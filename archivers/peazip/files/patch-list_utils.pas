--- list_utils.pas.orig	2016-01-27 13:31:39.038239000 -0500
+++ list_utils.pas	2016-01-27 13:32:00.045976000 -0500
@@ -969,7 +969,7 @@
   //name of the dir
   ): integer;
 var
-  s: utf8string;
+  s: string;
   i, j: integer;
   dirarr: array of utf8string;
 begin
