--- src/VBox/Main/ConsoleImpl2.cpp.orig	2009-12-15 14:48:58.000000000 +0900
+++ src/VBox/Main/ConsoleImpl2.cpp	2009-12-15 14:48:42.000000000 +0900
@@ -86,6 +86,7 @@
 # include <sys/ioctl.h>
 # include <sys/socket.h>
 # include <net/if.h>
+# include <net80211/ieee80211_ioctl.h>
 #endif
 
 #if defined(RT_OS_WINDOWS) && defined(VBOX_WITH_NETFLT)
@@ -1605,6 +1605,15 @@
                 break;
             }
 #endif
+#ifdef RT_OS_FREEBSD
+# ifdef VBOX_WITH_PULSE
+            case AudioDriverType_Pulse:
+            {
+                rc = CFGMR3InsertString(pCfg, "AudioDriver", "pulse");              RC_CHECK();
+                break;
+            }
+# endif
+#endif
 #ifdef RT_OS_DARWIN
             case AudioDriverType_CoreAudio:
             {
@@ -2394,6 +2394,42 @@ DECLCALLBACK(int) Console::configConstru
             /* we're not releasing the INetCfg stuff here since we use it later to figure out whether it is wireless */
 
 # elif defined(RT_OS_LINUX) || defined(RT_OS_FREEBSD)
+#  if defined(RT_OS_FREEBSD)
+            /*
+             * If we bridge to a tap interface open it the `old' direct way.
+             * This works and performs better than bridging a physical
+             * interface via the current FreeBSD vboxnetflt implementation.
+             */
+            if (!strncmp(pszHifName, "tap", sizeof "tap" - 1)) {
+                hrc = pThis->attachToTapInterface(aNetworkAdapter);
+                if (FAILED(hrc))
+                {
+                    switch (hrc)
+                    {
+                        case VERR_ACCESS_DENIED:
+                            return VMSetError(pVM, VERR_HOSTIF_INIT_FAILED, RT_SRC_POS,  N_(
+                                             "Failed to open '/dev/%s' for read/write access.  Please check the "
+                                             "permissions of that node, and that the net.link.tap.user_open "
+                                             "sysctl is set.  Either run 'chmod 0666 /dev/%s' or "
+                                             "change the group of that node to vboxusers and make yourself "
+                                             "a member of that group.  Make sure that these changes are permanent."), pszHifName, pszHifName);
+                        default:
+                            AssertMsgFailed(("Could not attach to tap interface! Bad!\n"));
+                            return VMSetError(pVM, VERR_HOSTIF_INIT_FAILED, RT_SRC_POS, N_(
+                                             "Failed to initialize Host Interface Networking"));
+                    }
+                }
+
+                Assert ((int)pThis->maTapFD[uInstance] >= 0);
+                if ((int)pThis->maTapFD[uInstance] >= 0)
+                {
+                    rc = CFGMR3InsertString(pLunL0, "Driver", "HostInterface");                 RC_CHECK();
+                    rc = CFGMR3InsertNode(pLunL0, "Config", &pCfg);                             RC_CHECK();
+                    rc = CFGMR3InsertInteger(pCfg, "FileHandle", pThis->maTapFD[uInstance]);    RC_CHECK();
+                }
+                break;
+            }
+#  endif
             /** @todo Check for malformed names. */
             const char *pszTrunk = pszHifName;
 
@@ -2495,6 +2496,33 @@ DECLCALLBACK(int) Console::configConstru
             }
             else
                 Log(("Failed to open wireless socket\n"));
+# elif defined(RT_OS_FREEBSD)
+            int iSock = socket(AF_INET, SOCK_DGRAM, 0);
+            if (iSock >= 0)
+            {
+                struct ieee80211req ireq;
+                uint8_t data[32];
+
+                (void) memset(&ireq, 0, sizeof(ireq));
+                (void) strncpy(ireq.i_name, pszHifName, sizeof(ireq.i_name));
+                ireq.i_type = IEEE80211_IOC_SSID;
+                ireq.i_val = -1;
+                ireq.i_data = data;
+                ireq.i_len = sizeof(data);
+
+                bool fSharedMacOnWire = ioctl(iSock, SIOCG80211, &ireq) >= 0;
+                close(iSock);
+                if (fSharedMacOnWire)
+                {
+                    rc = CFGMR3InsertInteger(pCfg, "SharedMacOnWire", true);
+                    RC_CHECK();
+                    Log(("Set SharedMacOnWire\n"));
+                }
+                else
+                    Log(("Failed to get wireless name\n"));
+            }
+            else
+                Log(("Failed to open wireless socket\n"));
 # elif defined(RT_OS_WINDOWS)
 #  define DEVNAME_PREFIX L"\\\\.\\"
             /* we are getting the medium type via IOCTL_NDIS_QUERY_GLOBAL_STATS Io Control
