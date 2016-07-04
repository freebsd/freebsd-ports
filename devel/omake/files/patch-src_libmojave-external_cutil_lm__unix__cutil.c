$NetBSD: patch-ap,v 1.1 2010/12/17 09:40:14 wiz Exp $

From upstream SVN.

--- src/libmojave-external/cutil/lm_unix_cutil.c.orig	2007-07-18 17:42:32.000000000 +0000
+++ src/libmojave-external/cutil/lm_unix_cutil.c
@@ -87,9 +87,9 @@ value home_win32(value v_unit)
     TCHAR path[MAX_PATH];
 
     if(SUCCEEDED(CompatSHGetFolderPath(NULL, CSIDL_LOCAL_APPDATA | CSIDL_FLAG_CREATE, NULL, 0, path)))
-        CAMLreturn(copy_string(path));
+        CAMLreturn(caml_copy_string(path));
 
-    failwith("home_win32");
+    caml_failwith("home_win32");
     return Val_unit;
 }
 
@@ -138,7 +138,7 @@ value lockf_win32(value v_fd, value v_ki
             flags = LOCKFILE_FAIL_IMMEDIATELY;
             break;
         default:
-            invalid_argument("lockf_win32");
+            caml_invalid_argument("lockf_win32");
             break;
         }
 
@@ -147,11 +147,11 @@ value lockf_win32(value v_fd, value v_ki
         overlapped.Offset = pos;
 
         /* Perform the lock */
-        enter_blocking_section();
+        caml_enter_blocking_section();
         code = LockFileEx(fd, flags, 0, len, 0, &overlapped);
         if(code == 0)
             error = GetLastError();
-        leave_blocking_section();
+        caml_leave_blocking_section();
 
         /* Fail if the lock was not successful */
         if(code == 0) {
@@ -165,14 +165,14 @@ value lockf_win32(value v_fd, value v_ki
                  * XXX: HACK: this exception is being caught
                  *            Do not change the string w/o changing the wrapper code.
                  */
-                failwith("lockf_win32: already locked");
+                caml_failwith("lockf_win32: already locked");
                 break;
             case ERROR_POSSIBLE_DEADLOCK:
                 /*
                  * XXX: HACK: this exception is being caught
                  *            Do not change the string w/o changing the wrapper code.
                  */
-                failwith("lockf_win32: possible deadlock");
+                caml_failwith("lockf_win32: possible deadlock");
                 break;
             default:
                 FormatMessage(
@@ -187,7 +187,7 @@ value lockf_win32(value v_fd, value v_ki
                 sprintf(szBuf, "lockf_win32 failed with error %d: %s", error, lpMsgBuf); 
                 LocalFree(lpMsgBuf);
 
-                failwith(szBuf);
+                caml_failwith(szBuf);
                 break;
             }
         }
@@ -289,7 +289,7 @@ value caml_registry_find(value v_hkey, v
 #endif
 
     /* Got the value */
-    return copy_string(buffer);
+    return caml_copy_string(buffer);
 }
 
 #else /* WIN32 */
@@ -381,9 +381,9 @@ value lm_flock(value v_fd, value v_op)
     op = Int_val(v_op);
 #if defined(FLOCK_ENABLED)
     cmd = flock_of_flock[op];
-    enter_blocking_section();
+    caml_enter_blocking_section();
     code = flock(fd, cmd);
-    leave_blocking_section();
+    caml_leave_blocking_section();
 #elif defined(FCNTL_ENABLED)
     {
         struct flock info;
@@ -392,9 +392,9 @@ value lm_flock(value v_fd, value v_op)
         info.l_whence = SEEK_SET;
         info.l_start = 0;
         info.l_len = FLOCK_LEN;
-        enter_blocking_section();
+        caml_enter_blocking_section();
         code = fcntl(fd, cmd, &info);
-        leave_blocking_section();
+        caml_leave_blocking_section();
     }
 #elif defined(LOCKF_ENABLED)
     cmd = lockf_of_flock[op];
@@ -457,12 +457,12 @@ value lm_getpwents(value v_unit)
         Store_field(entry, 2, Val_int(entryp->pw_uid));
         Store_field(entry, 3, Val_int(entryp->pw_gid));
 #ifdef __BEOS__
-        Store_field(entry, 4, copy_string(""));
+        Store_field(entry, 4, caml_copy_string(""));
 #else
-        Store_field(entry, 4, copy_string(entryp->pw_gecos));
+        Store_field(entry, 4, caml_copy_string(entryp->pw_gecos));
 #endif
-        Store_field(entry, 5, copy_string(entryp->pw_dir));
-        Store_field(entry, 6, copy_string(entryp->pw_shell));
+        Store_field(entry, 5, caml_copy_string(entryp->pw_dir));
+        Store_field(entry, 6, caml_copy_string(entryp->pw_shell));
         cons = caml_alloc_tuple(2);
         Store_field(cons, 0, entry);
         Store_field(cons, 1, users);
