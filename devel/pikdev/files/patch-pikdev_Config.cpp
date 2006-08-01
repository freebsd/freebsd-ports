--- src/Config.cpp	Mon Jul 31 18:21:46 2006
+++ src/Config.cpp	Mon Jul 31 18:22:14 2006
@@ -123,7 +123,7 @@
     vdd       = conf->readNumEntry("vdd", -4 ) ;
     vpp       = conf->readNumEntry("vpp", -5 ) ;
     clkdelay  = conf->readNumEntry("clkdelay", 0 ) ;
-    port      = conf->readEntry("device", "/dev/parport0" ) ;
+    port      = conf->readEntry("device", "/dev/ppi0" ) ;
 }
 
 
@@ -142,7 +142,7 @@
     vdd       = conf->readNumEntry("vdd", 5 ) ;
     vpp       = conf->readNumEntry("vpp", 3 ) ;
     clkdelay  = conf->readNumEntry("clkdelay", 0 ) ;
-    port      = conf->readEntry("device", "/dev/ttyS0" ) ;
+    port      = conf->readEntry("device", "/dev/sio0" ) ;
 }
 
 void Config::getSer555PortConfig(QString &port, int &vpp, int& vdd, int &clock,
@@ -159,7 +159,7 @@
     vdd       = conf->readNumEntry("vdd", 5 ) ;
     vpp       = conf->readNumEntry("vpp", 3 ) ;
     clkdelay  = conf->readNumEntry("clkdelay", 0 ) ;
-    port      = conf->readEntry("device", "/dev/ttyUSB0" ) ;
+    port      = conf->readEntry("device", "/dev/usb" ) ;
 }
 
 /** Write informations about  known standard programming cards */
