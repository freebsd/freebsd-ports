--- rtl/freebsd/ptypes.inc	2013-02-10 12:51:29.000000000 -0500
+++ rtl/freebsd/ptypes.inc	2022-05-29 19:24:36.804227000 -0500
@@ -26,7 +26,7 @@
     SEM_SAFE=255;
 type
 
-    dev_t    = cuint32;         { used for device numbers      }
+    dev_t    = cuint64;         { used for device numbers      }
     TDev     = dev_t;
     pDev     = ^dev_t;
 
@@ -35,11 +35,7 @@
     pGid     = ^gid_t;
     TIOCtlRequest = cuLong;
 
-    {$ifdef CPU64}
-     ino_t    = cuint32;           { used for file serial numbers }
-    {$else}	
-     ino_t    = clong;           { used for file serial numbers }
-    {$endif}
+    ino_t    = cuint64;           { used for file serial numbers }
     TIno     = ino_t;
     pIno     = ^ino_t;
 
@@ -47,7 +43,7 @@
     TMode    = mode_t;
     pMode    = ^mode_t;
 
-    nlink_t  = cuint16;         { used for link counts         }
+    nlink_t  = cuint64;         { used for link counts         }
     TnLink   = nlink_t;
     pnLink   = ^nlink_t;
 
@@ -195,7 +191,7 @@
 
 Type TStatFS =  {?} Record
        case boolean of
-       0 : ( // current FreeBSD
+       false : ( // current FreeBSD
         version     : cuint32;        { structure version number }
         ftype       : cuint32;        { type of filesystem }
         fflags      : cuint64;        { copy of mount exported flags }
@@ -219,7 +215,7 @@
         mnfromname  : array[0..MNAMELEN-1]   of ansichar; { mounted filesystem }
         mountpoint  : array[0..MNAMELEN-1]   of ansichar; { directory on which mounted }
         );
-        1:( // union for old fieldname's sake.
+        true:( // union for old fieldname's sake.
         f_version     : cuint32;        { structure version number }
         f_type        : cuint32;        { type of filesystem }
         f_flags       : cuint64;        { copy of mount exported flags }
