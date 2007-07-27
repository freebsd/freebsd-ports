--- src/query.cc.orig	2005-04-30 09:51:29.000000000 -0400
+++ src/query.cc	2007-07-26 20:47:03.000000000 -0400
@@ -197,7 +197,7 @@
     {
       string s((*i).first);
       int str_len = (*i).first.length();
-      if((unsigned)p + str_len + 3 *sizeof(int)  < (unsigned)p_end )
+      if(p + str_len + 3 *sizeof(int)  < p_end )
       {
         *p++ = (char) str_len;
 	const char* q_type_name = s.c_str();
@@ -216,7 +216,7 @@
 	die(0, "report buffer overflow -- too many query types");
     }
   
-  len = (unsigned)p - (unsigned)buf;
+  len = p - buf;
   *(buf) = num_recs;
 
   if(write(fd, buf, len) != len)
