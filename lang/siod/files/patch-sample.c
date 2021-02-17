--- sample.c	2014-03-25 04:10:42.000000000 -0400
+++ sample.c	2021-02-15 23:14:05.303485000 -0500
@@ -33,13 +33,13 @@
 	NIL);}
 
-LISP my_one;
-LISP my_two;
-LISP my_99;
-LISP my_0;
+static LISP my_one;
+static LISP my_two;
+static LISP my_99;
+static LISP my_0;
 
-LISP cfib(LISP x);
-LISP clooptest(LISP x,LISP f);
+static LISP cfib(LISP x);
+static LISP clooptest(LISP x,LISP f);
 
-static char *standard_fib = "\
+static const char *standard_fib = "\
                              \
 (define (fib x)              \
@@ -49,7 +49,8 @@
        (fib (- x 2)))))      ";
 
-int main(int argc,char **argv)
+int main(int argc, const char **argv)
 {int j,xflag = 0,retval = 0;
  char *linebuffer = NULL,*ptr,*iobuff;
+ const char *ex;
  print_welcome();
 #ifdef THINK_C
@@ -63,5 +64,5 @@
    else if (strncmp(argv[j],"-e",2) == 0)
      {xflag = 2;
-      linebuffer = &argv[j][2];}
+      ex = &argv[j][2];}
  process_cla(argc,argv,(xflag) ? 0 : 1);
  print_hs_1();
@@ -81,5 +82,5 @@
  init_subr_1("cfib",cfib);
  init_subr_2("cloop-test",clooptest);
- repl_c_string(standard_fib,0,0,0);
+ repl_c_string01(standard_fib, 0, 0, 0);
  switch(xflag)
    {case 0:
@@ -88,17 +89,17 @@
     case 1:
       printf("Using repl_c_string\n");
-      linebuffer = (char *) malloc(256);
+      linebuffer = malloc(256);
       while(fgets(linebuffer,256,stdin))
 	{if ((ptr = strchr(linebuffer,'\n'))) *ptr = 0;
-	 retval = repl_c_string(linebuffer,1,xflag,0);
+	 retval = repl_c_string01(linebuffer, 1, xflag, 0);
 	 xflag = 0;}
       break;
     case 2:
-      retval = repl_c_string(linebuffer,1,xflag,1);
+      retval = repl_c_string01(ex, 1, xflag, 1);
       break;
    case 3:
      printf("Using repl_c_string I/O case\n");
-      linebuffer = (char *) malloc(256);
-      iobuff = (char *) malloc(1024);
+      linebuffer = malloc(256);
+      iobuff = malloc(1024);
       while(fgets(linebuffer,256,stdin))
 	{if ((ptr = strchr(linebuffer,'\n'))) *ptr = 0;
