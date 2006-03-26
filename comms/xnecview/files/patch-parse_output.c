--- parse_output.c.orig	Fri Mar 17 20:32:22 2006
+++ parse_output.c	Fri Mar 17 20:30:42 2006
@@ -749,9 +749,9 @@
       EXPAND_IF_NECESSARY(numneco,maxfreqs,neco)
    
       /* search for the frequency and read it */
-      do fgets(s,200,f);  while (!feof(f) && !strstr(s,"FREQUENCY="));
+      do fgets(s,200,f);  while (!feof(f) && !strstr(s,"FREQUENCY : "));
       if (feof(f)) break;
-      p = strchr(s,'=');
+      p = strchr(s,':');
       freq = atof(p+1);
 
       /* find the right place in the neco array (data is sorted by frequency) */
