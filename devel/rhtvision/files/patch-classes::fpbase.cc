--- classes/fpbase.cc.orig	Wed Oct 10 02:05:52 2001
+++ classes/fpbase.cc	Fri Jun  7 04:35:14 2002
@@ -22,7 +22,7 @@
 
 fpbase::fpbase()
 {
- buf=new filebuf();
+ buf=new CLY_filebuf();
  pstream::init(buf);
 }
 
@@ -34,7 +34,7 @@
 
 fpbase::fpbase( const char *name, CLY_OpenModeT omode, int prot )
 {
- buf=new filebuf();
+ buf=new CLY_filebuf();
  open(name,omode,prot);
  pstream::init(buf);
 }
@@ -93,4 +93,51 @@
 {
  return buf;
 }
+
+#ifdef CLY_DefineSpecialFileBuf
+// gcc 3.1 specific
+CLY_filebuf *CLY_filebuf::open(FILE *f, ios_base::openmode mode)
+{
+ CLY_filebuf *ret=NULL;
+ if (!this->is_open())
+   {
+    _M_file.sys_open(f,mode);
+    if (this->is_open())
+      {
+       _M_allocate_internal_buffer();
+       _M_mode=mode;
+       
+       // For time being, set both (in/out) sets  of pointers.
+       _M_set_indeterminate();
+       if ((mode & ios_base::ate) &&
+           this->seekoff(0,ios_base::end,mode)<0)
+          this->close();
+       ret=this;
+      }
+   }
+ return ret;
+}
+
+CLY_filebuf *CLY_filebuf::open(int h, ios_base::openmode mode)
+{
+ CLY_filebuf *ret=NULL;
+ if (!this->is_open())
+   {
+    _M_file.sys_open(h,mode,false);
+    if (this->is_open())
+      {
+       _M_allocate_internal_buffer();
+       _M_mode=mode;
+       
+       // For time being, set both (in/out) sets  of pointers.
+       _M_set_indeterminate();
+       if ((mode & ios_base::ate) &&
+           this->seekoff(0,ios_base::end,mode)<0)
+          this->close();
+       ret=this;
+      }
+   }
+ return ret;
+}
+#endif // CLY_DefineSpecialFileBuf
 
