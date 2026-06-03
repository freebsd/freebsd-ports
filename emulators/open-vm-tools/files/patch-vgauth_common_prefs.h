--- vgauth/common/prefs.h.orig	2025-06-19 04:05:18 UTC
+++ vgauth/common/prefs.h
@@ -65,7 +65,7 @@ void Pref_LogAllEntries(const PrefHandle ph);
 // fallback value if registry isn't set
 #define VGAUTH_PREF_CONFIG_FILENAME "c:\\Program Files\\VMware\\VMware Tools\\vgauth.conf"
 #else
-#define VGAUTH_PREF_CONFIG_FILENAME "/etc/vmware-tools/vgauth.conf"
+#define VGAUTH_PREF_CONFIG_FILENAME "%%PREFIX%%/etc/vmware-tools/vgauth.conf"
 // XXX temp til installer tweaks its location
 #define VGAUTH_PREF_CONFIG_FILENAME_OLD "/etc/vmware/vgauth.conf"
 #endif
@@ -102,7 +102,7 @@ ticketTTL=3600
 auditSuccessEvents=true
 
 [localization]
-msgCatalog = /etc/vmware-tools/vgauth/messages
+msgCatalog = %%PREFIX%%/etc/vmware-tools/vgauth/messages
 # EOF
  @endverbatim
  * See http://developer.gnome.org/glib/2.28/glib-Key-value-file-parser.html#glib-Key-value-file-parser.description
