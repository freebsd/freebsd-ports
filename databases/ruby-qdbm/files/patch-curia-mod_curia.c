--- curia/mod_curia.c.orig	2011-07-24 16:00:48.000000000 +0000
+++ curia/mod_curia.c	2011-07-24 16:02:05.000000000 +0000
@@ -277,9 +277,9 @@
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
   curia = crtable[index];
@@ -298,7 +298,7 @@
   FIXNUM_P(vindex);
   if((index = FIX2INT(vindex)) == -1) myerror(DP_EMISC);
   kbuf = STR2CSTR(vkey);
-  ksiz = RSTRING(vkey)->len;
+  ksiz = RSTRING_LEN(vkey);
   curia = crtable[index];
   if(!crout(curia, kbuf, ksiz)){
     if(crsltable[index] && dpecode == DP_ENOITEM) return Qfalse;
@@ -317,7 +317,7 @@
   FIXNUM_P(vindex);
   if((index = FIX2INT(vindex)) == -1) myerror(DP_EMISC);
   kbuf = STR2CSTR(vkey);
-  ksiz = RSTRING(vkey)->len;
+  ksiz = RSTRING_LEN(vkey);
   FIXNUM_P(vstart);
   start = FIX2INT(vstart);
   FIXNUM_P(vmax);
@@ -340,7 +340,7 @@
   FIXNUM_P(vindex);
   if((index = FIX2INT(vindex)) == -1) myerror(DP_EMISC);
   kbuf = STR2CSTR(vkey);
-  ksiz = RSTRING(vkey)->len;
+  ksiz = RSTRING_LEN(vkey);
   curia = crtable[index];
   if((vsiz = crvsiz(curia, kbuf, ksiz)) == -1){
     if(crsltable[index] && dpecode == DP_ENOITEM) return INT2FIX(-1);
