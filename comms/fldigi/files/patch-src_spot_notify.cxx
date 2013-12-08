--- src/spot/notify.cxx.orig	2013-11-18 18:41:28.965212678 -0500
+++ src/spot/notify.cxx	2013-11-18 19:17:17.004165081 -0500
@@ -33,7 +33,10 @@
 #include <cctype>
 #include <cstdlib>
 
-#if (__GNUC__ > 4) || (__GNUC__ == 4 && __GNUC_MINOR__ >= 1)
+#if __clang__
+#  define MAP_TYPE std::unordered_map
+#  include <unordered_map>
+#elif (__GNUC__ > 4) || (__GNUC__ == 4 && __GNUC_MINOR__ >= 1)
 #  define MAP_TYPE std::tr1::unordered_map
 #  include <tr1/unordered_map>
 #else
@@ -339,7 +342,7 @@
 void notify_rsid(trx_mode mode, int afreq)
 {
 	const char* mode_name = mode_info[mode].name;
-	regmatch_t sub[2] = { { 0, strlen(mode_name) } };
+	regmatch_t sub[2] = { { 0, static_cast<regoff_t>(strlen(mode_name)) } };
 	sub[1] = sub[0];
 	for (notify_list_t::iterator i = notify_list.begin(); i != notify_list.end(); ++i)
 		if (i->event == NOTIFY_EVENT_RSID)
@@ -1253,7 +1256,7 @@
 
 	if (notify_tmp.event == NOTIFY_EVENT_RSID) {
 		notify_tmp.mode = active_modem->get_mode();
-		regmatch_t sub[2] = { { 0, strlen(mode_info[notify_tmp.mode].name) } };
+		regmatch_t sub[2] = { { 0, static_cast<regoff_t>(strlen(mode_info[notify_tmp.mode].name)) } };
 		sub[1] = sub[0];
 		notify_recv(notify_tmp.mode, active_modem->get_freq(),
 			    mode_info[notify_tmp.mode].name, sub, 2, &notify_tmp);
