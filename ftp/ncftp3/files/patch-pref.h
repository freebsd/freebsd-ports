--- ncftp/pref.h.orig	Sun Apr 15 19:36:00 2001
+++ ncftp/pref.h	Tue May  8 13:42:15 2001
@@ -16,10 +16,10 @@
 #	define kFirstFileName				"init_v3.txt"
 #else
 #	define kFirewallPrefFileName			"firewall"
-#	define kGlobalFirewallPrefFileName		"/etc/ncftp.firewall"
-#	define kGlobalFixedFirewallPrefFileName		"/etc/ncftp.firewall.fixed"
-#	define kGlobalPrefFileName			"/etc/ncftp.prefs_v3"
-#	define kGlobalFixedPrefFileName			"/etc/ncftp.prefs_v3.fixed"
+#	define kGlobalFirewallPrefFileName		SYSCONFDIR "/ncftp.firewall"
+#	define kGlobalFixedFirewallPrefFileName		SYSCONFDIR "/ncftp.firewall.fixed"
+#	define kGlobalPrefFileName			SYSCONFDIR "/ncftp.prefs_v3"
+#	define kGlobalFixedPrefFileName			SYSCONFDIR "/ncftp.prefs_v3.fixed"
 #	define kPrefFileName				"prefs_v3"
 #	define kPrefFileNameV2				"prefs"
 #	define kFirstFileName				"init_v3"
