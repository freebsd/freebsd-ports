--- src/outpacket.c.orig	2024-12-20 21:57:21 UTC
+++ src/outpacket.c
@@ -23,7 +23,7 @@ void end_opt6(int container)
 
 void end_opt6(int container)
 {
-   void *p = daemon->outpacket.iov_base + container + 2;
+   uint8_t *p = (uint8_t *)daemon->outpacket.iov_base + container + 2;
    u16 len = outpacket_counter - container - 4 ;
    
    PUTSHORT(len, p);
@@ -50,11 +50,11 @@ void *expand(size_t headroom)
 
 void *expand(size_t headroom)
 {
-  void *ret;
+  uint8_t *ret;
 
   if (expand_buf(&daemon->outpacket, outpacket_counter + headroom))
     {
-      ret = daemon->outpacket.iov_base + outpacket_counter;
+      ret = (uint8_t *)daemon->outpacket.iov_base + outpacket_counter;
       outpacket_counter += headroom;
       return ret;
     }
@@ -65,7 +65,7 @@ int new_opt6(int opt)
 int new_opt6(int opt)
 {
   int ret = outpacket_counter;
-  void *p;
+  unsigned char *p;
 
   if ((p = expand(4)))
     {
@@ -88,7 +88,7 @@ void put_opt6_long(unsigned int val)
   
 void put_opt6_long(unsigned int val)
 {
-  void *p;
+  unsigned char *p;
   
   if ((p = expand(4)))  
     PUTLONG(val, p);
@@ -96,7 +96,7 @@ void put_opt6_short(unsigned int val)
 
 void put_opt6_short(unsigned int val)
 {
-  void *p;
+  uint8_t *p;
 
   if ((p = expand(2)))
     PUTSHORT(val, p);   
