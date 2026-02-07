--- depot/mod_depot.c.orig	2006-09-25 12:21:38 UTC
+++ depot/mod_depot.c
@@ -232,7 +232,7 @@ static VALUE rbdpopen(VALUE vself, VALUE
   const char *name;
   int index, omode, bnum;
   if((index = getnewindex()) == -1) myerror(DP_EMISC);
-  name = STR2CSTR(vname);
+  name = StringValuePtr(vname);
   FIXNUM_P(vomode);
   omode = FIX2INT(vomode);
   FIXNUM_P(vbnum);
@@ -273,10 +273,10 @@ static VALUE rbdpput(VALUE vself, VALUE 
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
   depot = dptable[index];
@@ -294,8 +294,8 @@ static VALUE rbdpout(VALUE vself, VALUE 
   int index, ksiz;
   FIXNUM_P(vindex);
   if((index = FIX2INT(vindex)) == -1) myerror(DP_EMISC);
-  kbuf = STR2CSTR(vkey);
-  ksiz = RSTRING(vkey)->len;
+  kbuf = StringValuePtr(vkey);
+  ksiz = RSTRING_LEN(vkey);
   depot = dptable[index];
   if(!dpout(depot, kbuf, ksiz)){
     if(dpsltable[index] && dpecode == DP_ENOITEM) return Qfalse;
@@ -313,8 +313,8 @@ static VALUE rbdpget(VALUE vself, VALUE 
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
@@ -336,8 +336,8 @@ static VALUE rbdpvsiz(VALUE vself, VALUE
   int index, ksiz, vsiz;
   FIXNUM_P(vindex);
   if((index = FIX2INT(vindex)) == -1) myerror(DP_EMISC);
-  kbuf = STR2CSTR(vkey);
-  ksiz = RSTRING(vkey)->len;
+  kbuf = StringValuePtr(vkey);
+  ksiz = RSTRING_LEN(vkey);
   depot = dptable[index];
   if((vsiz = dpvsiz(depot, kbuf, ksiz)) == -1){
     if(dpsltable[index] && dpecode == DP_ENOITEM) return INT2FIX(-1);
