--- query.c.orig	2018-01-16 11:49:56.341179000 -0800
+++ query.c	2018-01-16 11:50:06.432700000 -0800
@@ -203,7 +203,7 @@
 
 
   NEWNAME:
-  if (++z->loop == 100) goto DIE;
+  if (++z->loop == 500) goto DIE;
   d = z->name[z->level];
   dtype = z->level ? DNS_T_A : z->type;
   dlen = dns_domain_length(d);
@@ -449,7 +449,7 @@
 
 
   HAVEPACKET:
-  if (++z->loop == 100) goto DIE;
+  if (++z->loop == 500) goto DIE;
   buf = z->dt.packet;
   len = z->dt.packetlen;
 
