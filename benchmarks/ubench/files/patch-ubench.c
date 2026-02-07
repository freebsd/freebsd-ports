--- ubench.c.orig	2000-05-29 03:07:21 UTC
+++ ubench.c
@@ -37,11 +37,11 @@ extern char *_sys_errlist[];
 #define sys_errlist _sys_errlist
 #endif
 
-int	cpubench();
-int	membench();
+int	cpubench(int);
+int	membench(int);
 #ifdef  DISKNETYES
-int	diskbench();
-int	netbench();
+int	diskbench(int);
+int	netbench(int);
 #endif
 void	signalSetup();
 
@@ -66,10 +66,10 @@ void print_usage()
 {
 #ifdef DISKNETYES
   fprintf(stderr,
-  "Usage: ubench [-cmhs] [-d [raw_device]] [-n [interface]]\n");
+  "Usage: ubench [-cmhs] [-d [raw_device]] [-n [interface]] [-t testtime]\n");
 #else
   fprintf(stderr,
-  "Usage: ubench [-cmhs]\n");
+  "Usage: ubench [-cmhs] [-t testtime]\n");
 #endif
 }
 /*****************************************************************************/
@@ -81,6 +81,7 @@ char *argc[];
   int s			=	1;
   int k			=	1;
   int i			=	1;
+  int timeout = 180;
   
   while ( argc[i] )
     if ( argc[i][0]=='-' )
@@ -112,6 +113,17 @@ prgs: switch ( argc[i][s] )
 	    s++;
 	    ONEflag=1;
 	    goto prgs;
+	  case 't':
+	    if (!argc[i][++s]) {
+		if (!argc[++i]) {
+		    print_usage();
+		    exit(1);
+		}
+		s = 0;
+	    }
+	    timeout = atoi(argc[i] + s);
+	    s += strlen(argc[i] + s);
+	    goto prgs;
           default:
 	    print_version();
 	    print_usage();
@@ -156,11 +168,11 @@ prgs: switch ( argc[i][s] )
 #endif
     }
   i=0;
-  if ( CPUflag ) i+=cpubench();
-  if ( MEMflag ) i+=membench();
+  if ( CPUflag ) i+=cpubench(timeout);
+  if ( MEMflag ) i+=membench(timeout);
 #ifdef DISKNETYES
-  if ( DISKflag ) i+=diskbench();
-  if ( NETflag ) i+=netbench();
+  if ( DISKflag ) i+=diskbench(timeout);
+  if ( NETflag ) i+=netbench(timeout);
   if ( CPUflag&MEMflag&DISKflag&NETflag )
     {
       if ( ONEflag )
