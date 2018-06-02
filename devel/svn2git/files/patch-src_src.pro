--- src/src.pro.orig	2018-06-02 10:56:17 UTC
+++ src/src.pro
@@ -14,7 +14,7 @@ VERSTR = '\\"$${VERSION}\\"'  # place qu
 DEFINES += VER=\"$${VERSTR}\" # create a VER macro containing the version string
 
 TEMPLATE = app
-TARGET = ../svn-all-fast-export
+TARGET = ../svn2git
 
 isEmpty(PREFIX) {
     PREFIX = /usr/local
