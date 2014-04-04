--- villa/mod_villa.c.orig	2014-03-29 18:35:17.000000000 +0100
+++ villa/mod_villa.c	2014-03-29 18:37:37.000000000 +0100
@@ -304,7 +304,7 @@
   int index, omode, cmode;
   VLCFUNC cmp;
   if((index = getnewindex()) == -1) myerror(DP_EMISC);
-  name = STR2CSTR(vname);
+  name = StringValuePtr(vname);
   FIXNUM_P(vomode);
   omode = FIX2INT(vomode);
   FIXNUM_P(vcmode);
@@ -352,10 +352,10 @@
   int index, ksiz, vsiz, dmode;
   FIXNUM_P(vindex);
   if((index = FIX2INT(vindex)) == -1) myerror(DP_EMISC);
-  kbuf = STR2CSTR(vkey);
-  ksiz = RSTRING(vkey)->len;
-  vbuf = STR2CSTR(vval);
-  vsiz = RSTRING(vval)->len;
+  kbuf = StringValuePtr(vkey);
+  ksiz = RSTRING_LEN(vkey);
+  vbuf = StringValuePtr(vval);
+  vsiz = RSTRING_LEN(vval);
   FIXNUM_P(vdmode);
   dmode = FIX2INT(vdmode);
   villa = vltable[index];
@@ -373,8 +373,8 @@
   int index, ksiz;
   FIXNUM_P(vindex);
   if((index = FIX2INT(vindex)) == -1) myerror(DP_EMISC);
-  kbuf = STR2CSTR(vkey);
-  ksiz = RSTRING(vkey)->len;
+  kbuf = StringValuePtr(vkey);
+  ksiz = RSTRING_LEN(vkey);
   villa = vltable[index];
   if(!vlout(villa, kbuf, ksiz)){
     if(vlsltable[index] && dpecode == DP_ENOITEM) return Qfalse;
@@ -391,8 +391,8 @@
   VALUE vval;
   FIXNUM_P(vindex);
   if((index = FIX2INT(vindex)) == -1) myerror(DP_EMISC);
-  kbuf = STR2CSTR(vkey);
-  ksiz = RSTRING(vkey)->len;
+  kbuf = StringValuePtr(vkey);
+  ksiz = RSTRING_LEN(vkey);
   villa = vltable[index];
   if(!(vbuf = vlget(villa, kbuf, ksiz, &vsiz))){
     if(vlsltable[index] && dpecode == DP_ENOITEM) return Qnil;
@@ -409,8 +409,8 @@
   int index, ksiz, vsiz;
   FIXNUM_P(vindex);
   if((index = FIX2INT(vindex)) == -1) myerror(DP_EMISC);
-  kbuf = STR2CSTR(vkey);
-  ksiz = RSTRING(vkey)->len;
+  kbuf = StringValuePtr(vkey);
+  ksiz = RSTRING_LEN(vkey);
   villa = vltable[index];
   if((vsiz = vlvsiz(villa, kbuf, ksiz)) == -1){
     if(vlsltable[index] && dpecode == DP_ENOITEM) return INT2FIX(-1);
@@ -426,8 +426,8 @@
   int index, ksiz, vnum;
   FIXNUM_P(vindex);
   if((index = FIX2INT(vindex)) == -1) myerror(DP_EMISC);
-  kbuf = STR2CSTR(vkey);
-  ksiz = RSTRING(vkey)->len;
+  kbuf = StringValuePtr(vkey);
+  ksiz = RSTRING_LEN(vkey);
   villa = vltable[index];
   vnum = vlvnum(villa, kbuf, ksiz);
   return INT2FIX(vnum);
@@ -497,8 +497,8 @@
   VALUE vval;
   FIXNUM_P(vindex);
   if((index = FIX2INT(vindex)) == -1) myerror(DP_EMISC);
-  kbuf = STR2CSTR(vkey);
-  ksiz = RSTRING(vkey)->len;
+  kbuf = StringValuePtr(vkey);
+  ksiz = RSTRING_LEN(vkey);
   FIXNUM_P(vjmode);
   jmode = FIX2INT(vjmode);
   villa = vltable[index];
@@ -551,8 +551,8 @@
   int index, vsiz, cpmode;
   FIXNUM_P(vindex);
   if((index = FIX2INT(vindex)) == -1) myerror(DP_EMISC);
-  vbuf = STR2CSTR(vval);
-  vsiz = RSTRING(vval)->len;
+  vbuf = StringValuePtr(vval);
+  vsiz = RSTRING_LEN(vval);
   FIXNUM_P(vcpmode);
   cpmode = FIX2INT(vcpmode);
   villa = vltable[index];
