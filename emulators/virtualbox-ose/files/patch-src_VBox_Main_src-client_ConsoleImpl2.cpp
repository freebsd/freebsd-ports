--- src/VBox/Main/src-client/ConsoleImpl2.cpp.orig	2017-10-18 07:12:56 UTC
+++ src/VBox/Main/src-client/ConsoleImpl2.cpp
@@ -5206,7 +5206,7 @@ int Console::i_configNetwork(const char *pszDevice,
                 {
                     switch (hrc)
                     {
-                        case VERR_ACCESS_DENIED:
+                        case (HRESULT)VERR_ACCESS_DENIED:
                             return VMSetError(VMR3GetVM(mpUVM), VERR_HOSTIF_INIT_FAILED, RT_SRC_POS,  N_(
                                             "Failed to open '/dev/net/tun' for read/write access. Please check the "
                                             "permissions of that node. Either run 'chmod 0666 /dev/net/tun' or "
@@ -5408,7 +5408,7 @@ int Console::i_configNetwork(const char *pszDevice,
                     {
                         switch (hrc)
                         {
-                            case VERR_ACCESS_DENIED:
+                            case (HRESULT)VERR_ACCESS_DENIED:
                                 return VMSetError(VMR3GetVM(mpUVM), VERR_HOSTIF_INIT_FAILED, RT_SRC_POS,  N_(
                                                 "Failed to open '/dev/%s' for read/write access.  Please check the "
                                                 "permissions of that node, and that the net.link.tap.user_open "
