--- common/Persistent.h.orig	2007-11-13 22:33:34.000000000 +0100
+++ common/Persistent.h	2007-11-13 22:33:49.000000000 +0100
@@ -47,9 +47,9 @@
 	CPersistent(const char *uniqueName, kClassPersistent pclass);
 	virtual ~CPersistent();
 
-	virtual unsigned int SizeOf(void) const = 0L;
-	virtual const void *GetData(void) const = 0L;
-	virtual void SetData(const void *ptr, unsigned int size) = 0L;
+	virtual unsigned int SizeOf(void) const = 0;
+	virtual const void *GetData(void) const = 0;
+	virtual void SetData(const void *ptr, unsigned int size) = 0;
 		// virtual access
 	
 	static void SaveAll(void);
