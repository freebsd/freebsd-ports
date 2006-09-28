diff -ruN mdnsd.c.orig mdnsd.c
--- mdnsd.c.orig	Tue Feb 18 08:54:46 2003
+++ mdnsd.c	Mon Sep 25 22:11:17 2006
@@ -1,5 +1,7 @@
 #include "mdnsd.h"
+#include <arpa/inet.h>
 #include <string.h>
+#include <stdlib.h>
 
 // size of query/publish hashes
 #define SPRIME 108
@@ -198,7 +200,7 @@
     struct cached *cur = 0;
     q->nexttry = 0;
     q->tries = 0;
-    while(cur = _c_next(d,cur,q->name,q->type))
+    while( (cur = _c_next(d,cur,q->name,q->type)) )
         if(q->nexttry == 0 || cur->rr.ttl - 7 < q->nexttry) q->nexttry = cur->rr.ttl - 7;
     if(q->nexttry != 0 && q->nexttry < d->checkqlist) d->checkqlist = q->nexttry;
 }
@@ -208,7 +210,7 @@
     struct cached *c = 0;
     struct query *cur;
     int i = _namehash(q->name) % LPRIME;
-    while(c = _c_next(d,c,q->name,q->type)) c->q = 0;
+    while( (c = _c_next(d,c,q->name,q->type)) ) c->q = 0;
     if(d->qlist == q) d->qlist = q->list;
     else {
         for(cur=d->qlist;cur->list != q;cur = cur->list);
@@ -288,13 +290,13 @@
 
     if(r->class == 32768 + d->class)
     { // cache flush
-        while(c = _c_next(d,c,r->name,r->type)) c->rr.ttl = 0;
+        while( (c = _c_next(d,c,r->name,r->type)) ) c->rr.ttl = 0;
         _c_expire(d,&d->cache[i]);
     }
     
     if(r->ttl == 0)
     { // process deletes
-        while(c = _c_next(d,c,r->name,r->type))
+        while( (c = _c_next(d,c,r->name,r->type)) )
             if(_a_match(r,&c->rr))
             {
                 c->rr.ttl = 0;
@@ -330,7 +332,7 @@
     }
     c->next = d->cache[i];
     d->cache[i] = c;
-    if(c->q = _q_next(d, 0, r->name, r->type))
+    if( (c->q = _q_next(d, 0, r->name, r->type)) )
         _q_answer(d,c);
 }
 
@@ -344,7 +346,11 @@
 
 int _r_out(mdnsd d, struct message *m, mdnsdr *list)
 { // copy a published record into an outgoing message
-    mdnsdr r, next;
+    /*
+     * Unused
+     * mdnsdr next;
+     */
+    mdnsdr r;
     int ret = 0;
     while((r = *list) != 0 && message_packet_len(m) + _rr_len(&r->rr) < d->frame)
     {
@@ -363,7 +369,10 @@
 
 mdnsd mdnsd_new(int class, int frame)
 {
-    int i;
+    /*
+    * Unused
+    * int i;
+    */
     mdnsd d;
     d = (mdnsd)malloc(sizeof(struct mdnsd_struct));
     bzero(d,sizeof(struct mdnsd_struct));
@@ -401,7 +410,10 @@
 
 void mdnsd_free(mdnsd d)
 {
-    int i;
+    /*
+     * Unused
+     * int i;
+     */
     // loop through all hashes, free everything
     // free answers if any
     free(d);
@@ -611,8 +623,11 @@
 
 struct timeval *mdnsd_sleep(mdnsd d)
 {
+    /*
+     * Unused
+     * mdnsdr r;
+     */
     int sec, usec;
-    mdnsdr r;
     d->sleep.tv_sec = d->sleep.tv_usec = 0;
     #define RET while(d->sleep.tv_usec > 1000000) {d->sleep.tv_sec++;d->sleep.tv_usec -= 1000000;} return &d->sleep;
 
@@ -665,7 +680,7 @@
         q->next = d->queries[i];
         q->list = d->qlist;
         d->qlist = d->queries[i] = q;
-        while(cur = _c_next(d,cur,q->name,q->type))
+        while( (cur = _c_next(d,cur,q->name,q->type)) )
             cur->q = q; // any cached entries should be associated
         _q_reset(d,q);
         q->nexttry = d->checkqlist = d->now.tv_sec; // new questin, immediately send out
