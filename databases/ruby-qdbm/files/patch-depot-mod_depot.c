--- depot/mod_depot.c.orig	2011-07-24 15:46:48.000000000 +0000
+++ depot/mod_depot.c	2011-07-24 15:48:24.000000000 +0000
@@ -274,9 +274,9 @@
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
   depot = dptable[index];
@@ -295,7 +295,7 @@
   FIXNUM_P(vindex);
   if((index = FIX2INT(vindex)) == -1) myerror(DP_EMISC);
   kbuf = STR2CSTR(vkey);
-  ksiz = RSTRING(vkey)->len;
+  ksiz = RSTRING_LEN(vkey);
   depot = dptable[index];
   if(!dpout(depot, kbuf, ksiz)){
     if(dpsltable[index] && dpecode == DP_ENOITEM) return Qfalse;
@@ -314,7 +314,7 @@
   FIXNUM_P(vindex);
   if((index = FIX2INT(vindex)) == -1) myerror(DP_EMISC);
   kbuf = STR2CSTR(vkey);
-  ksiz = RSTRING(vkey)->len;
+  ksiz = RSTRING_LEN(vkey);
   FIXNUM_P(vstart);
   start = FIX2INT(vstart);
   FIXNUM_P(vmax);
@@ -337,7 +337,7 @@
   FIXNUM_P(vindex);
   if((index = FIX2INT(vindex)) == -1) myerror(DP_EMISC);
   kbuf = STR2CSTR(vkey);
-  ksiz = RSTRING(vkey)->len;
+  ksiz = RSTRING_LEN(vkey);
   depot = dptable[index];
   if((vsiz = dpvsiz(depot, kbuf, ksiz)) == -1){
     if(dpsltable[index] && dpecode == DP_ENOITEM) return INT2FIX(-1);
