--- src/key_event.c.orig	Mon Aug 16 08:40:30 2004
+++ src/key_event.c	Thu Oct 14 00:51:11 2004
@@ -140,6 +140,7 @@
     
     int i;
     int index;
+    UTFCHAR buf;
 
     IMKeyEventStruct *k = (IMKeyEventStruct *) keylist->keylist;
     MyDataPerSession *session_data = (MyDataPerSession *) s->specific_data;
@@ -289,7 +290,7 @@
 
         /* lock candidate if numbers are not keyname */
         /* XXX fix in v.2 on not only checking '1' */
-        UTFCHAR buf = (UTFCHAR)UTF8toUnicode((wchar_t)session_data->cf->header.keyname[key2code('1')].wch);
+        buf = (UTFCHAR)UTF8toUnicode((wchar_t)session_data->cf->header.keyname[key2code('1')].wch);
         if (!buf)
         {
             session_data->luc_commit = True;
