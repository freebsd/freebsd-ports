Index: loader/main.c
===================================================================
RCS file: /home/wine/wine/loader/main.c,v
retrieving revision 1.90
retrieving revision 1.89
diff -u -3 -p -r1.90 -r1.89
--- loader/main.c	20 Jan 2004 00:28:01 -0000	1.90
+++ loader/main.c	22 Nov 2003 00:08:26 -0000	1.89
@@ -29,7 +29,7 @@ int main( int argc, char *argv[] )
 {
     char error[1024];

-#if 0
+#ifdef __i386__
     static char pe_load[256*1024*1024] __attribute__((aligned(4096)));
     wine_set_pe_load_area( pe_load, sizeof(pe_load) );
 #endif
