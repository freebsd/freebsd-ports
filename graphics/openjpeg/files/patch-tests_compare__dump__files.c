--- tests/compare_dump_files.c.orig	2016-09-14 00:05:13 UTC
+++ tests/compare_dump_files.c
@@ -118,10 +118,10 @@ int main(int argc, char **argv)
   test_cmp_parameters inParam;
   FILE *fbase=NULL, *ftest=NULL;
   int same = 0;
-  char lbase[256];
-  char strbase[256];
-  char ltest[256];
-  char strtest[256];
+  char lbase[512];
+  char strbase[512];
+  char ltest[512];
+  char strtest[512];
 
   if( parse_cmdline_cmp(argc, argv, &inParam) == 1 )
     {
@@ -154,9 +154,9 @@ int main(int argc, char **argv)
 
   while (fgets(lbase, sizeof(lbase), fbase) && fgets(ltest,sizeof(ltest),ftest))
     {
-    int nbase = sscanf(lbase, "%255[^\r\n]", strbase);
-    int ntest = sscanf(ltest, "%255[^\r\n]", strtest);
-    assert( nbase != 255 && ntest != 255 );
+    int nbase = sscanf(lbase, "%511[^\r\n]", strbase);
+    int ntest = sscanf(ltest, "%511[^\r\n]", strtest);
+    assert( nbase != 511 && ntest != 511 );
     if( nbase != 1 || ntest != 1 )
       {
       fprintf(stderr, "could not parse line from files\n" );
