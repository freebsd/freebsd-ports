--- src/bossac.cpp.orig	2017-03-31 15:31:35 UTC
+++ src/bossac.cpp
@@ -64,6 +64,7 @@ class BossaConfig (public)
     bool help;
     bool forceUsb;
     string forceUsbArg;
+    bool arduinoErase;
 
     int readArg;
     string portArg;
@@ -89,6 +90,7 @@ BossaConfig::BossaConfig()
     info = false;
     help = false;
     forceUsb = false;
+    arduinoErase = false;
 
     readArg = 0;
     bootArg = 1;
@@ -189,6 +191,11 @@ static Option opts[] =
       'R', "reset", &config.reset,
       { ArgNone },
       "reset CPU (if supported)"
+    },
+    {
+      'a', "arduino_erase", &config.arduinoErase,
+      { ArgNone },
+      "erase and reset via Arduino 1200 baud hack (cannot be used with port autodetection)"
     }
 };
 
@@ -257,6 +264,12 @@ main(int argc, char* argv[])
         return help(argv[0]);
     }
 
+    if (config.arduinoErase && !config.port)
+    {
+        fprintf(stderr, "%s: port must be specified for Arduino 1200bps erase hack\n", argv[0]);
+        return help(argv[0]);
+    }
+
     if (config.read || config.write || config.verify)
     {
         if (args == argc)
@@ -311,6 +324,25 @@ main(int argc, char* argv[])
                 fprintf(stderr, "Invalid USB value: %s\n", config.forceUsbArg.c_str());
                 return 1;
             }
+        }
+
+        if (config.arduinoErase)
+        {
+            SerialPort::Ptr port;
+            if (config.forceUsb)
+                port = portFactory.create(config.portArg, isUsb);
+            else
+                port = portFactory.create(config.portArg);
+
+            if(!port->open(1200))
+            {
+                fprintf(stderr, "Failed to open port at 1200bps\n");
+                return 1;
+            }
+
+            port->setRTS(true);
+            port->setDTR(false);
+            port->close();
         }
 
         if (config.port)
