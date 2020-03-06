--- rtl/freebsd/sysnr.inc	2020-02-21 13:23:53.181811000 -0500
+++ rtl/freebsd/sysnr.inc	2020-02-21 17:55:07.026920000 -0500
@@ -16,9 +16,9 @@
 {More or less checked/in use FreeBSD syscalls}
  syscall_nr_readv                       = 120;
  syscall_nr_writev                      = 121;
- syscall_nr_pread                       = 173;
- syscall_nr_pwrite                      = 174;
- syscall_nr_semsys                      = 169;
+ syscall_nr_pread                       = 475;
+ syscall_nr_pwrite                      = 476;
+ syscall_nr_semsys                      = 169; 
  syscall_nr_msgsys                      = 170;
  syscall_nr_shmsys                      = 171;
  syscall_nr_mkfifo                      = 132;
@@ -48,15 +48,15 @@
  syscall_nr_fcntl                       =  92;
  syscall_nr_flock                       = 131;
  syscall_nr_fork                        =   2;
- syscall_nr_fstat                       = 189;
+ syscall_nr_fstat                       = 189;  // COMPAT11x
  syscall_nr_statfs4                     = 157;  // COMPAT4x
  syscall_nr_fstatfs4                    = 158;  // COMPAT4x
- syscall_nr_getfsstat                   = 395;  
+ syscall_nr_getfsstat                   = 395;  // COMPAT11x
  syscall_nr_statfs                      = 396;  
  syscall_nr_fstatfs                     = 397;  
  syscall_nr_fsync                       =  95;
- syscall_nr_ftruncate                   = 201;
- syscall_nr_getdents                    = 272;
+ syscall_nr_ftruncate                   = 480;
+ syscall_nr_getdents                    = 272; 
  syscall_nr_getegid                     =  43;
  syscall_nr_geteuid                     =  25;
  syscall_nr_getgid                      =  47;
@@ -70,15 +70,16 @@
  syscall_nr_ioctl                       =  54;
  syscall_nr_kill                        =  37;
  syscall_nr_link                        =   9;
- syscall_nr_listen                      = 106;
- syscall_nr_lseek                       = 199;
- syscall_nr_lstat                       = 190;
+ syscall_nr_listen                      = 106; 
+ syscall_nr_lseek                       = 478;
+ syscall_nr_lstat                       = 190; 
  syscall_nr_mkdir                       = 136;
  syscall_nr_mknod                       =  14;
- syscall_nr_mmap                        = 197;
+ syscall_nr_mmap                        = 477;
  syscall_nr_open                        =   5;
  syscall_nr_pipe                        =  42;
- syscall_nr_poll                        = 209;
+ syscall_nr_pipe2                       = 542;
+ syscall_nr_poll                        = 209; 
  syscall_nr_read                        =   3;
  syscall_nr_readlink                    =  58;
  syscall_nr_recvfrom                    =  29;
