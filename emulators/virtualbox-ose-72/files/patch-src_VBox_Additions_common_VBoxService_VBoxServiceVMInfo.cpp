--- src/VBox/Additions/common/VBoxService/VBoxServiceVMInfo.cpp.orig	2021-01-07 15:34:20 UTC
+++ src/VBox/Additions/common/VBoxService/VBoxServiceVMInfo.cpp
@@ -67,8 +67,8 @@
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
@@ -528,7 +528,7 @@ static void vgsvcVMInfoWriteFixedProperties(void)
 }
 
 
-#if defined(VBOX_WITH_DBUS) && defined(RT_OS_LINUX) /* Not yet for Solaris/FreeBSB. */
+#if defined(VBOX_WITH_DBUS) && (defined(RT_OS_LINUX) || defined(RT_OS_FREEBSD)) /* Not yet for Solaris. */
 /*
  * Simple wrapper to work around compiler-specific va_list madness.
  */
@@ -555,12 +555,6 @@ static int vgsvcVMInfoWriteUsers(void)
 #ifdef RT_OS_WINDOWS
     rc = VGSvcVMInfoWinWriteUsers(&g_VMInfoPropCache, &pszUserList, &cUsersInList);
 
-#elif defined(RT_OS_FREEBSD)
-    /** @todo FreeBSD: Port logged on user info retrieval.
-     *                 However, FreeBSD 9 supports utmpx, so we could use the code
-     *                 block below (?). */
-    rc = VERR_NOT_IMPLEMENTED;
-
 #elif defined(RT_OS_HAIKU)
     /** @todo Haiku: Port logged on user info retrieval. */
     rc = VERR_NOT_IMPLEMENTED;
@@ -586,7 +580,7 @@ static int vgsvcVMInfoWriteUsers(void)
     while (   (ut_user = getutxent())
            && RT_SUCCESS(rc))
     {
-# ifdef RT_OS_DARWIN /* No ut_user->ut_session on Darwin */
+# if defined(RT_OS_DARWIN) || defined(RT_OS_FREEBSD) /* No ut_user->ut_session on Darwin/FreeBSD */
         VGSvcVerbose(4, "Found entry '%s' (type: %d, PID: %RU32)\n", ut_user->ut_user, ut_user->ut_type, ut_user->ut_pid);
 # else
         VGSvcVerbose(4, "Found entry '%s' (type: %d, PID: %RU32, session: %RU32)\n",
@@ -621,7 +615,7 @@ static int vgsvcVMInfoWriteUsers(void)
     }
 
 # ifdef VBOX_WITH_DBUS
-#  if defined(RT_OS_LINUX) /* Not yet for Solaris/FreeBSB. */
+#  if defined(RT_OS_LINUX) || defined(RT_OS_FREEBSD) /* Not yet for Solaris. */
     DBusError dbErr;
     DBusConnection *pConnection = NULL;
     int rc2 = RTDBusLoadLib();
@@ -830,7 +824,7 @@ static int vgsvcVMInfoWriteUsers(void)
     if (   fHaveLibDbus
         && dbus_error_is_set(&dbErr))
         dbus_error_free(&dbErr);
-#  endif /* RT_OS_LINUX */
+#  endif /* RT_OS_LINUX || RT_OS_FREEBSD */
 # endif /* VBOX_WITH_DBUS */
 
     /** @todo Fedora/others: Handle systemd-loginctl. */
@@ -867,7 +861,7 @@ static int vgsvcVMInfoWriteUsers(void)
     RTMemFree(papszUsers);
 
     endutxent(); /* Close utmpx file. */
-#endif /* !RT_OS_WINDOWS && !RT_OS_FREEBSD && !RT_OS_HAIKU && !RT_OS_OS2 */
+#endif /* !RT_OS_WINDOWS && !RT_OS_HAIKU && !RT_OS_OS2 */
 
     Assert(RT_FAILURE(rc) || cUsersInList == 0 || (pszUserList && *pszUserList));
 
