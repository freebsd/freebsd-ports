--- curia/mod_curia.c.orig	2006-09-25 12:26:06 UTC
+++ curia/mod_curia.c
@@ -233,7 +233,7 @@ static VALUE rbcropen(VALUE vself, VALUE
   const char *name;
   int index, omode, bnum, dnum;
   if((index = getnewindex()) == -1) myerror(DP_EMISC);
-  name = STR2CSTR(vname);
+  name = StringValuePtr(vname);
   FIXNUM_P(vomode);
   omode = FIX2INT(vomode);
   FIXNUM_P(vbnum);
@@ -276,10 +276,10 @@ static VALUE rbcrput(VALUE vself, VALUE 
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
   curia = crtable[index];
@@ -297,8 +297,8 @@ static VALUE rbcrout(VALUE vself, VALUE 
   int index, ksiz;
   FIXNUM_P(vindex);
   if((index = FIX2INT(vindex)) == -1) myerror(DP_EMISC);
-  kbuf = STR2CSTR(vkey);
-  ksiz = RSTRING(vkey)->len;
+  kbuf = StringValuePtr(vkey);
+  ksiz = RSTRING_LEN(vkey);
   curia = crtable[index];
   if(!crout(curia, kbuf, ksiz)){
     if(crsltable[index] && dpecode == DP_ENOITEM) return Qfalse;
@@ -316,8 +316,8 @@ static VALUE rbcrget(VALUE vself, VALUE 
   VALUE vval;
   FIXNUM_P(vindex);
   if((index = FIX2INT(vindex)) == -1) myerror(DP_EMISC);
-  kbuf = STR2CSTR(vkey);
-  ksiz = RSTRING(vkey)->len;
+  kbuf = StringValuePtr(vkey);
+  ksiz = RSTRING_LEN(vkey);
   FIXNUM_P(vstart);
   start = FIX2INT(vstart);
   FIXNUM_P(vmax);
@@ -339,8 +339,8 @@ static VALUE rbcrvsiz(VALUE vself, VALUE
   int index, ksiz, vsiz;
   FIXNUM_P(vindex);
   if((index = FIX2INT(vindex)) == -1) myerror(DP_EMISC);
-  kbuf = STR2CSTR(vkey);
-  ksiz = RSTRING(vkey)->len;
+  kbuf = StringValuePtr(vkey);
+  ksiz = RSTRING_LEN(vkey);
   curia = crtable[index];
   if((vsiz = crvsiz(curia, kbuf, ksiz)) == -1){
     if(crsltable[index] && dpecode == DP_ENOITEM) return INT2FIX(-1);
