--- lib/hostip.c.orig	Mon Jun 24 17:05:50 2002
+++ lib/hostip.c	Mon Jun 24 17:05:54 2002
@@ -360,7 +360,7 @@
  *
  * Keith McGuigan 
  * 10/3/2001 */
-static struct hostent* pack_hostent(char** buf, struct hostent* orig)
+static struct hostent* pack_hostent(char** buf, struct hostent* orig, int pass)
 {
   char* bufptr;
   struct hostent* copy;
@@ -427,8 +427,9 @@
   }
   copy->h_addr_list[i] = NULL;
 
-  *buf=(char *)realloc(*buf, (int)bufptr-(int)(*buf));
-  return copy;
+  if (pass == 0)
+    *buf=(char *)realloc(*buf, (int)bufptr-(int)(*buf));
+  return *buf;
 }
 #endif
 
@@ -623,7 +624,8 @@
       /* we make a copy of the hostent right now, right here, as the
          static one we got a pointer to might get removed when we don't
          want/expect that */
-      h = pack_hostent(&buf, h);
+      pack_hostent(&buf, h, 0);
+      h = pack_hostent(&buf, h, 1);
       *bufp=(char *)buf;
     }
 #endif
