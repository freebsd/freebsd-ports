--- p_unix.h.orig	Tue Feb 17 06:22:27 2004
+++ p_unix.h	Tue Feb 17 06:52:01 2004
@@ -131,6 +131,25 @@
     };
 };
 
+/*************************************************************************
+// FreeBSD/i386
+**************************************************************************/
+
+class PackFreeBSDI386 : public PackLinuxI386
+{
+    typedef PackLinuxI386 super;
+public:
+    PackFreeBSDI386(InputFile *f) : super(f) { }
+    virtual int getFormat() const { return UPX_F_FREEBSD_i386; }
+    virtual const char *getName() const { return "FreeBSD/386"; }
+
+    virtual bool canPack();
+
+protected:
+    virtual const upx_byte *getLoader() const;
+    virtual int getLoaderSize() const;
+};
+
 
 /*************************************************************************
 // solaris/sparc
