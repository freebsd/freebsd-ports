--- qsstv/sstvparam.cpp.orig	Sat Jul  6 17:37:37 2002
+++ qsstv/sstvparam.cpp	Fri Oct 29 00:11:50 2004
@@ -198,24 +198,24 @@
    0xAC,
    GBR,
    {
-     {PHASET1},             // PHASET0  start new line
-     {PHASET2},             // PHASET1  get sync
-     {PHASET4},             // PHASET2  get backporch
-     {PHASET8},             // PHASET3  set red line
-     {PHASET6},             // PHASET4  set green line
-     {PHASET7},             // PHASET5  set  blue line
-     {PHASET9},             // PHASET6  get green line
-     {PHASETA},             // PHASET7  get blue line
-     {PHASETE},             // PHASET8  get red  line
-     {PHASET5},             // PHASET9  F1500
-     {PHASET3},             // PHASETA  F1900A
-     {PHASET1},             // PHASETB  F2300
-     {PHASET1},             // PHASETC  F1900B
-     {PHASET1},             // PHASETD  future
-     {NEXTRGB},             // PHASETE  frontporch
-     {PHASET0},             // NEXTRGB
-     {PHASET1},             // NEXTXYZOE
-     {PHASET1}              // NEXTXYZOE2
+     PHASET1,             // PHASET0  start new line
+     PHASET2,             // PHASET1  get sync
+     PHASET4,             // PHASET2  get backporch
+     PHASET8,             // PHASET3  set red line
+     PHASET6,             // PHASET4  set green line
+     PHASET7,             // PHASET5  set  blue line
+     PHASET9,             // PHASET6  get green line
+     PHASETA,             // PHASET7  get blue line
+     PHASETE,             // PHASET8  get red  line
+     PHASET5,             // PHASET9  F1500
+     PHASET3,             // PHASETA  F1900A
+     PHASET1,             // PHASETB  F2300
+     PHASET1,             // PHASETC  F1900B
+     PHASET1,             // PHASETD  future
+     NEXTRGB,             // PHASETE  frontporch
+     PHASET0,             // NEXTRGB
+     PHASET1,             // NEXTXYZOE
+     PHASET1              // NEXTXYZOE2
    }
   },
 
@@ -234,24 +234,24 @@
    0x28,
    GBR,
    {
-     {PHASET1},             // PHASET0  start new line
-     {PHASET2},             // PHASET1  get sync
-     {PHASET4},             // PHASET2  get backporch
-     {PHASET8},             // PHASET3  set red line
-     {PHASET6},             // PHASET4  set green line
-     {PHASET7},             // PHASET5  set  blue line
-     {PHASET9},             // PHASET6  get green line
-     {PHASETA},             // PHASET7  get blue line
-     {PHASETE},             // PHASET8  get red  line
-     {PHASET5},             // PHASET9  F1500
-     {PHASET3},             // PHASETA  F1900A
-     {PHASET1},             // PHASETB  F2300
-     {PHASET1},             // PHASETC  F1900B
-     {PHASET1},             // PHASETD  future
-     {NEXTRGB},             // PHASETE  frontporch
-     {PHASET0},             // NEXTRGB
-     {PHASET1},             // NEXTXYZOE
-     {PHASET1}              // NEXTXYZOE2
+     PHASET1,             // PHASET0  start new line
+     PHASET2,             // PHASET1  get sync
+     PHASET4,             // PHASET2  get backporch
+     PHASET8,             // PHASET3  set red line
+     PHASET6,             // PHASET4  set green line
+     PHASET7,             // PHASET5  set  blue line
+     PHASET9,             // PHASET6  get green line
+     PHASETA,             // PHASET7  get blue line
+     PHASETE,             // PHASET8  get red  line
+     PHASET5,             // PHASET9  F1500
+     PHASET3,             // PHASETA  F1900A
+     PHASET1,             // PHASETB  F2300
+     PHASET1,             // PHASETC  F1900B
+     PHASET1,             // PHASETD  future
+     NEXTRGB,             // PHASETE  frontporch
+     PHASET0,             // NEXTRGB
+     PHASET1,             // NEXTXYZOE
+     PHASET1              // NEXTXYZOE2
    }
   },
   
@@ -270,24 +270,24 @@
    0x3c,
    GBR2,
    {
-     {PHASET9},             // PHASET0  start new line
-     {PHASET2},             // PHASET1  get sync
-     {PHASET3},             // PHASET2  get backporch
-     {PHASET8},             // PHASET3  set red line
-     {PHASET6},             // PHASET4  set green line
-     {PHASET7},             // PHASET5  set  blue line
-     {PHASETA},             // PHASET6  get green line
-     {PHASETE},             // PHASET7  get blue line
-     {NEXTRGB},             // PHASET8  get red  line
-     {PHASET4},             // PHASET9  f1
-     {PHASET5},             // PHASETA  f2
-     {PHASET1},             // PHASETB  f3
-     {PHASET1},             // PHASETC  F1900B
-     {PHASET1},             // PHASETD  future
-     {PHASET1},             // PHASETE  frontporch
-     {PHASET0},             // NEXTRGB
-     {PHASET1},             // NEXTXYZOE
-     {PHASET1}              // NEXTXYZOE2
+     PHASET9,             // PHASET0  start new line
+     PHASET2,             // PHASET1  get sync
+     PHASET3,             // PHASET2  get backporch
+     PHASET8,             // PHASET3  set red line
+     PHASET6,             // PHASET4  set green line
+     PHASET7,             // PHASET5  set  blue line
+     PHASETA,             // PHASET6  get green line
+     PHASETE,             // PHASET7  get blue line
+     NEXTRGB,             // PHASET8  get red  line
+     PHASET4,             // PHASET9  f1
+     PHASET5,             // PHASETA  f2
+     PHASET1,             // PHASETB  f3
+     PHASET1,             // PHASETC  F1900B
+     PHASET1,             // PHASETD  future
+     PHASET1,             // PHASETE  frontporch
+     PHASET0,             // NEXTRGB
+     PHASET1,             // NEXTXYZOE
+     PHASET1              // NEXTXYZOE2
    }  
   },
   
@@ -306,24 +306,24 @@
    0xb8,
    GBR2,
    {
-     {PHASET9},             // PHASET0  start new line
-     {PHASET2},             // PHASET1  get sync
-     {PHASET3},             // PHASET2  get backporch
-     {PHASET8},             // PHASET3  set red line
-     {PHASET6},             // PHASET4  set green line
-     {PHASET7},             // PHASET5  set  blue line
-     {PHASETA},             // PHASET6  get green line
-     {PHASETE},             // PHASET7  get blue line
-     {NEXTRGB},             // PHASET8  get red  line
-     {PHASET4},             // PHASET9  blanking1
-     {PHASET5},             // PHASETA  blanking2
-     {PHASET1},             // PHASETB  F2300
-     {PHASET1},             // PHASETC  F1900B
-     {PHASET1},             // PHASETD  future
-     {PHASET1},             // PHASETE  frontporch
-     {PHASET0},             // NEXTRGB
-     {PHASET1},             // NEXTXYZOE
-     {PHASET1}              // NEXTXYZOE2
+     PHASET9,             // PHASET0  start new line
+     PHASET2,             // PHASET1  get sync
+     PHASET3,             // PHASET2  get backporch
+     PHASET8,             // PHASET3  set red line
+     PHASET6,             // PHASET4  set green line
+     PHASET7,             // PHASET5  set  blue line
+     PHASETA,             // PHASET6  get green line
+     PHASETE,             // PHASET7  get blue line
+     NEXTRGB,             // PHASET8  get red  line
+     PHASET4,             // PHASET9  blanking1
+     PHASET5,             // PHASETA  blanking2
+     PHASET1,             // PHASETB  F2300
+     PHASET1,             // PHASETC  F1900B
+     PHASET1,             // PHASETD  future
+     PHASET1,             // PHASETE  frontporch
+     PHASET0,             // NEXTRGB
+     PHASET1,             // NEXTXYZOE
+     PHASET1              // NEXTXYZOE2
    }  
   },
   
@@ -342,24 +342,24 @@
    0xcc,
    GBR2,
    {
-     {PHASET9},             // PHASET0  start new line
-     {PHASET2},             // PHASET1  get sync
-     {PHASET3},             // PHASET2  get backporch
-     {PHASET8},             // PHASET3  set red line
-     {PHASET6},             // PHASET4  set green line
-     {PHASET7},             // PHASET5  set  blue line
-     {PHASETA},             // PHASET6  get green line
-     {PHASET1},             // PHASET7  get blue line
-     {NEXTRGB},             // PHASET8  get red  line
-     {PHASET4},             // PHASET9  blanking1
-     {PHASET5},             // PHASETA  blanking2
-     {PHASET1},             // PHASETB  F2300
-     {PHASET1},             // PHASETC  F1900B
-     {PHASET1},             // PHASETD  future
-     {PHASET1},             // PHASETE  frontporch
-     {PHASET0},             // NEXTRGB
-     {PHASET1},             // NEXTXYZOE
-     {PHASET1}              // NEXTXYZOE2
+     PHASET9,             // PHASET0  start new line
+     PHASET2,             // PHASET1  get sync
+     PHASET3,             // PHASET2  get backporch
+     PHASET8,             // PHASET3  set red line
+     PHASET6,             // PHASET4  set green line
+     PHASET7,             // PHASET5  set  blue line
+     PHASETA,             // PHASET6  get green line
+     PHASET1,             // PHASET7  get blue line
+     NEXTRGB,             // PHASET8  get red  line
+     PHASET4,             // PHASET9  blanking1
+     PHASET5,             // PHASETA  blanking2
+     PHASET1,             // PHASETB  F2300
+     PHASET1,             // PHASETC  F1900B
+     PHASET1,             // PHASETD  future
+     PHASET1,             // PHASETE  frontporch
+     PHASET0,             // NEXTRGB
+     PHASET1,             // NEXTXYZOE
+     PHASET1              // NEXTXYZOE2
    }
   },
 
@@ -378,24 +378,24 @@
    0xB7,
    RGB,
    {
-     {PHASET1},             // PHASET0  start new line
-     {PHASET2},             // PHASET1  get sync
-     {PHASET3},             // PHASET2  get backporch
-     {PHASET8},             // PHASET3  set red line
-     {PHASET6},             // PHASET4  set green line
-     {PHASET7},             // PHASET5  set  blue line
-     {PHASET5},             // PHASET6  get green line
-     {PHASETE},             // PHASET7  get blue line
-     {PHASET4},             // PHASET8  get red  line
-     {PHASET1},             // PHASET9  F1500
-     {PHASET1},             // PHASETA  F1900A
-     {PHASET1},             // PHASETB  F2300
-     {PHASET1},             // PHASETC  F1900B
-     {PHASET1},             // PHASETD  future
-     {NEXTRGB},             // PHASETE  frontporch
-     {PHASET0},             // NEXTRGB
-     {PHASET1},             // NEXTXYZOE
-     {PHASET1}              // NEXTXYZOE2
+     PHASET1,             // PHASET0  start new line
+     PHASET2,             // PHASET1  get sync
+     PHASET3,             // PHASET2  get backporch
+     PHASET8,             // PHASET3  set red line
+     PHASET6,             // PHASET4  set green line
+     PHASET7,             // PHASET5  set  blue line
+     PHASET5,             // PHASET6  get green line
+     PHASETE,             // PHASET7  get blue line
+     PHASET4,             // PHASET8  get red  line
+     PHASET1,             // PHASET9  F1500
+     PHASET1,             // PHASETA  F1900A
+     PHASET1,             // PHASETB  F2300
+     PHASET1,             // PHASETC  F1900B
+     PHASET1,             // PHASETD  future
+     NEXTRGB,             // PHASETE  frontporch
+     PHASET0,             // NEXTRGB
+     PHASET1,             // NEXTXYZOE
+     PHASET1              // NEXTXYZOE2
    }
   },
   
@@ -414,24 +414,24 @@
    0x88,
    XYZOE,
    {
-     {PHASET1},             // PHASET0  detect end of viscode
-     {PHASET2},             // PHASET1  get sync
-     {PHASET3},             // PHASET2  get backporch
-     {PHASET8},             // PHASET3  set red line
-     {PHASET6},             // PHASET4  set green line
-     {PHASET7},             // PHASET5  set  blue line
-     {PHASETE},             // PHASET6  get green line
-     {PHASET3},             // PHASET7  get blue line
-     {PHASET9},             // PHASET8  get red  line
-     {PHASETB},             // PHASET9  blanking 1 /F1500
-     {PHASET1},             // PHASETA  blanking 2
-     {PHASET4},             // PHASETB
-     {PHASET1},             // PHASETC
-     {PHASET1},             // PHASETD  future
-     {NEXTXYZOE},         	// PHASETE  frontporch
-     {PHASET1},             // NEXTRGB
-     {PHASET0},             // NEXTXYZOE
-     {PHASET1}              // NEXTXYZOE2
+     PHASET1,             // PHASET0  detect end of viscode
+     PHASET2,             // PHASET1  get sync
+     PHASET3,             // PHASET2  get backporch
+     PHASET8,             // PHASET3  set red line
+     PHASET6,             // PHASET4  set green line
+     PHASET7,             // PHASET5  set  blue line
+     PHASETE,             // PHASET6  get green line
+     PHASET3,             // PHASET7  get blue line
+     PHASET9,             // PHASET8  get red  line
+     PHASETB,             // PHASET9  blanking 1 /F1500
+     PHASET1,             // PHASETA  blanking 2
+     PHASET4,             // PHASETB
+     PHASET1,             // PHASETC
+     PHASET1,             // PHASETD  future
+     NEXTXYZOE,         	// PHASETE  frontporch
+     PHASET1,             // NEXTRGB
+     PHASET0,             // NEXTXYZOE
+     PHASET1              // NEXTXYZOE2
    }
   },  
 
@@ -450,24 +450,24 @@
    0x0C,
    XYZOE2,
   {
-     {PHASET1},             // PHASET0  detect end of viscode
-     {PHASET2},             // PHASET1  get sync
-     {PHASET3},             // PHASET2  get backporch
-     {PHASET8},             // PHASET3  set red line
-     {PHASET6},             // PHASET4  set green line
-     {PHASET7},             // PHASET5  set  blue line
-     {PHASETA},             // PHASET6  get green line
-     {PHASETE},             // PHASET7  get blue line
-     {PHASET9},             // PHASET8  get red  line
-     {PHASETB},             // PHASET9  F1500
-     {PHASETC},             // PHASETA  F2300
-     {PHASET4},             // PHASETB  F1900A
-     {PHASET5},             // PHASETC  F1900B
-     {PHASET1},             // PHASETD  future
-     {NEXTXYZOE2},       // PHASETE  frontporch
-     {PHASET1},             // NEXTRGB
-     {PHASET1},             // NEXTXYZOE
-     {PHASET0}              // NEXTXYZOE2
+     PHASET1,             // PHASET0  detect end of viscode
+     PHASET2,             // PHASET1  get sync
+     PHASET3,             // PHASET2  get backporch
+     PHASET8,             // PHASET3  set red line
+     PHASET6,             // PHASET4  set green line
+     PHASET7,             // PHASET5  set  blue line
+     PHASETA,             // PHASET6  get green line
+     PHASETE,             // PHASET7  get blue line
+     PHASET9,             // PHASET8  get red  line
+     PHASETB,             // PHASET9  F1500
+     PHASETC,             // PHASETA  F2300
+     PHASET4,             // PHASETB  F1900A
+     PHASET5,             // PHASETC  F1900B
+     PHASET1,             // PHASETD  future
+     NEXTXYZOE2,       // PHASETE  frontporch
+     PHASET1,             // NEXTRGB
+     PHASET1,             // NEXTXYZOE
+     PHASET0              // NEXTXYZOE2
    }
   },
   {"P3",     "P3"   ,
@@ -485,24 +485,24 @@
    0x71,
    RGB,
   {
-     {PHASET1},             // PHASET0  detect end of viscode
-     {PHASET2},             // PHASET1  get sync
-     {PHASET3},             // PHASET2  get backporch
-     {PHASET8},             // PHASET3  set red line
-     {PHASET6},             // PHASET4  set green line
-     {PHASET7},             // PHASET5  set  blue line
-     {PHASETA},             // PHASET6  get green line
-     {NEXTRGB},             // PHASET7  get blue line
-     {PHASET9},             // PHASET8  get red  line
-     {PHASET4},             // PHASET9  F1500
-     {PHASET5},             // PHASETA  F1900A
-     {PHASET1},             // PHASETB  F2300
-     {PHASET1},             // PHASETC  F1900B
-     {PHASET1},             // PHASETD  future
-     {PHASET0},             // PHASETE  frontporch
-     {PHASETE},             // NEXTRGB
-     {PHASET1},             // NEXTXYZOE
-     {PHASET1}              // NEXTXYZOE2
+     PHASET1,             // PHASET0  detect end of viscode
+     PHASET2,             // PHASET1  get sync
+     PHASET3,             // PHASET2  get backporch
+     PHASET8,             // PHASET3  set red line
+     PHASET6,             // PHASET4  set green line
+     PHASET7,             // PHASET5  set  blue line
+     PHASETA,             // PHASET6  get green line
+     NEXTRGB,             // PHASET7  get blue line
+     PHASET9,             // PHASET8  get red  line
+     PHASET4,             // PHASET9  F1500
+     PHASET5,             // PHASETA  F1900A
+     PHASET1,             // PHASETB  F2300
+     PHASET1,             // PHASETC  F1900B
+     PHASET1,             // PHASETD  future
+     PHASET0,             // PHASETE  frontporch
+     PHASETE,             // NEXTRGB
+     PHASET1,             // NEXTXYZOE
+     PHASET1              // NEXTXYZOE2
    }  
   }
 
@@ -522,24 +522,24 @@
    0x72,
    RGB,
   {
-     {PHASET1},             // PHASET0  detect end of viscode
-     {PHASET2},             // PHASET1  get sync
-     {PHASET3},             // PHASET2  get backporch
-     {PHASET8},             // PHASET3  set red line
-     {PHASET6},             // PHASET4  set green line
-     {PHASET7},             // PHASET5  set  blue line
-     {PHASETA},             // PHASET6  get green line
-     {NEXTRGB},             // PHASET7  get blue line
-     {PHASET9},             // PHASET8  get red  line
-     {PHASET4},             // PHASET9  F1500
-     {PHASET5},             // PHASETA  F1900A
-     {PHASET1},             // PHASETB  F2300
-     {PHASET1},             // PHASETC  F1900B
-     {PHASET1},             // PHASETD  future
-     {PHASET0},             // PHASETE  frontporch
-     {PHASETE},             // NEXTRGB
-     {PHASET1},             // NEXTXYZOE
-     {PHASET1}              // NEXTXYZOE2
+     PHASET1,             // PHASET0  detect end of viscode
+     PHASET2,             // PHASET1  get sync
+     PHASET3,             // PHASET2  get backporch
+     PHASET8,             // PHASET3  set red line
+     PHASET6,             // PHASET4  set green line
+     PHASET7,             // PHASET5  set  blue line
+     PHASETA,             // PHASET6  get green line
+     NEXTRGB,             // PHASET7  get blue line
+     PHASET9,             // PHASET8  get red  line
+     PHASET4,             // PHASET9  F1500
+     PHASET5,             // PHASETA  F1900A
+     PHASET1,             // PHASETB  F2300
+     PHASET1,             // PHASETC  F1900B
+     PHASET1,             // PHASETD  future
+     PHASET0,             // PHASETE  frontporch
+     PHASETE,             // NEXTRGB
+     PHASET1,             // NEXTXYZOE
+     PHASET1              // NEXTXYZOE2
    }  
   }
 ,
@@ -558,24 +558,24 @@
    0xF3,
    RGB,
   {
-     {PHASET1},             // PHASET0  detect end of viscode
-     {PHASET2},             // PHASET1  get sync
-     {PHASET3},             // PHASET2  get backporch
-     {PHASET8},             // PHASET3  set red line
-     {PHASET6},             // PHASET4  set green line
-     {PHASET7},             // PHASET5  set  blue line
-     {PHASETA},             // PHASET6  get green line
-     {NEXTRGB},             // PHASET7  get blue line
-     {PHASET9},             // PHASET8  get red  line
-     {PHASET4},             // PHASET9  F1500
-     {PHASET5},             // PHASETA  F1900A
-     {PHASET1},             // PHASETB  F2300
-     {PHASET1},             // PHASETC  F1900B
-     {PHASET1},             // PHASETD  future
-     {PHASET0},             // PHASETE  frontporch
-     {PHASETE},             // NEXTRGB
-     {PHASET1},             // NEXTXYZOE
-     {PHASET1}              // NEXTXYZOE2
+     PHASET1,             // PHASET0  detect end of viscode
+     PHASET2,             // PHASET1  get sync
+     PHASET3,             // PHASET2  get backporch
+     PHASET8,             // PHASET3  set red line
+     PHASET6,             // PHASET4  set green line
+     PHASET7,             // PHASET5  set  blue line
+     PHASETA,             // PHASET6  get green line
+     NEXTRGB,             // PHASET7  get blue line
+     PHASET9,             // PHASET8  get red  line
+     PHASET4,             // PHASET9  F1500
+     PHASET5,             // PHASETA  F1900A
+     PHASET1,             // PHASETB  F2300
+     PHASET1,             // PHASETC  F1900B
+     PHASET1,             // PHASETD  future
+     PHASET0,             // PHASETE  frontporch
+     PHASETE,             // NEXTRGB
+     PHASET1,             // NEXTXYZOE
+     PHASET1              // NEXTXYZOE2
    }  
   }
 
