--- lib/qreport.cc.orig	Fri Feb 23 21:29:12 2001
+++ lib/qreport.cc	Fri Feb 13 19:17:38 2004
@@ -165,7 +165,18 @@
 //  if (msduration>0) {
    // no ho deixis així!!!!
     int dur = msduration;
-    os->form("%3d:%02d:%02d",dur/3600000,(dur%3600000)/60000,(dur%60000)/1000);
+
+    os->width(3);
+    os->fill('0');
+    *os << dur/3600000 << ':';
+    os->width(2);
+    os->fill('0');
+    *os << (dur%3600000) << ':';
+    os->width(2);
+    os->fill('0');
+    *os << (dur%60000)/1000;
+    
+//    os->form("%3d:%02d:%02d",dur/3600000,(dur%3600000)/60000,(dur%60000)/1000);
 //  }
 //  else 
 //    *os << "         ";
@@ -176,7 +187,9 @@
     case 0:               *os << "        "; break;
     case (u_int32_t)(-1): *os << "  [vbr] "; break;
     default:
-      os->form("%3d kbps",bitrate);
+      os->width(3);
+      *os << bitrate << " kbps";
+//      os->form("%3d kbps",bitrate);
   }
 
   *os << " - ";
@@ -190,7 +203,9 @@
 */
 
 //  if (size>0)
-    os->form("%4.2f Mb",(double)size/(1024*1024));
+    os->precision(2);
+    *os << (double)size/(1024*1024) << " Mb";
+//    os->form("%4.2f Mb",(double)size/(1024*1024));
 //  else
 //    *os << "          ";
 
@@ -233,11 +248,15 @@
         *os << "<a href=\"file://" << htmlize(name) << "\">" << name << "</a>: "; 
       else
 */
-        os->form("%-64s",name.c_str());
+	os->width(64);
+	*os << name;
+//        os->form("%-64s",name.c_str());
     break;
     case MP3:
 //      *os << "bliblablo";
-        os->form("%-64s",name.c_str());
+	os->width(64);
+	*os << name;
+//        os->form("%-64s",name.c_str());
     break;
     case DIR:
 /*
@@ -245,10 +264,14 @@
         *os << "<a href=\"file://" << htmlize(name) << "\">" << name << "</a>: "; 
       else
 */
-        os->form("%-64s  ",name.c_str());
+	os->width(64);
+	*os << name;
+//        os->form("%-64s  ",name.c_str());
       if (directories>1) // other than itself
         *os << directories-1 << _(" directories  "); 
-      os->form("%3d file%c  ",files,(files==1)?' ':'s');
+      os->width(3);
+      *os << files << " file" << (files==1)?' ' : 's';
+//      os->form("%3d file%c  ",files,(files==1)?' ':'s');
     break;
   }
 
@@ -265,7 +288,17 @@
 //  if (msduration>0) {
    // no ho deixis així!!!!
     int dur = msduration;
-    os->form("%3d:%02d:%02d",dur/3600000,(dur%3600000)/60000,(dur%60000)/1000);
+
+    os->width(3);
+    os->fill('0');
+    *os << dur/3600000 << ':';
+    os->width(2);
+    os->fill('0');
+    *os << (dur%3600000) << ':';
+    os->width(2);
+    os->fill('0');
+    *os << (dur%60000)/1000;
+    //os->form("%3d:%02d:%02d",dur/3600000,(dur%3600000)/60000,(dur%60000)/1000);
 //  }
 //  else 
 //    *os << "         ";
@@ -277,7 +310,9 @@
     case 0:               *os << "        "; break;
     case (u_int32_t)(-1): *os << "  [vbr] "; break;
     default:
-      os->form("%3d kbps",bitrate);
+      os->width(3);
+      *os << bitrate << " kbps";
+//      os->form("%3d kbps",bitrate);
   }
 
   *os << " - ";
@@ -291,7 +326,9 @@
 */
 
 //  if (size>0)
-    os->form("%4.2f Mb",(double)size/(1024*1024));
+    os->precision(2);
+    *os << (double)size/(1024*1024) << " Mb";
+//    os->form("%4.2f Mb",(double)size/(1024*1024));
 //  else
 //    *os << "          ";
 
@@ -328,11 +365,15 @@
         *os << "<a href=\"file://" << htmlize(name) << "\">" << name << "</a>: "; 
       else
 */
-        os->form("%-64s",name.c_str());
+	os->width(64);
+	*os << name;
+//        os->form("%-64s",name.c_str());
     break;
     case MP3:
 //      *os << "bliblablo";
-        os->form("%-64s",name.c_str());
+	os->width(64);
+	*os << name;
+//        os->form("%-64s",name.c_str());
     break;
     case DIR:
 /*
@@ -340,10 +381,14 @@
         *os << "<a href=\"file://" << htmlize(name) << "\">" << name << "</a>: "; 
       else
 */
-        os->form("%-64s  ",name.c_str());
+	os->width(64);
+	*os << name;
+//        os->form("%-64s  ",name.c_str());
       if (directories>1) // other than itself
         *os << directories-1 << _(" directories  "); 
-      os->form("%3d file%c  ",files,(files==1)?' ':'s');
+      os->width(3);
+      *os << files << " file" << (files==1)?' ':'s';
+//      os->form("%3d file%c  ",files,(files==1)?' ':'s');
     break;
   }
 
