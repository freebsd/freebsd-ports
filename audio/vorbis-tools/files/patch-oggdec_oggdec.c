
$FreeBSD$

--- oggdec/oggdec.c.orig	Mon Sep 23 13:20:52 2002
+++ oggdec/oggdec.c	Mon Sep 23 13:21:04 2002
@@ -99,6 +99,7 @@
                 break;
             case 'o':
                 outfilename = strdup(optarg);
+                break;
             case 'R':
                 raw = atoi(optarg);
                 break;
