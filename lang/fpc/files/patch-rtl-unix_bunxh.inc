--- rtl/unix/bunxh.inc	2020-02-21 18:37:42.890255000 -0500
+++ rtl/unix/bunxh.inc	2020-02-21 18:38:00.256721000 -0500
@@ -34,7 +34,7 @@
     Function  FpChmod      (path : pChar; Mode : TMode): cInt;
     Function  FpChown      (path : pChar; owner : TUid; group : TGid): cInt;
     Function  FpUtime      (path : pChar; times : putimbuf): cInt;
-    Function  FpPipe       (var fildes : tfildes):cInt;
+    Function  FpPipe       (var fildes : tfildes; flags : cInt):cInt;
     Function  FpDup        (fildes : cInt): cInt;  external name 'FPC_SYSC_DUP';
     Function  FpDup2       (fildes, fildes2 : cInt): cInt; external name 'FPC_SYSC_DUP2';
     Function  FpTimes      (var buffer : tms): TClock;
