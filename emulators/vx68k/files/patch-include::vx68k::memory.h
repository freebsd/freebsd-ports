--- include/vx68k/memory.h.orig	Fri Dec 22 21:12:50 2000
+++ include/vx68k/memory.h	Wed Dec  1 18:24:18 2004
@@ -24,6 +24,8 @@
 #include <vm68k/processor.h>
 #include <vm68k/memory.h>
 
+#include <iterator.h>
+
 #include <pthread.h>
 
 #include <vector>
@@ -70,12 +72,12 @@
 
   public:
     /* Reads data from this object.  */
-    int get_8(uint32_type address, function_code) const;
-    uint16_type get_16(uint32_type address, function_code) const;
+    int get_8(uint32_type address, function_code) const throw();
+    uint16_type get_16(uint32_type address, function_code) const throw();
 
     /* Writes data to this object.  These methods shall always fail.  */
-    void put_8(uint32_type address, int, function_code);
-    void put_16(uint32_type address, uint16_type, function_code);
+    void put_8(uint32_type address, int, function_code) throw();
+    void put_16(uint32_type address, uint16_type, function_code) throw();
 
   public:
     /* Attaches or detaches an execution unit.  */
@@ -113,14 +115,14 @@
 
   public:
     /* Reads data from this object.  */
-    int get_8(uint32_type address, function_code) const;
-    uint16_type get_16(uint32_type address, function_code) const;
-    uint32_type get_32(uint32_type address, function_code) const;
+    int get_8(uint32_type address, function_code) const throw();
+    uint16_type get_16(uint32_type address, function_code) const throw();
+    uint32_type get_32(uint32_type address, function_code) const throw();
 
     /* Writes data to this object.  */
-    void put_8(uint32_type address, int, function_code);
-    void put_16(uint32_type address, uint16_type, function_code);
-    void put_32(uint32_type address, uint32_type, function_code);
+    void put_8(uint32_type address, int, function_code) throw();
+    void put_16(uint32_type address, uint16_type, function_code) throw();
+    void put_32(uint32_type address, uint32_type, function_code) throw();
 
   public:
     void set_super_area(size_t n);
@@ -132,12 +134,12 @@
   {
   public:
     /* Reads data from this object.  */
-    int get_8(uint32_type address, function_code) const;
-    uint16_type get_16(uint32_type address, function_code) const;
+    int get_8(uint32_type address, function_code) const throw();
+    uint16_type get_16(uint32_type address, function_code) const throw();
 
     /* Writes data to this object.  */
-    void put_8(uint32_type address, int, function_code);
-    void put_16(uint32_type address, uint16_type, function_code);
+    void put_8(uint32_type address, int, function_code) throw();
+    void put_16(uint32_type address, uint16_type, function_code) throw();
   };
 
   /* Raster iterator for the text VRAM.  This class is used by the
@@ -204,11 +206,11 @@
     ~text_video_memory();
 
   public:
-    int get_8(uint32_type address, function_code) const;
-    uint16_type get_16(uint32_type address, function_code) const;
+    int get_8(uint32_type address, function_code) const throw();
+    uint16_type get_16(uint32_type address, function_code) const throw();
 
-    void put_8(uint32_type address, int, function_code);
-    void put_16(uint32_type address, uint16_type, function_code);
+    void put_8(uint32_type address, int, function_code) throw();
+    void put_16(uint32_type address, uint16_type, function_code) throw();
 
   public:
     /* Installs IOCS calls on the text video memory.  */
@@ -279,12 +281,12 @@
 
   public:
     /* Reads data from this object.  */
-    int get_8(uint32_type address, function_code) const;
-    uint16_type get_16(uint32_type address, function_code) const;
+    int get_8(uint32_type address, function_code) const throw();
+    uint16_type get_16(uint32_type address, function_code) const throw();
 
     /* Writes data to this object.  */
-    void put_8(uint32_type address, int, function_code);
-    void put_16(uint32_type address, uint16_type, function_code);
+    void put_8(uint32_type address, int, function_code) throw();
+    void put_16(uint32_type address, uint16_type, function_code) throw();
 
   public:
     /* Returns true if VDISP interrupts are enabled.  */
@@ -318,12 +320,12 @@
 
   public:
     /* Reads data from this object.  */
-    int get_8(uint32_type address, function_code) const;
-    uint16_type get_16(uint32_type address, function_code) const;
+    int get_8(uint32_type address, function_code) const throw();
+    uint16_type get_16(uint32_type address, function_code) const throw();
 
     /* Writes data to this object.  */
-    void put_8(uint32_type address, int, function_code);
-    void put_16(uint32_type address, uint16_type, function_code);
+    void put_8(uint32_type address, int, function_code) throw();
+    void put_16(uint32_type address, uint16_type, function_code) throw();
 
   public:
     /* Checks if text colors are modified.  This function may be
@@ -346,12 +348,12 @@
 
   public:
     /* Reads data from this object.  */
-    int get_8(uint32_type address, function_code) const;
-    uint16_type get_16(uint32_type address, function_code) const;
+    int get_8(uint32_type address, function_code) const throw();
+    uint16_type get_16(uint32_type address, function_code) const throw();
 
     /* Writes data to this object.  */
-    void put_8(uint32_type address, int, function_code);
-    void put_16(uint32_type address, uint16_type, function_code);
+    void put_8(uint32_type address, int, function_code) throw();
+    void put_16(uint32_type address, uint16_type, function_code) throw();
 
   public:
     /* Installs IOCS calls on the DMAC.  */
@@ -372,12 +374,12 @@
 
   public:
     /* Reads data from this object.  */
-    int get_8(uint32_type address, function_code) const;
-    uint16_type get_16(uint32_type address, function_code) const;
+    int get_8(uint32_type address, function_code) const throw();
+    uint16_type get_16(uint32_type address, function_code) const throw();
 
     /* Writes data to this object.  */
-    void put_8(uint32_type address, int, function_code);
-    void put_16(uint32_type address, uint16_type, function_code);
+    void put_8(uint32_type address, int, function_code) throw();
+    void put_16(uint32_type address, uint16_type, function_code) throw();
   };
 
   /* MFP input/output port memory.  This memory is mapped to the
@@ -386,12 +388,12 @@
   {
   public:
     /* Reads data from this object.  */
-    int get_8(uint32_type address, function_code) const;
-    uint16_type get_16(uint32_type address, function_code) const;
+    int get_8(uint32_type address, function_code) const throw();
+    uint16_type get_16(uint32_type address, function_code) const throw();
 
     /* Writes data to this object.  */
-    void put_8(uint32_type address, int, function_code);
-    void put_16(uint32_type address, uint16_type, function_code);
+    void put_8(uint32_type address, int, function_code) throw();
+    void put_16(uint32_type address, uint16_type, function_code) throw();
   };
 
   /* System ports memory.  This memory is mapped to the address range
@@ -400,12 +402,12 @@
   {
   public:
     /* Reads data from this object.  */
-    int get_8(uint32_type address, function_code) const;
-    uint16_type get_16(uint32_type address, function_code) const;
+    int get_8(uint32_type address, function_code) const throw();
+    uint16_type get_16(uint32_type address, function_code) const throw();
 
     /* Writes data to this object.  */
-    void put_8(uint32_type address, int, function_code);
-    void put_16(uint32_type address, uint16_type, function_code);
+    void put_8(uint32_type address, int, function_code) throw();
+    void put_16(uint32_type address, uint16_type, function_code) throw();
   };
 
   /* OPM input/output port memory.  */
@@ -434,12 +436,12 @@
 
   public:
     /* Reads data from this object.  */
-    int get_8(uint32_type address, function_code) const;
-    uint16_type get_16(uint32_type address, function_code) const;
+    int get_8(uint32_type address, function_code) const throw();
+    uint16_type get_16(uint32_type address, function_code) const throw();
 
     /* Writes data to this object.  */
-    void put_8(uint32_type address, int, function_code);
-    void put_16(uint32_type address, uint16_type, function_code);
+    void put_8(uint32_type address, int, function_code) throw();
+    void put_16(uint32_type address, uint16_type, function_code) throw();
 
   public:
     int status() const {return _status;}
@@ -462,12 +464,12 @@
   {
   public:
     /* Reads data from this object.  */
-    int get_8(uint32_type address, function_code) const;
-    uint16_type get_16(uint32_type address, function_code) const;
+    int get_8(uint32_type address, function_code) const throw();
+    uint16_type get_16(uint32_type address, function_code) const throw();
 
     /* Writes data to this object.  */
-    void put_8(uint32_type address, int value, function_code);
-    void put_16(uint32_type address, uint16_type value, function_code);
+    void put_8(uint32_type address, int value, function_code) throw();
+    void put_16(uint32_type address, uint16_type value, function_code) throw();
 
   public:
     /* Installs IOCS calls on this ADPCM chip.  */
@@ -480,12 +482,12 @@
   {
   public:
     /* Reads data from this object.  */
-    int get_8(uint32_type address, function_code) const;
-    uint16_type get_16(uint32_type address, function_code) const;
+    int get_8(uint32_type address, function_code) const throw();
+    uint16_type get_16(uint32_type address, function_code) const throw();
 
     /* Writes data to this object.  */
-    void put_8(uint32_type address, int value, function_code);
-    void put_16(uint32_type address, uint16_type value, function_code);
+    void put_8(uint32_type address, int value, function_code) throw();
+    void put_16(uint32_type address, uint16_type value, function_code) throw();
 
   public:
     /* Installs IOCS calls on this ADPCM chip.  */
@@ -528,12 +530,12 @@
 
   public:
     /* Reads data from this object.  */
-    int get_8(uint32_type address, function_code) const;
-    uint16_type get_16(uint32_type address, function_code) const;
+    int get_8(uint32_type address, function_code) const throw();
+    uint16_type get_16(uint32_type address, function_code) const throw();
 
     /* Writes data to this object.  */
-    void put_8(uint32_type address, int, function_code);
-    void put_16(uint32_type address, uint16_type, function_code);
+    void put_8(uint32_type address, int, function_code) throw();
+    void put_16(uint32_type address, uint16_type, function_code) throw();
 
   public:
     /* Installs IOCS calls on the first COM port and the mouse.  */
@@ -572,12 +574,12 @@
   {
   public:
     /* Reads data from this object.  */
-    int get_8(uint32_type address, function_code) const;
-    uint16_type get_16(uint32_type address, function_code) const;
+    int get_8(uint32_type address, function_code) const throw();
+    uint16_type get_16(uint32_type address, function_code) const throw();
 
     /* Writes data to this object.  */
-    void put_8(uint32_type address, int, function_code);
-    void put_16(uint32_type address, uint16_type, function_code);
+    void put_8(uint32_type address, int, function_code) throw();
+    void put_16(uint32_type address, uint16_type, function_code) throw();
   };
 
   /* Sprite controller memory.  */
@@ -585,12 +587,12 @@
   {
   public:
     /* Reads data from this object.  */
-    int get_8(uint32_type address, function_code) const;
-    uint16_type get_16(uint32_type address, function_code) const;
+    int get_8(uint32_type address, function_code) const throw();
+    uint16_type get_16(uint32_type address, function_code) const throw();
 
     /* Writes data to this object.  */
-    void put_8(uint32_type address, int, function_code);
-    void put_16(uint32_type address, uint16_type, function_code);
+    void put_8(uint32_type address, int, function_code) throw();
+    void put_16(uint32_type address, uint16_type, function_code) throw();
   };
 
   /* SRAM.  */
@@ -605,12 +607,12 @@
 
   public:
     /* Reads data from this object.  */
-    int get_8(uint32_type address, function_code) const;
-    uint16_type get_16(uint32_type address, function_code) const;
+    int get_8(uint32_type address, function_code) const throw();
+    uint16_type get_16(uint32_type address, function_code) const throw();
 
     /* Writes data to this object.  */
-    void put_8(uint32_type address, int, function_code);
-    void put_16(uint32_type address, uint16_type, function_code);
+    void put_8(uint32_type address, int, function_code) throw();
+    void put_16(uint32_type address, uint16_type, function_code) throw();
   };
 
   /* Font ROM.  */
@@ -642,12 +644,12 @@
     
   public:
     /* Reads data from this object.  */
-    int get_8(uint32_type address, function_code) const;
-    uint16_type get_16(uint32_type address, function_code) const;
+    int get_8(uint32_type address, function_code) const throw();
+    uint16_type get_16(uint32_type address, function_code) const throw();
 
     /* Writes data to this object.  */
-    void put_8(uint32_type address, int, function_code);
-    void put_16(uint32_type address, uint16_type, function_code);
+    void put_8(uint32_type address, int, function_code) throw();
+    void put_16(uint32_type address, uint16_type, function_code) throw();
 
   public:
     /* Installs IOCS calls on the system font.  */
