--- storage/connect/filamap.h.orig	2014-09-25 00:29:47.000000000 +0200
+++ storage/connect/filamap.h	2014-09-27 11:44:39.000000000 +0200
@@ -47,7 +47,7 @@
   virtual void  Rewind(void);
 
  protected:
-  virtual int   InitDelete(PGLOBAL g, int fpos, int spos);
+  virtual int   InitDelete(PGLOBAL g, uintptr_t fpos, uintptr_t spos);
 
   // Members
   char *Memory;               // Pointer on file mapping view.
@@ -104,13 +104,13 @@
   virtual int   MaxBlkSize(PGLOBAL g, int s)
                 {return TXTFAM::MaxBlkSize(g, s);}
   virtual bool  SetPos(PGLOBAL g, int recpos);
-  virtual int   GetNextPos(void) {return (int)Fpos + Nrec;}
+  virtual int   GetNextPos(void) {return (uintptr_t)Fpos + Nrec;}
   virtual bool  DeferReading(void) {return false;}
   virtual int   ReadBuffer(PGLOBAL g);
   virtual int   WriteBuffer(PGLOBAL g);
 
  protected:
-  virtual int   InitDelete(PGLOBAL g, int fpos, int spos);
+  virtual int   InitDelete(PGLOBAL g, uintptr_t fpos, uintptr_t spos);
 
   // No additional members
   }; // end of class MPXFAM
