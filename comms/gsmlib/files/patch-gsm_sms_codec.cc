--- gsmlib/gsm_sms_codec.cc.orig	Tue Oct 29 02:33:19 2002
+++ gsmlib/gsm_sms_codec.cc	Tue Oct 29 02:33:36 2002
@@ -110,6 +110,8 @@
   t.tm_isdst = -1;
   t.tm_yday = 0;
   t.tm_wday = 0;
+
+#define BROKEN_STRFTIME
   
 #ifdef BROKEN_STRFTIME
   char formattedTime[1024];
