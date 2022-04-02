--- config_h.SH.orig	2020-12-18 10:04:35 UTC
+++ config_h.SH
@@ -858,7 +858,7 @@ sed <<!GROK!THIS! >$CONFIG_H -e 's!^#undef\(.*/\)\*!/\
 
 /* BYTEORDER:
  *	This symbol holds the hexadecimal constant defined in byteorder,
- *	in a UV, i.e. 0x1234 or 0x4321 or 0x12345678, etc...
+ *	in a UVINT, i.e. 0x1234 or 0x4321 or 0x12345678, etc...
  *	If the compiler supports cross-compiling or multiple-architecture
  *	binaries, use compiler-defined macros to
  *	determine the byte order.
@@ -1210,6 +1210,13 @@ sed <<!GROK!THIS! >$CONFIG_H -e 's!^#undef\(.*/\)\*!/\
  */
 #define PTRSIZE $ptrsize		/**/
 
+/* PTRADDRSIZE:
+ *	This symbol contains the size of an address, so that the C preprocessor
+ *	can make decisions based on it.  It will be sizeof(ptraddr_t) if the
+ *	compiler supports ptraddr_t; otherwise it will be sizeof(void *).
+ */
+#define PTRADDRSIZE $ptraddrsize	/**/
+
 /* Drand01:
  *	This macro is to be used to generate uniformly distributed
  *	random numbers over the range [0., 1.[.  You may have to supply
@@ -3988,6 +3995,12 @@ sed <<!GROK!THIS! >$CONFIG_H -e 's!^#undef\(.*/\)\*!/\
 /* UVTYPE:
  *	This symbol defines the C type used for Perl's UV.
  */
+/* IVINTTYPE:
+ *	This symbol defines the C type used for Perl's IVINT.
+ */
+/* UVINTTYPE:
+ *	This symbol defines the C type used for Perl's UVINT.
+ */
 /* I8TYPE:
  *	This symbol defines the C type used for Perl's I8.
  */
@@ -4073,6 +4086,8 @@ sed <<!GROK!THIS! >$CONFIG_H -e 's!^#undef\(.*/\)\*!/\
  */
 #define	IVTYPE		$ivtype		/**/
 #define	UVTYPE		$uvtype		/**/
+#define	IVINTTYPE	$ivinttype	/**/
+#define	UVINTTYPE	$uvinttype	/**/
 #define	I8TYPE		$i8type		/**/
 #define	U8TYPE		$u8type		/**/
 #define	I16TYPE		$i16type	/**/
@@ -4086,6 +4101,7 @@ sed <<!GROK!THIS! >$CONFIG_H -e 's!^#undef\(.*/\)\*!/\
 #define	NVTYPE		$nvtype		/**/
 #define	IVSIZE		$ivsize		/**/
 #define	UVSIZE		$uvsize		/**/
+#define	UVINTSIZE	$uvintsize	/**/
 #define	I8SIZE		$i8size		/**/
 #define	U8SIZE		$u8size		/**/
 #define	I16SIZE		$i16size	/**/
@@ -4097,11 +4113,11 @@ sed <<!GROK!THIS! >$CONFIG_H -e 's!^#undef\(.*/\)\*!/\
 #define	U64SIZE		$u64size	/**/
 #endif
 #define	NVSIZE		$nvsize		/**/
-#$d_nv_preserves_uv	NV_PRESERVES_UV
+#$d_nv_preserves_uv		NV_PRESERVES_UV
 #define	NV_PRESERVES_UV_BITS	$nv_preserves_uv_bits
 #define	NV_OVERFLOWS_INTEGERS_AT	($nv_overflows_integers_at)
 #$d_nv_zero_is_allbits_zero	NV_ZERO_IS_ALLBITS_ZERO
-#if UVSIZE == 8
+#if UVINTSIZE == 8
 #   ifdef BYTEORDER
 #       if BYTEORDER == 0x1234
 #           undef BYTEORDER
