===================================================================
RCS file: /home2/webcvs/mirror/valgrind/memcheck/mc_include.h,v
retrieving revision 1.16
retrieving revision 1.16.2.1
diff -u -p -r1.16 -r1.16.2.1
--- memcheck/mc_include.h	2003/07/24 08:45:32	1.16
+++ memcheck/mc_include.h	2004/02/29 15:53:40	1.16.2.1
@@ -121,16 +121,16 @@ extern void MC_(helper_value_check0_fail
 
 
 /* Functions defined in mc_main.c */
-extern void MC_(helperc_STOREV4) ( Addr, UInt );
-extern void MC_(helperc_STOREV2) ( Addr, UInt );
-extern void MC_(helperc_STOREV1) ( Addr, UInt );
+extern __attribute__ ((regparm(2))) void MC_(helperc_STOREV4) ( Addr, UInt );
+extern __attribute__ ((regparm(2))) void MC_(helperc_STOREV2) ( Addr, UInt );
+extern __attribute__ ((regparm(2))) void MC_(helperc_STOREV1) ( Addr, UInt );
    
-extern UInt MC_(helperc_LOADV1) ( Addr );
-extern UInt MC_(helperc_LOADV2) ( Addr );
-extern UInt MC_(helperc_LOADV4) ( Addr );
+extern __attribute__ ((regparm(1))) UInt MC_(helperc_LOADV1) ( Addr );
+extern __attribute__ ((regparm(1))) UInt MC_(helperc_LOADV2) ( Addr );
+extern __attribute__ ((regparm(1))) UInt MC_(helperc_LOADV4) ( Addr );
 
-extern void MC_(fpu_write_check) ( Addr addr, Int size );
-extern void MC_(fpu_read_check)  ( Addr addr, Int size );
+extern __attribute__ ((regparm(2))) void MC_(fpu_write_check) ( Addr addr, Int size );
+extern __attribute__ ((regparm(2))) void MC_(fpu_read_check)  ( Addr addr, Int size );
 
 
 /* For client requests */
