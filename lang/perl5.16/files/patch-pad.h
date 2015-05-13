--- pad.h.orig	2013-03-04 15:16:22 UTC
+++ pad.h
@@ -140,14 +140,14 @@ typedef enum {
 #  define ASSERT_CURPAD_LEGAL(label) \
     pad_peg(label); \
     if (PL_comppad ? (AvARRAY(PL_comppad) != PL_curpad) : (PL_curpad != 0))  \
-	Perl_croak(aTHX_ "panic: illegal pad in %s: 0x%"UVxf"[0x%"UVxf"]",\
+	Perl_croak(aTHX_ "panic: illegal pad in %s: 0x%" UVxf "[0x%" UVxf "]",\
 	    label, PTR2UV(PL_comppad), PTR2UV(PL_curpad));
 
 
 #  define ASSERT_CURPAD_ACTIVE(label) \
     pad_peg(label); \
     if (!PL_comppad || (AvARRAY(PL_comppad) != PL_curpad))		  \
-	Perl_croak(aTHX_ "panic: invalid pad in %s: 0x%"UVxf"[0x%"UVxf"]",\
+	Perl_croak(aTHX_ "panic: invalid pad in %s: 0x%" UVxf "[0x%" UVxf "]",\
 	    label, PTR2UV(PL_comppad), PTR2UV(PL_curpad));
 #else
 #  define ASSERT_CURPAD_LEGAL(label)
@@ -233,7 +233,7 @@ Restore the old pad saved into the local
 	PL_comppad = (PAD*) (AvARRAY(padlist)[nth]);		\
 	PL_curpad = AvARRAY(PL_comppad);			\
 	DEBUG_Xv(PerlIO_printf(Perl_debug_log,			\
-	      "Pad 0x%"UVxf"[0x%"UVxf"] set_cur    depth=%d\n",	\
+	      "Pad 0x%" UVxf "[0x%" UVxf "] set_cur    depth=%d\n",	\
 	      PTR2UV(PL_comppad), PTR2UV(PL_curpad), (int)(nth)));
 
 
@@ -251,7 +251,7 @@ Restore the old pad saved into the local
 	PL_comppad = (npad);					\
 	PL_curpad =  PL_comppad ? AvARRAY(PL_comppad) : NULL;	\
 	DEBUG_Xv(PerlIO_printf(Perl_debug_log,			\
-	      "Pad 0x%"UVxf"[0x%"UVxf"] save_local\n",		\
+	      "Pad 0x%" UVxf "[0x%" UVxf "] save_local\n",		\
 	      PTR2UV(PL_comppad), PTR2UV(PL_curpad)));
 
 #define PAD_RESTORE_LOCAL(opad) \
@@ -259,7 +259,7 @@ Restore the old pad saved into the local
 	PL_comppad = opad;						\
 	PL_curpad =  PL_comppad ? AvARRAY(PL_comppad) : NULL;	\
 	DEBUG_Xv(PerlIO_printf(Perl_debug_log,			\
-	      "Pad 0x%"UVxf"[0x%"UVxf"] restore_local\n",	\
+	      "Pad 0x%" UVxf "[0x%" UVxf "] restore_local\n",	\
 	      PTR2UV(PL_comppad), PTR2UV(PL_curpad)));
 
 
