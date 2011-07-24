--- villa/mod_villa.c.orig	2011-07-24 16:03:33.000000000 +0000
+++ villa/mod_villa.c	2011-07-24 16:05:49.000000000 +0000
@@ -353,9 +353,9 @@
   FIXNUM_P(vindex);
   if((index = FIX2INT(vindex)) == -1) myerror(DP_EMISC);
   kbuf = STR2CSTR(vkey);
-  ksiz = RSTRING(vkey)->len;
+  ksiz = RSTRING_LEN(vkey);
   vbuf = STR2CSTR(vval);
-  vsiz = RSTRING(vval)->len;
+  vsiz = RSTRING_LEN(vval);
   FIXNUM_P(vdmode);
   dmode = FIX2INT(vdmode);
   villa = vltable[index];
@@ -374,7 +374,7 @@
   FIXNUM_P(vindex);
   if((index = FIX2INT(vindex)) == -1) myerror(DP_EMISC);
   kbuf = STR2CSTR(vkey);
-  ksiz = RSTRING(vkey)->len;
+  ksiz = RSTRING_LEN(vkey);
   villa = vltable[index];
   if(!vlout(villa, kbuf, ksiz)){
     if(vlsltable[index] && dpecode == DP_ENOITEM) return Qfalse;
@@ -392,7 +392,7 @@
   FIXNUM_P(vindex);
   if((index = FIX2INT(vindex)) == -1) myerror(DP_EMISC);
   kbuf = STR2CSTR(vkey);
-  ksiz = RSTRING(vkey)->len;
+  ksiz = RSTRING_LEN(vkey);
   villa = vltable[index];
   if(!(vbuf = vlget(villa, kbuf, ksiz, &vsiz))){
     if(vlsltable[index] && dpecode == DP_ENOITEM) return Qnil;
@@ -410,7 +410,7 @@
   FIXNUM_P(vindex);
   if((index = FIX2INT(vindex)) == -1) myerror(DP_EMISC);
   kbuf = STR2CSTR(vkey);
-  ksiz = RSTRING(vkey)->len;
+  ksiz = RSTRING_LEN(vkey);
   villa = vltable[index];
   if((vsiz = vlvsiz(villa, kbuf, ksiz)) == -1){
     if(vlsltable[index] && dpecode == DP_ENOITEM) return INT2FIX(-1);
@@ -427,7 +427,7 @@
   FIXNUM_P(vindex);
   if((index = FIX2INT(vindex)) == -1) myerror(DP_EMISC);
   kbuf = STR2CSTR(vkey);
-  ksiz = RSTRING(vkey)->len;
+  ksiz = RSTRING_LEN(vkey);
   villa = vltable[index];
   vnum = vlvnum(villa, kbuf, ksiz);
   return INT2FIX(vnum);
@@ -498,7 +498,7 @@
   FIXNUM_P(vindex);
   if((index = FIX2INT(vindex)) == -1) myerror(DP_EMISC);
   kbuf = STR2CSTR(vkey);
-  ksiz = RSTRING(vkey)->len;
+  ksiz = RSTRING_LEN(vkey);
   FIXNUM_P(vjmode);
   jmode = FIX2INT(vjmode);
   villa = vltable[index];
@@ -552,7 +552,7 @@
   FIXNUM_P(vindex);
   if((index = FIX2INT(vindex)) == -1) myerror(DP_EMISC);
   vbuf = STR2CSTR(vval);
-  vsiz = RSTRING(vval)->len;
+  vsiz = RSTRING_LEN(vval);
   FIXNUM_P(vcpmode);
   cpmode = FIX2INT(vcpmode);
   villa = vltable[index];
