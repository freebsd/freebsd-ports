*** lib/database/src/so/sensors/SoSensorMgr.c++.orig	Sat Jul 12 00:40:53 2003
--- lib/database/src/so/sensors/SoSensorMgr.c++	Sun Feb 22 17:11:52 2004
***************
*** 61,66 ****
--- 61,70 ----
  #include <unistd.h>
  #endif // __APPLE__
  
+ #ifdef __FreeBSD__
+ #include <sys/select.h>
+ #endif
+ 
  #ifdef DEBUG
  #include <SoDebug.h>
  static SbTime startTime;
