--- rtl/bsd/ostypes.inc.orig	2015-11-13 21:15:29 UTC
+++ rtl/bsd/ostypes.inc
@@ -145,6 +145,16 @@ TYPE
 
   { directory services }
 {$ifndef darwinarm}
+{$ifdef dragonfly}
+   dirent  = record
+        d_fileno      : ino_t;                          // file number of entry
+        d_namlen      : cuint16;                        // strlen (d_name)
+        d_type        : cuint8;                         // file type, see below
+        d_unused1     : cuint8;                         // padding, reserved
+        d_unused2     : cuint32;                        // reserved
+        d_name        : array[0..255] of char;          // name, null terminated
+   end;
+{$else}
    dirent  = record
         d_fileno      : cuint32;                        // file number of entry
         d_reclen      : cuint16;                        // length of this record
@@ -152,6 +162,7 @@ TYPE
         d_namlen      : cuint8;                         // length of string in d_name
         d_name        : array[0..(255 + 1)-1] of char;  // name must be no longer than this
    end;
+{$endif}
 {$else not darwinarm}
    {$packrecords 4}
    { available on Mac OS X 10.6 and later, and used by all iPhoneOS versions }
