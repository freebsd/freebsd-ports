--- cmn/intel.h.orig	2012-05-27 06:52:31.000000000 +0900
+++ cmn/intel.h	2012-05-27 06:53:11.000000000 +0900
@@ -123,7 +123,7 @@
 // Class Definitions.
 class Intel {
  public:
-  Intel(WorldP w,LocatorP l,char *name,
+  Intel(WorldP w,LocatorP l,const char *name,
        	const IntelOptions *ops,ITmask opMask); 
   /* EFFECTS: Create a new intel with the options specified in opMakse that are
      in ops.  ops will never be referenced if opMask is ITnone.  lives now
@@ -293,7 +293,7 @@
 // Simply buffers input from a user interface.
 class Human: public Intel {
  public: 
-  Human(WorldP w,LocatorP l,char *name,int lives,
+  Human(WorldP w,LocatorP l,const char *name,int lives,
         int *sharedLives,ColorNum colorNum);
   /* NOTE: Uses all default options.  intelOptions should be meaningless for 
      a human. If "sharedLives" is non-null, ignore "lives" and share the lives. */
@@ -346,7 +346,7 @@
 
 class Machine: public Intel {
 public:
-  Machine(WorldP w,LocatorP l,char *name,
+  Machine(WorldP w,LocatorP l,const char *name,
 	  const IntelOptions *ops,ITmask opMask);
 	  
   virtual IntelId get_master_intel_id();
@@ -464,7 +464,7 @@
 
 class Enemy: public Machine {
 public:
-  Enemy(WorldP w,LocatorP l,char *name,
+  Enemy(WorldP w,LocatorP l,const char *name,
 	const IntelOptions *ops,ITmask opMask);
 
   static void set_reflexes_time(int time) {reflexesTime = time;}
@@ -491,7 +491,7 @@
 
 class Neutral: public Machine {
 public:
-  Neutral(WorldP w,LocatorP l,char *name,
+  Neutral(WorldP w,LocatorP l,const char *name,
 	const IntelOptions *ops,ITmask opMask);
 	  
   virtual Boolean is_enemy();
@@ -502,7 +502,7 @@
 
 class SealIntel: public Neutral {
 public:
-  SealIntel(WorldP w,LocatorP l,char *name,const Id &homeId);
+  SealIntel(WorldP w,LocatorP l,const char *name,const Id &homeId);
   
   virtual Boolean is_seal_intel();
 
@@ -522,7 +522,7 @@
 
 class DoppelIntel: public Neutral {
 public:
-	DoppelIntel(WorldP w,LocatorP l,char *name,
+	DoppelIntel(WorldP w,LocatorP l,const char *name,
     const IntelOptions *ops,ITmask opMask,
 	  IntelP master = NULL);
 	
@@ -572,7 +572,7 @@
 // in choose_strategy() and go_get_em().
 class Pet: public DoppelIntel {
 public:
-  Pet(WorldP w,LocatorP l,char *name,
+  Pet(WorldP w,LocatorP l,const char *name,
 	    const IntelOptions *ops,ITmask opMask,
 	    IntelP master = NULL);
     
@@ -583,7 +583,7 @@
 	IT_WEAPON_{some dir}, or to come back to him if command is IT_WEAPON_CENTER. 
 	This will also set p to be the new master. */
 
-	static char *mode_string(int mode);
+	static const char *mode_string(int mode);
 	/* NOTE: For debugging. */
 
 
