--- rtl/bsd/x86_64/syscallh.inc	2008-10-31 18:19:44.000000000 +0000
+++ rtl/bsd/x86_64/syscallh.inc	2010-08-12 11:35:15.000000000 +0100
@@ -41,7 +41,5 @@
 function do_sysCall(sysnr,param1,param2,param3,param4,param5,param6:TSysParam):int64; external name 'FPC_DOSYS6';
 function do_sysCall(sysnr,param1,param2,param3,param4,param5,param6,param7:TSysParam):int64; external name 'FPC_DOSYS7';
 
-// special
-function do__sysCall(sysnr,param1,param2,param3,param4,param5,param6,param7,Param8:TSysParam):TSysResult; external name 'FPC__DOSYS';
 {$endif}
 
