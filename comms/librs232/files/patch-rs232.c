--- rs232.c.orig	2014-10-05 15:21:14.000000000 +0800
+++ rs232.c	2014-12-04 14:24:26.000000000 +0800
@@ -38,19 +38,23 @@
 
 
 
-#ifdef __linux__   /* Linux */
+#if defined(__linux__) || defined(__FreeBSD__)
 
 
-int Cport[30],
+int Cport[38],
     error;
 
 struct termios new_port_settings,
-       old_port_settings[30];
+       old_port_settings[38];
 
-char comports[30][16]={"/dev/ttyS0","/dev/ttyS1","/dev/ttyS2","/dev/ttyS3","/dev/ttyS4","/dev/ttyS5",
-                       "/dev/ttyS6","/dev/ttyS7","/dev/ttyS8","/dev/ttyS9","/dev/ttyS10","/dev/ttyS11",
-                       "/dev/ttyS12","/dev/ttyS13","/dev/ttyS14","/dev/ttyS15","/dev/ttyUSB0",
-                       "/dev/ttyUSB1","/dev/ttyUSB2","/dev/ttyUSB3","/dev/ttyUSB4","/dev/ttyUSB5",
+char comports[38][16]={"/dev/cuau0", "/dev/cuau1", "/dev/cuau2", "/dev/cuau3",
+                       "/dev/cuaU0", "/dev/cuaU1", "/dev/cuaU2", "/dev/cuaU3",
+                       "/dev/ttyS0","/dev/ttyS1","/dev/ttyS2","/dev/ttyS3",
+		       "/dev/ttyS4","/dev/ttyS5", "/dev/ttyS6","/dev/ttyS7",
+                       "/dev/ttyS8","/dev/ttyS9","/dev/ttyS10","/dev/ttyS11",
+                       "/dev/ttyS12","/dev/ttyS13","/dev/ttyS14","/dev/ttyS15",
+		       "/dev/ttyUSB0", "/dev/ttyUSB1","/dev/ttyUSB2",
+		       "/dev/ttyUSB3", "/dev/ttyUSB4","/dev/ttyUSB5",
                        "/dev/ttyAMA0","/dev/ttyAMA1","/dev/ttyACM0","/dev/ttyACM1",
                        "/dev/rfcomm0","/dev/rfcomm1","/dev/ircomm0","/dev/ircomm1"};
 
@@ -61,7 +65,7 @@
   int baudr,
       status;
 
-  if((comport_number>29)||(comport_number<0))
+  if((comport_number>37)||(comport_number<0))
   {
     printf("illegal comport number\n");
     return(1);
@@ -107,28 +111,6 @@
                    break;
     case  460800 : baudr = B460800;
                    break;
-    case  500000 : baudr = B500000;
-                   break;
-    case  576000 : baudr = B576000;
-                   break;
-    case  921600 : baudr = B921600;
-                   break;
-    case 1000000 : baudr = B1000000;
-                   break;
-    case 1152000 : baudr = B1152000;
-                   break;
-    case 1500000 : baudr = B1500000;
-                   break;
-    case 2000000 : baudr = B2000000;
-                   break;
-    case 2500000 : baudr = B2500000;
-                   break;
-    case 3000000 : baudr = B3000000;
-                   break;
-    case 3500000 : baudr = B3500000;
-                   break;
-    case 4000000 : baudr = B4000000;
-                   break;
     default      : printf("invalid baudrate\n");
                    return(1);
                    break;
