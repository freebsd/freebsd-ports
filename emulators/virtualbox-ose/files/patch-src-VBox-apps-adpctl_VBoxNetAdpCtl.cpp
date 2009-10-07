--- src/apps/adpctl/VBoxNetAdpCtl.cpp.r22902	2009-04-10 14:03:59.000000000 +0200
+++ src/apps/adpctl/VBoxNetAdpCtl.cpp	2009-09-16 14:07:11.000000000 +0200
@@ -1,4 +1,4 @@
-/* $Id: VBoxNetAdpCtl.cpp 18864 2009-04-10 12:03:59Z vboxsync $ */
+/* $Id: VBoxNetAdpCtl.cpp 23064 2009-09-16 12:07:11Z vboxsync $ */
 /** @file
  * Apps - VBoxAdpCtl, Configuration tool for vboxnetX adapters.
  */
@@ -24,7 +24,6 @@
 /*******************************************************************************
 *   Header Files                                                               *
 *******************************************************************************/
-#include <assert.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
@@ -36,11 +35,12 @@
 # include <sys/ioccom.h>
 #endif
 
-/* @todo Error codes must be moved to some header file */
-#define ADPCTLERR_NO_CTL_DEV 3
-#define ADPCTLERR_IOCTL_FAILED 4
+/** @todo Error codes must be moved to some header file */
+#define ADPCTLERR_BAD_NAME         2
+#define ADPCTLERR_NO_CTL_DEV       3
+#define ADPCTLERR_IOCTL_FAILED     4
 
-/* @todo These are duplicates from src/VBox/HostDrivers/VBoxNetAdp/VBoxNetAdpInternal.h */
+/** @todo These are duplicates from src/VBox/HostDrivers/VBoxNetAdp/VBoxNetAdpInternal.h */
 #define VBOXNETADP_CTL_DEV_NAME    "/dev/vboxnetctl"
 #define VBOXNETADP_NAME            "vboxnet"
 #define VBOXNETADP_MAX_NAME_LEN    32
@@ -85,6 +85,7 @@
         pcszArg5, /* [network mask] */
         NULL  /* terminator */
     };
+    char * const envp[] = { (char*)"LC_ALL=C", NULL };
     int rc = EXIT_SUCCESS;
     pid_t childPid = fork();
     switch (childPid)
@@ -94,7 +95,7 @@
             rc = EXIT_FAILURE;
             break;
         case 0: /* Child process. */
-            if (execv(VBOXADPCTL_IFCONFIG_PATH, (char * const*)argv) == -1)
+            if (execve(VBOXADPCTL_IFCONFIG_PATH, (char * const*)argv, envp) == -1)
                 rc = EXIT_FAILURE;
             break;
         default: /* Parent process. */
@@ -108,15 +109,39 @@
 #define MAX_ADDRESSES 128
 #define MAX_ADDRLEN   64
 
-static bool removeAddresses(const char *pszAdapterName)
+static bool removeAddresses(char *pszAdapterName)
 {
-    char szCmd[1024], szBuf[1024];
+    char szBuf[1024];
     char aszAddresses[MAX_ADDRESSES][MAX_ADDRLEN];
+    int rc;
+    int fds[2];
+    char * const argv[] = { VBOXADPCTL_IFCONFIG_PATH, pszAdapterName, NULL };
+    char * const envp[] = { (char*)"LC_ALL=C", NULL };
 
     memset(aszAddresses, 0, sizeof(aszAddresses));
-    snprintf(szCmd, sizeof(szCmd), VBOXADPCTL_IFCONFIG_PATH " %s", pszAdapterName);
-    FILE *fp = popen(szCmd, "r");
 
+    rc = pipe(fds);
+    if (rc < 0)
+        return false;
+
+    pid_t pid = fork();
+    if (pid < 0)
+        return false;
+
+    if (pid == 0)
+    {
+        /* child */
+        close(fds[0]);
+        close(STDOUT_FILENO);
+        rc = dup2(fds[1], STDOUT_FILENO);
+        if (rc >= 0)
+            execve(VBOXADPCTL_IFCONFIG_PATH, argv, envp);
+        return false;
+    }
+
+    /* parent */
+    close(fds[1]);
+    FILE *fp = fdopen(fds[0], "r");
     if (!fp)
         return false;
 
@@ -124,9 +149,6 @@
     for (cAddrs = 0; cAddrs < MAX_ADDRESSES && fgets(szBuf, sizeof(szBuf), fp);)
     {
         int cbSkipWS = strspn(szBuf, " \t");
-#if 0 /* Don't use this! assert() breaks the mac build. Use IPRT or be a rectangular building thing. */
-        assert(cbSkipWS < 20);
-#endif
         char *pszWord = strtok(szBuf + cbSkipWS, " ");
         /* We are concerned with IPv6 address lines only. */
         if (!pszWord || strcmp(pszWord, "inet6"))
@@ -143,11 +165,12 @@
             continue;
         strncpy(aszAddresses[cAddrs++], pszWord, MAX_ADDRLEN-1);
     }
-    pclose(fp);
+    fclose(fp);
 
     for (int i = 0; i < cAddrs; i++)
     {
-        if (executeIfconfig(pszAdapterName, "inet6", VBOXADPCTL_DEL_CMD, aszAddresses[i]) != EXIT_SUCCESS)
+        if (executeIfconfig(pszAdapterName, "inet6",
+                            VBOXADPCTL_DEL_CMD, aszAddresses[i]) != EXIT_SUCCESS)
             return false;
     }
 
@@ -166,19 +189,41 @@
     int rc = ioctl(fd, uCmd, pData);
     if (rc == -1)
     {
-        perror("VBoxNetAdpCtl: ioctl failed for " VBOXNETADP_CTL_DEV_NAME); 
+        perror("VBoxNetAdpCtl: ioctl failed for " VBOXNETADP_CTL_DEV_NAME);
         rc = ADPCTLERR_IOCTL_FAILED;
     }
-    
+
     close(fd);
- 
+
     return rc;
 }
 
+int checkAdapterName(const char *pcszNameIn, char *pszNameOut)
+{
+    int iAdapterIndex = -1;
+
+    if (   strlen(pcszNameIn) >= VBOXNETADP_MAX_NAME_LEN
+        || sscanf(pcszNameIn, "vboxnet%d", &iAdapterIndex) != 1
+        || iAdapterIndex < 0 || iAdapterIndex > 99 )
+    {
+        fprintf(stderr, "Setting configuration for %s is not supported.\n", pcszNameIn);
+        return ADPCTLERR_BAD_NAME;
+    }
+    sprintf(pszNameOut, "vboxnet%d", iAdapterIndex);
+    if (strcmp(pszNameOut, pcszNameIn))
+    {
+        fprintf(stderr, "Invalid adapter name %s.\n", pcszNameIn);
+        return ADPCTLERR_BAD_NAME;
+    }
+
+    return 0;
+}
+
 int main(int argc, char *argv[])
 
 {
-    const char *pszAdapterName;
+    char szAdapterName[VBOXNETADP_MAX_NAME_LEN];
+    char *pszAdapterName;
     const char *pszAddress;
     const char *pszNetworkMask = NULL;
     const char *pszOption = NULL;
@@ -216,13 +261,18 @@
             pszAddress = argv[2];
             if (strcmp("remove", pszAddress) == 0)
             {
-                strncpy(Req.szName, pszAdapterName, sizeof(Req.szName));
+                rc = checkAdapterName(pszAdapterName, szAdapterName);
+                if (rc)
+                    return rc;
+                memset(&Req, '\0', sizeof(Req));
+                snprintf(Req.szName, sizeof(Req.szName), "%s", szAdapterName);
                 return doIOCtl(VBOXNETADP_CTL_REMOVE, &Req);
             }
             break;
         case 2:
             if (strcmp("add", argv[1]) == 0)
             {
+                memset(&Req, '\0', sizeof(Req));
                 rc = doIOCtl(VBOXNETADP_CTL_ADD, &Req);
                 if (rc == 0)
                     puts(Req.szName);
@@ -237,11 +287,11 @@
             return 1;
     }
 
-    if (strncmp("vboxnet", pszAdapterName, 7))
-    {
-        fprintf(stderr, "Setting configuration for %s is not supported.\n", pszAdapterName);
-        return 2;
-    }
+    rc = checkAdapterName(pszAdapterName, szAdapterName);
+    if (rc)
+        return rc;
+
+    pszAdapterName = szAdapterName;
 
     if (fRemove)
     {
@@ -276,3 +326,4 @@
     }
     return rc;
 }
+
