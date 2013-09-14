$NetBSD: patch-src_proto.h,v 1.1 2012/11/16 00:35:28 joerg Exp $

--- src/proto.h.orig	2012-11-15 10:30:20.000000000 +0000
+++ src/proto.h
@@ -271,7 +271,7 @@ int getsock(int);
 void killsock(int);
 void killtclsock(int);
 int answer(int, char *, unsigned long *, unsigned short *, int);
-inline int open_listen(int *);
+int open_listen(int *);
 int open_address_listen(IP addr, int *);
 int open_telnet(char *, int);
 int open_telnet_dcc(int, char *, char *);
