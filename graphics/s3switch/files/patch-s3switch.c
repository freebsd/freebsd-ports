--- s3switch.c.orig	Wed Sep 11 23:25:33 2002
+++ s3switch.c	Sun Mar 16 03:15:54 2003
@@ -1,7 +1,37 @@
 // Simple utility to switch a Savage board between CRT/LCD devices.
 // T. N. Roberts, 99-Aug-26.
 
-// Linux x86 only.
+// Ported to FreeBSD/i386 by Bruce M Simpson <bms@spc.org>
+
+#if defined(__FreeBSD__)
+
+#include <sys/types.h>
+#include <machine/cpufunc.h>
+#include <machine/sysarch.h>
+#include <machine/vm86.h>
+#include <stdlib.h>
+#include <stdio.h>
+
+#define OUTB(val,port) outb(port,val)
+#define INB(port) inb(port)
+#define IOPERM(x,y,z) i386_set_ioperm(x,y,z)
+
+typedef struct vm86_intcall_args INTCALL_ARGS_T;
+#define EAX vmf.eax.r_ex
+#define EBX vmf.ebx.r_ex
+#define ECX vmf.ecx.r_ex
+#define EDX vmf.edx.r_ex
+
+#define INTCALL_INIT()
+
+static __inline
+INTCALL(int intnum, INTCALL_ARGS_T *args)
+{
+	args->intnum = intnum;
+	return(!i386_vm86(VM86_INTCALL, args));
+}
+
+#else /* Linux */
 
 #include <stdio.h>
 #define extern
@@ -10,6 +40,30 @@
 
 #include "lrmi.h"
 
+#define OUTB(val,port) outb(val,port)
+#define INB(port) inb(port)
+#define IOPERM(x,y,z) ioperm(x,y,z)
+
+typedef struct LRMI_regs INTCALL_ARGS_T;
+#define EAX eax
+#define EBX ebx
+#define ECX ecx
+#define EDX edx
+
+#define INTCALL_INIT()			\
+	do {				\
+		if (!LRMI_init())	\
+			return (1);	\
+	} while (0)
+
+static __inline
+INTCALL(int intnum, INTCALL_ARGS_T *args)
+{
+	return(LRMI_int(intnum, args));
+}
+
+#endif /* Linux */
+
 // Usage:
 //  s3switch [-q] [crt|lcd|both]
 
@@ -97,10 +151,10 @@
 {
     /* Allow or disallow access to I/O ports. */
 
-    ioperm( 0x40, 4, enable );
-    ioperm( 0x61, 1, enable );
-    ioperm( 0x80, 1, enable );
-    ioperm( 0x3b0, 0x30, enable );
+    IOPERM( 0x40, 4, enable );
+    IOPERM( 0x61, 1, enable );
+    IOPERM( 0x80, 1, enable );
+    IOPERM( 0x3b0, 0x30, enable );
 }
 
 
@@ -109,10 +163,10 @@
 {
     // Figure out what kind of Savage it is.
 
-    outb( 0x2d, 0x3d4 );
-    gPCIid = inb( 0x3d5 ) << 8;
-    outb( 0x2e, 0x3d4 );
-    gPCIid |= inb( 0x3d5 );
+    OUTB( 0x2d, 0x3d4 );
+    gPCIid = INB( 0x3d5 ) << 8;
+    OUTB( 0x2e, 0x3d4 );
+    gPCIid |= INB( 0x3d5 );
 
     switch( gPCIid ) {
 	case PCI_CHIP_SAVAGE3D:
@@ -157,21 +211,21 @@
 
     if( ChipClass == S3_SAVAGEMXIX ) 
     {
-	outb( 0xc0, 0x3d4 );
-	jTvFormat = inb( 0x3d5 );
-	outb( 0x6b, 0x3d4 );
-	jDevices = inb( 0x3d5 );
+	OUTB( 0xc0, 0x3d4 );
+	jTvFormat = INB( 0x3d5 );
+	OUTB( 0x6b, 0x3d4 );
+	jDevices = INB( 0x3d5 );
     }
     else 
     {
-	outb( 0x6b, 0x3d4 );
-	jTvFormat = inb( 0x3d5 );
-	outb( 0x6d, 0x3d4 );
-	jDevices = inb( 0x3d5 );
+	OUTB( 0x6b, 0x3d4 );
+	jTvFormat = INB( 0x3d5 );
+	OUTB( 0x6d, 0x3d4 );
+	jDevices = INB( 0x3d5 );
     }
 
-    outb( 0x79, 0x3d4 );
-    cr79 = inb( 0x3d5 );
+    OUTB( 0x79, 0x3d4 );
+    cr79 = INB( 0x3d5 );
 
     //printf( "Device ID: %04x\n", gPCIid);
 
@@ -207,24 +261,23 @@
 unsigned short
 set_active_device( int iDevice )
 {
-    struct LRMI_regs r;
+    INTCALL_ARGS_T sa;
     int iResult = 0;
 
-    if (!LRMI_init())
-	return 1;
+    INTCALL_INIT();
 
     /* Go set the active device. */
 
-    memset( &r, 0, sizeof(r) );
+    memset(&sa, 0, sizeof(sa));
 
-    r.eax = 0x4f14;	// S3 extended functions
-    r.ebx = 0x0003;	// set active device
-    r.ecx = iDevice;
+    sa.EAX = 0x4F14;
+    sa.EBX = 0x0003;
+    sa.ECX = iDevice;
 
     if( ChipClass == S3_SAVAGEMXIX )
-	r.ecx |= DUO_ON;
+	sa.ECX |= DUO_ON;
 
-    iResult = LRMI_int( 0x10, &r );
+    iResult = INTCALL(0x10, &sa);
 
     if( !iResult )
     {
@@ -232,7 +285,7 @@
 	return 1;
     }
 
-    if ( (r.eax & 0xffff) != 0x4f )
+    if ( (sa.EAX & 0xffff) != 0x4f )
     {
 	fprintf( stderr, "BIOS returned error code.\n" );
 	return 1;
@@ -246,22 +299,21 @@
 unsigned short
 set_tv_state( int state )
 {
-    struct LRMI_regs r;
+    INTCALL_ARGS_T sa;
     int iResult = 0;
 
-    if (!LRMI_init())
-	return 1;
+    INTCALL_INIT();
 
     /* And go set the TV state. */
 
-    memset( &r, 0, sizeof(r) );
+    memset(&sa, 0, sizeof(sa));
 
-    r.eax = 0x4f14;	// S3 extended functions
-    r.ebx = 0x0007;	// set tv state
-    r.ecx = state;
-    r.edx = TV_FORMAT_MASK;
+    sa.EAX = 0x4F14;
+    sa.EBX = 0x0007;
+    sa.ECX = state;
+    sa.EDX = TV_FORMAT_MASK;
 
-    iResult = LRMI_int( 0x10, &r );
+    iResult = INTCALL(0x10, &sa);
 
     if( !iResult )
     {
@@ -269,7 +321,7 @@
 	return 1;
     }
 
-    if ( (r.eax & 0xffff) != 0x4f )
+    if ( (sa.EAX & 0xffff) != 0x4f )
     {
 	fprintf( stderr, "BIOS returned error code.\n" );
 	return 1;
@@ -348,9 +400,9 @@
 	    if( (cr79 == 5) || (cr79 == 8) )
 	    {
 		cr79 = (cr79 == 5) ? 8 : 0x0e;
-		ioperm( 0x3d4, 2, 1 );
+		IOPERM( 0x3d4, 2, 1 );
 		outw( (cr79 << 8) | 0x79, 0x3d4 );
-		ioperm( 0x3d4, 2, 0 );
+		IOPERM( 0x3d4, 2, 0 );
 	    }
 	}
 	else if( !(jDevices & LCD_ACTIVE) && (newstate & LCD_ACTIVE) )
@@ -360,9 +412,9 @@
 	    if( (cr79 == 8) || (cr79 == 0xe) )
 	    {
 		cr79 = (cr79 == 8) ? 5 : 8;
-		ioperm( 0x3d4, 2, 1 );
+		IOPERM( 0x3d4, 2, 1 );
 		outw( (cr79 << 8) | 0x79, 0x3d4 );
-		ioperm( 0x3d4, 2, 0 );
+		IOPERM( 0x3d4, 2, 0 );
 	    }
 	}
     }
