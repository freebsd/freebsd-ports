Index: libical/src/libical/icaltime.c
===================================================================
RCS file: /home/kde/kdepim/libical/src/libical/icaltime.c,v
retrieving revision 1.5
retrieving revision 1.6
diff -u -3 -p -r1.5 -r1.6
--- libical/src/libical/icaltime.c	2001/06/26 12:22:20	1.5
+++ libical/src/libical/icaltime.c	2002/09/27 18:49:07	1.6
@@ -3,7 +3,7 @@
   FILE: icaltime.c
   CREATOR: eric 02 June 2000
   
-  $Id: icaltime.c,v 1.5 2001/06/26 12:22:20 cschumac Exp $
+  $Id: icaltime.c,v 1.6 2002/09/27 18:49:07 adridg Exp $
   $Locker:  $
     
  (C) COPYRIGHT 2000, Eric Busboom, http://www.softwarestudio.org
@@ -141,7 +141,11 @@ void unset_tz(struct set_tz_save savetz)
 
 	free(orig_tzid);
     } else {
+#ifdef __FreeBSD__
+	unsetenv("TZ");
+#else
 	putenv("TZ"); /* Delete from environment */
+#endif
     } 
 
     if(savetz.new_env_str != 0){
