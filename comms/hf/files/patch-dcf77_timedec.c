--- dcf77/timedec.c.orig	Sun Jul 30 12:07:54 2006
+++ dcf77/timedec.c	Sun Jul 30 12:10:01 2006
@@ -136,7 +136,12 @@
 		vlprintf(1, "mktime failed\n");
 		goto error;
 	}
+/* XXX FreeBSD takes care of timezone internally, I don't know about others. 
+ * -db (VA3DB)
+ */
+#ifdef __linux__
 	t -= timezone;
+#endif
 /*	t -= tz == ZONE_MESZ ? 7200 : 3600; */
 /* bug? isn't summer time later than winter time ? */
 	t -= tz == ZONE_MESZ ? 3600 : 7200 ; 
