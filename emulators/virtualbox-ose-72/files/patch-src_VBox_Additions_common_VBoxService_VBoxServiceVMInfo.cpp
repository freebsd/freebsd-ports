--- src/VBox/Additions/common/VBoxService/VBoxServiceVMInfo.cpp.orig	2026-01-27 12:48:12 UTC
+++ src/VBox/Additions/common/VBoxService/VBoxServiceVMInfo.cpp
@@ -116,8 +116,8 @@
 # include <net/if.h>
 # include <pwd.h> /* getpwuid */
 # include <unistd.h>
-# if !defined(RT_OS_OS2) && !defined(RT_OS_FREEBSD) && !defined(RT_OS_HAIKU)
-#  include <utmpx.h> /** @todo FreeBSD 9 should have this. */
+# if !defined(RT_OS_OS2) && !defined(RT_OS_HAIKU)
+#  include <utmpx.h>
 # endif
 # ifdef RT_OS_OS2
 #  include <net/if_dl.h>
@@ -795,7 +795,7 @@ void VGSvcVMInfoAddUserToList(PVBOXSERVICEVMINFOUSERLI
 }
 
 
-#if !defined(RT_OS_WINDOWS) && !defined(RT_OS_OS2) && !defined(RT_OS_HAIKU) && !defined(RT_OS_FREEBSD)
+#if !defined(RT_OS_WINDOWS) && !defined(RT_OS_OS2) && !defined(RT_OS_HAIKU)
 /**
  * Worker for vgsvcVMInfoWriteUsers that uses the utmpx.h interface to gather
  * users that are logged in.
@@ -806,7 +806,7 @@ static void vgsvcVMInfoAddUsersFromUTmpX(PVBOXSERVICEV
     utmpx *ut_user;
     while ((ut_user = getutxent()) != NULL)
     {
-# ifdef RT_OS_DARWIN /* No ut_user->ut_session on Darwin */
+# if defined(RT_OS_DARWIN) || defined(RT_OS_FREEBSD) /* No ut_user->ut_session on Darwin/FreeBSD */
         VGSvcVerbose(4, "Found entry '%s' (type: %d, PID: %RU32)\n", ut_user->ut_user, ut_user->ut_type, ut_user->ut_pid);
 # else
         VGSvcVerbose(4, "Found entry '%s' (type: %d, PID: %RU32, session: %RU32)\n",
@@ -822,7 +822,7 @@ static void vgsvcVMInfoAddUsersFromUTmpX(PVBOXSERVICEV
 }
 #endif
 
-#if defined(VBOX_WITH_DBUS) && defined(RT_OS_LINUX) /* Not yet for Solaris or FreeBSD. */
+#if defined(VBOX_WITH_DBUS) && (defined(RT_OS_LINUX) || defined(RT_OS_FREEBSD)) /* Not yet for Solaris. */
 
 /** @name Simple wrappers to work around compiler-specific va_list madness.
  * @{
@@ -1274,12 +1274,6 @@ static int vgsvcVMInfoWriteUsers(void)
        doesn't technically need them). */
     int rc = VGSvcVMInfoWinQueryUserListAndUpdateInfo(&UserGatherer, &g_VMInfoPropCache);
 
-#elif defined(RT_OS_FREEBSD)
-    /** @todo FreeBSD: Port logged on user info retrieval.
-     *                 However, FreeBSD 9 supports utmpx, so we could use the code
-     *                 block below (?). */
-    int rc = VERR_NOT_IMPLEMENTED;
-
 #elif defined(RT_OS_HAIKU)
     /** @todo Haiku: Port logged on user info retrieval. */
     int rc = VERR_NOT_IMPLEMENTED;
@@ -1294,12 +1288,12 @@ static int vgsvcVMInfoWriteUsers(void)
     /* Gather using setutxent & getutxent to source the utmp file. */
     vgsvcVMInfoAddUsersFromUTmpX(&UserGatherer);
 
-# if defined(VBOX_WITH_DBUS) && defined(RT_OS_LINUX) /* Not yet for Solaris/FreeBSD. */
+# if defined(VBOX_WITH_DBUS) && (defined(RT_OS_LINUX) || defined(RT_OS_FREEBSD)) /* Not yet for Solaris. */
     /* Gather using various DBus interface. */
     vgsvcVMInfoDBusAddToUserList(&UserGatherer);
 # endif
 
-#endif /* !RT_OS_WINDOWS && !RT_OS_FREEBSD && !RT_OS_HAIKU && !RT_OS_OS2 */
+#endif /* !RT_OS_WINDOWS && !RT_OS_HAIKU && !RT_OS_OS2 */
 
     if (RT_SUCCESS(rc))
         g_cVMInfoLoggedInUsers = UserGatherer.cUsersInList;
@@ -1583,7 +1577,7 @@ static int vgsvcVMInfoWriteNetwork(void)
             RTStrPrintf(szPropPath, sizeof(szPropPath), "/VirtualBox/GuestInfo/Net/%RU32/Name", cIfsReported);
             int rc2 = RTStrValidateEncoding(pIfCurr->ifa_name);
             if (RT_SUCCESS(rc2))
-                VGSvcPropCacheUpdate(&g_VMInfoPropCache, szPropPath, "%s", pIfCurr->ifa_name);
+                VGSvcPropCacheUpdateF(&g_VMInfoPropCache, szPropPath, "%s", pIfCurr->ifa_name);
             else
                 VGSvcPropCacheUpdate(&g_VMInfoPropCache, szPropPath, NULL);
 # endif
