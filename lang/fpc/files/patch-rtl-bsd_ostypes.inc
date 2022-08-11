--- rtl/bsd/ostypes.inc	2019-05-04 17:02:10.000000000 -0500
+++ rtl/bsd/ostypes.inc	2022-05-24 17:03:10.944070000 -0500
@@ -107,6 +107,45 @@
         st_gen        : cuint32;           // file generation number
         st_birthtime  : time_t;            // File creation time
         st_birthtimensec : clong;          // nsec of file creation time
+{$elseif defined(freebsd)}
+{$ifdef i386}
+{$define __STAT_TIME_T_EXT}
+{$endif}
+        st_dev        : dev_t;             // inode's device
+        st_ino        : ino_t;             // inode's number
+        st_nlink      : nlink_t;           // number of hard links
+        st_mode       : mode_t;            // inode protection mode
+	st_padding0   : cint16;
+        st_uid        : uid_t;             // user ID of the file's owner
+        st_gid        : gid_t;             // group ID of the file's group
+	st_padding1   : cint32;
+        st_rdev       : dev_t;             // device type
+{$ifdef __STAT_TIME_T_EXT}
+        st_atim_ext   : cint32;
+{$endif}
+        st_atime      : time_t;            // time of last access
+        st_atimensec  : clong;             // nsec of last access
+{$ifdef __STAT_TIME_T_EXT}
+        st_mtim_ext   : cint32;
+{$endif}
+        st_mtime      : time_t;            // time of last data modification
+        st_mtimensec  : clong;             // nsec of last data modification
+{$ifdef __STAT_TIME_T_EXT}
+        st_ctim_ext   : cint32;
+{$endif}
+        st_ctime      : time_t;            // time of last file status change
+        st_ctimensec  : clong;             // nsec of last file status change
+{$ifdef __STAT_TIME_T_EXT}
+        st_birthtim_ext   : cint32;
+{$endif}
+        st_birthtime  : time_t;            // File creation time
+        st_birthtimensec : clong;          // nsec of file creation time
+        st_size       : off_t;             // file size, in bytes
+        st_blocks     : cint64;            // blocks allocated for file
+        st_blksize    : cint32;            // optimal blocksize for I/O
+        st_flags      : cuint32;           // user defined flags for file
+        st_gen        : cuint64;           // file generation number
+	st_spare      : array [0..10-1] of cuint64;
 {$else}
         st_dev        : dev_t;             // inode's device
 {$ifdef darwin_new_iostructs}
@@ -189,6 +228,17 @@
         d_padding     : array[0..3] of cuint8;
         d_name        : array[0..(255 + 1)-1] of char;  // name must be no longer than this
    end;
+{$elseif defined(freebsd)}
+   dirent  = record
+        d_fileno      : ino_t;
+        d_off         : off_t;
+        d_reclen      : cuint16;                        // length of this record
+        d_type        : cuint8;                         // file type, see below
+	d_pad0        : cuint8;
+        d_namlen      : cuint16;                        // length of string in d_name
+	d_pad1        : cuint16;
+        d_name        : array[0..(255 + 1)-1] of char;  // name must be no longer than this
+   end;
 {$else}
    dirent  = record
         d_fileno      : cuint32;                        // file number of entry
@@ -242,6 +292,9 @@
                 l_pid   : pid_t;        { lock owner }
                 l_type  : cshort;       { lock type: read/write, etc. }
                 l_whence: cshort;       { type of l_start }
+{$ifdef freebsd}
+                l_sysid : cint;
+{$endif}
                 end;
    TFlock   = flock;
    pFlock   = ^flock;
