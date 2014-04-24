From nox Mon Sep 17 00:00:00 2001
From: Juergen Lock <nox@jelal.kn-bremen.de>
Date: 22 Mar 2014 00:21:00 +0100
Subject: Fix bsd-user targets running scripts with shebang args

This fixes running scripts starting like:

	#! /usr/bin/perl -w

Signed-off-by: Juergen Lock <nox@jelal.kn-bremen.de>

--- a/bsd-user/freebsd/os-proc.c
--- b/bsd-user/freebsd/os-proc.c
@@ -83,7 +83,7 @@ out:
 }
 
 static int
-is_target_shell_script(int fd, char *interp, size_t size)
+is_target_shell_script(int fd, char *interp, size_t size, char **interp_args)
 {
     char buf[2], *p, *b;
     ssize_t n;
@@ -120,7 +120,21 @@ is_target_shell_script(int fd, char *int
             return 0;
         }
         if ((p = memchr(b, '\n', size)) != NULL) {
+            int hasargs = 0;
             *p = 0;
+
+            *interp_args = NULL;
+            p = interp;
+            while (*p) {
+                if ((*p == ' ') || (*p == '\t')) {
+                    hasargs = 1;
+                    *p = 0;
+                } else if (hasargs) {
+                    *interp_args = p;
+                    break;
+                }
+                ++p;
+            }
             return 1;
         }
         b += n;
@@ -136,7 +150,7 @@ is_target_shell_script(int fd, char *int
 abi_long freebsd_exec_common(abi_ulong path_or_fd, abi_ulong guest_argp,
         abi_ulong guest_envp, int do_fexec)
 {
-    char **argp, **envp, **qargp, **qarg1, **qarg0;
+    char **argp, **envp, **qargp, **qarg1, **qarg0, **qargend;
     int argc, envc;
     abi_ulong gp;
     abi_ulong addr;
@@ -166,7 +180,7 @@ abi_long freebsd_exec_common(abi_ulong p
         envc++;
     }
 
-    qarg0 = argp =  alloca((argc + 4) * sizeof(void *));
+    qarg0 = argp =  alloca((argc + 5) * sizeof(void *));
     /* save the first agrument for the emulator */
     *argp++ = (char *)getprogname();
     qargp = argp;
@@ -188,7 +202,8 @@ abi_long freebsd_exec_common(abi_ulong p
         }
         total_size += strlen(*q) + 1;
     }
-    *q = NULL;
+    *q++ = NULL;
+    qargend = q;
 
     for (gp = guest_envp, q = envp; gp; gp += sizeof(abi_ulong), q++) {
         if (get_user_ual(addr, gp)) {
@@ -217,7 +232,7 @@ abi_long freebsd_exec_common(abi_ulong p
     }
 
     if (do_fexec) {
-        char execpath[PATH_MAX];
+        char execpath[PATH_MAX], *scriptargs;
 
         if (((int)path_or_fd > 0 &&
             is_target_elf_binary((int)path_or_fd)) == 1) {
@@ -238,7 +253,7 @@ abi_long freebsd_exec_common(abi_ulong p
                 goto execve_end;
             }
         } else if (is_target_shell_script((int)path_or_fd, execpath,
-                    sizeof(execpath)) != 0) {
+                    sizeof(execpath), &scriptargs) != 0) {
             char scriptpath[PATH_MAX];
 
             /* execve() as a target script using emulator. */
@@ -246,6 +261,10 @@ abi_long freebsd_exec_common(abi_ulong p
                         sizeof(scriptpath)) != NULL) {
                 *qargp = execpath;
                 *qarg1 = scriptpath;
+                if (scriptargs) {
+                    memmove(qarg1 + 1, qarg1, (qargend-qarg1) * sizeof(*qarg1));
+                    *qarg1 = scriptargs;
+                }
                 ret = get_errno(execve(qemu_proc_pathname, qarg0, envp));
             } else {
                 ret = -TARGET_EBADF;
@@ -256,7 +275,7 @@ abi_long freebsd_exec_common(abi_ulong p
         }
     } else {
         int fd;
-        char execpath[PATH_MAX];
+        char execpath[PATH_MAX], *scriptargs;
 
         p = lock_user_string(path_or_fd);
         if (p == NULL) {
@@ -275,11 +294,15 @@ abi_long freebsd_exec_common(abi_ulong p
             *qarg1 = (char *)p;
             ret = get_errno(execve(qemu_proc_pathname, qargp, envp));
         } else if (is_target_shell_script(fd, execpath,
-                    sizeof(execpath)) != 0) {
+                    sizeof(execpath), &scriptargs) != 0) {
             close(fd);
             /* execve() as a target script using emulator. */
             *qargp = execpath;
             *qarg1 = (char *)p;
+            if (scriptargs) {
+                memmove(qarg1 + 1, qarg1, (qargend-qarg1) * sizeof(*qarg1));
+                *qarg1 = scriptargs;
+            }
             ret = get_errno(execve(qemu_proc_pathname, qarg0, envp));
         } else {
             close(fd);
