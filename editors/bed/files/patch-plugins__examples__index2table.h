--- plugins/examples/index2table.h.orig	Thu May 23 16:28:24 2002
+++ plugins/examples/index2table.h	Tue Jan  2 00:15:22 2007
@@ -52,3 +52,5 @@
 		return sym;\
 		}\
 	char *nam##name= initfilter(#nam,&get##nam);
+
+typedef Filter * startindex2table_func_t(int fb,int sb,char *opts,ScreenPart *part=NULL);
