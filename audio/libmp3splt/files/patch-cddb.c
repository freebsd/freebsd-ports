--- src/cddb.c.orig
+++ src/cddb.c
@@ -393,6 +393,16 @@
       //we read the file line by line
       while (fgets(line, 2048, file_input)!=NULL)
       {
+        //if windows file with '\r', then pretend is a unix file
+        if (strlen(line) > 1)
+        {
+          if (line[strlen(line)-2] == '\r')
+          {
+            line[strlen(line)-2] = '\n';
+            line[strlen(line)-1] = '\0';
+          }
+        }
+
         type = SPLT_CUE_NOTHING;
 
         //we read strings from file TRACK,TITLE,AUDIO,PERFORMER,INDEX
