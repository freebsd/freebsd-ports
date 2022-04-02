--- sv.c.orig	2020-12-18 10:04:36 UTC
+++ sv.c
@@ -873,9 +873,9 @@ struct body_details {
 */
 
 struct body_details {
-    U8 body_size;	/* Size to allocate  */
-    U8 copy;		/* Size of structure to copy (may be shorter)  */
-    U8 offset;		/* Size of unalloced ghost fields to first alloced field*/
+    U16 body_size;	/* Size to allocate  */
+    U16 copy;		/* Size of structure to copy (may be shorter)  */
+    U16 offset;		/* Size of unalloced ghost fields to first alloced field*/
     PERL_BITFIELD8 type : 4;        /* We have space for a sanity check. */
     PERL_BITFIELD8 cant_upgrade : 1;/* Cannot upgrade this type */
     PERL_BITFIELD8 zero_nv : 1;     /* zero the NV when upgrading from this */
@@ -2057,7 +2057,7 @@ S_sv_2iuv_non_preserve(pTHX_ SV *const sv
     PERL_ARGS_ASSERT_SV_2IUV_NON_PRESERVE;
     PERL_UNUSED_CONTEXT;
 
-    DEBUG_c(PerlIO_printf(Perl_debug_log,"sv_2iuv_non '%s', IV=0x%" UVxf " NV=%" NVgf " inttype=%" UVXf "\n", SvPVX_const(sv), SvIVX(sv), SvNVX(sv), (UV)numtype));
+    DEBUG_c(PerlIO_printf(Perl_debug_log,"sv_2iuv_non '%s', IV=0x%" UVxf " NV=%" NVgf " inttype=%" UVXf "\n", SvPVX_const(sv), SvUVX(sv), SvNVX(sv), (UV)numtype));
     if (SvNVX(sv) < (NV)IV_MIN) {
 	(void)SvIOKp_on(sv);
 	(void)SvNOK_on(sv);
@@ -2222,7 +2222,7 @@ S_sv_2iuv_common(pTHX_ SV *const sv)
 				  "0x%" UVxf " 2iv(%" UVuf " => %" IVdf ") (as unsigned)\n",
 				  PTR2UV(sv),
 				  SvUVX(sv),
-				  SvUVX(sv)));
+				  SvIVX(sv)));
 	}
     }
     else if (SvPOKp(sv)) {
@@ -2886,22 +2886,22 @@ static const union {
     '9', '8', '9', '9'
 }};
 
-/* uiv_2buf(): private routine for use by sv_2pv_flags(): print an IV or
+/* uivint_2buf(): private routine for use by sv_2pv_flags(): print an IV or
  * UV as a string towards the end of buf, and return pointers to start and
  * end of it.
  *
- * We assume that buf is at least TYPE_CHARS(UV) long.
+ * We assume that buf is at least TYPE_CHARS(UVINT) long.
  */
 
 PERL_STATIC_INLINE char *
-S_uiv_2buf(char *const buf, const IV iv, UV uv, const int is_uv, char **const peob)
+S_uivint_2buf(char *const buf, const IVINT iv, UVINT uv, const int is_uv, char **const peob)
 {
-    char *ptr = buf + TYPE_CHARS(UV);
+    char *ptr = buf + TYPE_CHARS(UVINT);
     char * const ebuf = ptr;
     int sign;
     U16 *word_ptr, *word_table;
 
-    PERL_ARGS_ASSERT_UIV_2BUF;
+    PERL_ARGS_ASSERT_UIVINT_2BUF;
 
     /* ptr has to be properly aligned, because we will cast it to U16* */
     assert(PTR2nat(ptr) % 2 == 0);
@@ -3144,9 +3144,9 @@ Perl_sv_2pv_flags(pTHX_ SV *const sv, STRLEN *const lp
 	   converting the IV is going to be more efficient */
 	const U32 isUIOK = SvIsUV(sv);
         /* The purpose of this union is to ensure that arr is aligned on
-           a 2 byte boundary, because that is what uiv_2buf() requires */
+           a 2 byte boundary, because that is what uivint_2buf() requires */
         union {
-            char arr[TYPE_CHARS(UV)];
+            char arr[TYPE_CHARS(UVINT)];
             U16 dummy;
         } buf;
 	char *ebuf, *ptr;
@@ -3154,7 +3154,7 @@ Perl_sv_2pv_flags(pTHX_ SV *const sv, STRLEN *const lp
 
 	if (SvTYPE(sv) < SVt_PVIV)
 	    sv_upgrade(sv, SVt_PVIV);
-        ptr = uiv_2buf(buf.arr, SvIVX(sv), SvUVX(sv), isUIOK, &ebuf);
+        ptr = uivint_2buf(buf.arr, SvIVX(sv), SvUVX(sv), isUIOK, &ebuf);
 	len = ebuf - ptr;
 	/* inlined from sv_setpvn */
 	s = SvGROW_mutable(sv, len + 1);
@@ -9061,7 +9061,7 @@ Perl_sv_inc_nomg(pTHX_ SV *const sv)
 	       And if we do get here I suspect that sv_setnv will croak. NWC
 	       Fall through. */
 	    DEBUG_c(PerlIO_printf(Perl_debug_log,"sv_inc punt failed to convert '%s' to IOK or NOKp, UV=0x%" UVxf " NV=%" NVgf "\n",
-				  SvPVX_const(sv), SvIVX(sv), SvNVX(sv)));
+				  SvPVX_const(sv), SvUVX(sv), SvNVX(sv)));
 	}
 #endif /* PERL_PRESERVE_IVUV */
         if (!numtype && ckWARN(WARN_NUMERIC))
@@ -9239,7 +9239,7 @@ Perl_sv_dec_nomg(pTHX_ SV *const sv)
 	       And if we do get here I suspect that sv_setnv will croak. NWC
 	       Fall through. */
 	    DEBUG_c(PerlIO_printf(Perl_debug_log,"sv_dec punt failed to convert '%s' to IOK or NOKp, UV=0x%" UVxf " NV=%" NVgf "\n",
-				  SvPVX_const(sv), SvIVX(sv), SvNVX(sv)));
+				  SvPVX_const(sv), SvUVX(sv), SvNVX(sv)));
 	}
     }
 #endif /* PERL_PRESERVE_IVUV */
@@ -10721,7 +10721,7 @@ Perl_sv_tainted(pTHX_ SV *const sv)
     return FALSE;
 }
 
-#ifndef NO_MATHOMS  /* Can't move these to mathoms.c because call uiv_2buf(),
+#ifndef NO_MATHOMS  /* Can't move these to mathoms.c because call uivint_2buf(),
                        private to this file */
 
 /*
@@ -10737,13 +10737,13 @@ Perl_sv_setpviv(pTHX_ SV *const sv, const IV iv)
 Perl_sv_setpviv(pTHX_ SV *const sv, const IV iv)
 {
     /* The purpose of this union is to ensure that arr is aligned on
-       a 2 byte boundary, because that is what uiv_2buf() requires */
+       a 2 byte boundary, because that is what uivint_2buf() requires */
     union {
-        char arr[TYPE_CHARS(UV)];
+        char arr[TYPE_CHARS(UVINT)];
         U16 dummy;
     } buf;
     char *ebuf;
-    char * const ptr = uiv_2buf(buf.arr, iv, 0, 0, &ebuf);
+    char * const ptr = uivint_2buf(buf.arr, iv, 0, 0, &ebuf);
 
     PERL_ARGS_ASSERT_SV_SETPVIV;
 
@@ -12365,6 +12365,7 @@ Perl_sv_vcatpvfn_flags(pTHX_ SV *const sv, const char 
 	case 'z':
 	case 't':
         case 'j':
+	case 'P':
 	    intsize = *q++;
 	    break;
 	}
@@ -12688,6 +12689,7 @@ Perl_sv_vcatpvfn_flags(pTHX_ SV *const sv, const char 
 #endif
                         default:   iv = va_arg(*args, int);        break;
                         case 'j':  iv = (IV) va_arg(*args, PERL_INTMAX_T); break;
+                        case 'P':  iv = va_arg(*args, PERL_INTPTR_T); break;
                         case 'q':
 #if IVSIZE >= 8
                                    iv = va_arg(*args, Quad_t);     break;
@@ -12706,6 +12708,7 @@ Perl_sv_vcatpvfn_flags(pTHX_ SV *const sv, const char 
                         case 'l':  iv = (long)tiv;   break;
                         case 'V':
                         default:   iv = tiv;         break;
+                        case 'P':  iv = (PERL_INTPTR_T)tiv; break;
                         case 'q':
 #if IVSIZE >= 8
                                    iv = (Quad_t)tiv; break;
@@ -12745,6 +12748,7 @@ Perl_sv_vcatpvfn_flags(pTHX_ SV *const sv, const char 
 #endif
                         case 'j': uv = (UV) va_arg(*args, PERL_UINTMAX_T); break;
                         default:  uv = va_arg(*args, unsigned);      break;
+                        case 'P': uv = va_arg(*args, PERL_UINTPTR_T); break;
                         case 'q':
 #if IVSIZE >= 8
                                   uv = va_arg(*args, Uquad_t);       break;
@@ -12763,6 +12767,7 @@ Perl_sv_vcatpvfn_flags(pTHX_ SV *const sv, const char 
                         case 'l': uv = (unsigned long)tuv;  break;
                         case 'V':
                         default:  uv = tuv;                 break;
+                        case 'P': uv = (PERL_UINTPTR_T)tuv; break;
                         case 'q':
 #if IVSIZE >= 8
                                   uv = (Uquad_t)tuv;        break;
@@ -12906,6 +12911,7 @@ Perl_sv_vcatpvfn_flags(pTHX_ SV *const sv, const char 
 	    case 'z':
 	    case 't':
 	    case 'j':
+	    case 'P':
 		goto unknown;
 	    }
 
@@ -13292,6 +13298,7 @@ Perl_sv_vcatpvfn_flags(pTHX_ SV *const sv, const char 
                     case 't':  *(va_arg(*args, ptrdiff_t*)) = i; break;
 #endif
                     case 'j':  *(va_arg(*args, PERL_INTMAX_T*)) = i; break;
+                    case 'P':  *(va_arg(*args, PERL_INTPTR_T*)) = i; break;
                     case 'q':
 #if IVSIZE >= 8
                                *(va_arg(*args, Quad_t*))    = i; break;
@@ -13895,7 +13902,7 @@ Perl_ptr_table_new(pTHX)
 }
 
 #define PTR_TABLE_HASH(ptr) \
-  ((PTR2UV(ptr) >> 3) ^ (PTR2UV(ptr) >> (3 + 7)) ^ (PTR2UV(ptr) >> (3 + 17)))
+  ((PTR2UVINT(ptr) >> 3) ^ (PTR2UVINT(ptr) >> (3 + 7)) ^ (PTR2UVINT(ptr) >> (3 + 17)))
 
 /* map an existing pointer using a table */
 
@@ -13903,7 +13910,7 @@ S_ptr_table_find(PTR_TBL_t *const tbl, const void *con
 S_ptr_table_find(PTR_TBL_t *const tbl, const void *const sv)
 {
     PTR_TBL_ENT_t *tblent;
-    const UV hash = PTR_TABLE_HASH(sv);
+    const UVINT hash = PTR_TABLE_HASH(sv);
 
     PERL_ARGS_ASSERT_PTR_TABLE_FIND;
 
@@ -13941,7 +13948,7 @@ Perl_ptr_table_store(pTHX_ PTR_TBL_t *const tbl, const
     if (tblent) {
 	tblent->newval = newsv;
     } else {
-	const UV entry = PTR_TABLE_HASH(oldsv) & tbl->tbl_max;
+	const UVINT entry = PTR_TABLE_HASH(oldsv) & tbl->tbl_max;
 
 	if (tbl->tbl_arena_next == tbl->tbl_arena_end) {
 	    struct ptr_tbl_arena *new_arena;
@@ -13971,8 +13978,8 @@ Perl_ptr_table_split(pTHX_ PTR_TBL_t *const tbl)
 Perl_ptr_table_split(pTHX_ PTR_TBL_t *const tbl)
 {
     PTR_TBL_ENT_t **ary = tbl->tbl_ary;
-    const UV oldsize = tbl->tbl_max + 1;
-    UV newsize = oldsize * 2;
+    const UVINT oldsize = tbl->tbl_max + 1;
+    UVINT newsize = oldsize * 2;
     UV i;
 
     PERL_ARGS_ASSERT_PTR_TABLE_SPLIT;
