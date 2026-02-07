--- rtl/unix/oscdeclh.inc	2022-06-17 00:46:14.261191000 -0500
+++ rtl/unix/oscdeclh.inc	2022-06-17 00:48:10.379917000 -0500
@@ -50,7 +50,7 @@
     Function  FpChmod      (path : pChar; Mode : TMode): cInt; cdecl; external clib name 'chmod';
     Function  FpChown   (path : pChar; owner : TUid; group : TGid): cInt; cdecl; external clib name 'chown';
     Function  FPUtime(path:pchar;times:putimbuf):cint; cdecl; external clib name 'utime';
-    Function  FpPipe       (var fildes : tfildes):cInt; cdecl;external clib name 'pipe';
+    Function  FpPipe       (var fildes : tfildes; flags:cint):cInt; cdecl;external clib name 'pipe2';
     function  FpDup     (oldd:cint):cint; cdecl; external clib name 'dup';
     function  FpDup2    (oldd:cint;newd:cint):cint; cdecl; external clib name 'dup2';
     function  FpTimes	(var buffer : tms): TClock; cdecl; external clib name 'times';
