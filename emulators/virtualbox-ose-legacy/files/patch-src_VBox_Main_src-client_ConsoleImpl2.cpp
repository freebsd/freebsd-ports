--- src/VBox/Main/src-client/ConsoleImpl2.cpp.orig	2020-05-13 19:44:07 UTC
+++ src/VBox/Main/src-client/ConsoleImpl2.cpp
@@ -5265,7 +5265,7 @@ int Console::i_configNetwork(const char *pszDevice,
                 {
                     switch (hrc)
                     {
-                        case VERR_ACCESS_DENIED:
+                        case (HRESULT)VERR_ACCESS_DENIED:
                             return VMSetError(VMR3GetVM(mpUVM), VERR_HOSTIF_INIT_FAILED, RT_SRC_POS,  N_(
                                             "Failed to open '/dev/net/tun' for read/write access. Please check the "
                                             "permissions of that node. Either run 'chmod 0666 /dev/net/tun' or "
@@ -5467,7 +5467,7 @@ int Console::i_configNetwork(const char *pszDevice,
                     {
                         switch (hrc)
                         {
-                            case VERR_ACCESS_DENIED:
+                            case (HRESULT)VERR_ACCESS_DENIED:
                                 return VMSetError(VMR3GetVM(mpUVM), VERR_HOSTIF_INIT_FAILED, RT_SRC_POS,  N_(
                                                 "Failed to open '/dev/%s' for read/write access.  Please check the "
                                                 "permissions of that node, and that the net.link.tap.user_open "
