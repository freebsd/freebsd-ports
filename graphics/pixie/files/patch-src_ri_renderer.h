--- src/ri/renderer.h.orig
+++ src/ri/renderer.h
@@ -107,7 +107,7 @@
 class	CRendererContext : public CRiInterface {
 public:
 
-						CRendererContext(char *ribName=NULL,char *netString=NULL);
+						CRendererContext(char *ribName=(char*)NULL,char *netString=(char*)NULL);
 						~CRendererContext();
 
 	///////////////////////////////////////////////////////////////////////
@@ -253,7 +253,7 @@
 	CEnvironment		*environmentLoad(const char *,TSearchpath *,float *);	// Load a new environment map
 
 																				// Delayed object junk
-	void				processDelayedObject(CDelayedObject *,void	(*subdivisionFunction)(char *,float),char *,const float *,const float *,CRay *ray = NULL);
+	void				processDelayedObject(CDelayedObject *,void	(*subdivisionFunction)(char *,float),char *,const float *,const float *,CRay *ray = (CRay*)NULL);
 
 	void				addObject(CObject *);									// Add an object into the scene
 	void				addInstance(void *);									// Add an instance into the scene
@@ -267,11 +267,11 @@
 	CVariable			*retrieveVariable(const char *);
 
 																				// Locate (download) a file
-	int					locateFileEx(char *,const char *,const char *extension=NULL,TSearchpath *search=NULL);
-	int					locateFile(char *,const char *,TSearchpath *search=NULL);
+	int					locateFileEx(char *,const char *,const char *extension=(char*)NULL,TSearchpath *search=(TSearchpath *)NULL);
+	int					locateFile(char *,const char *,TSearchpath *search=(TSearchpath *)NULL);
 
 																				// Open (download) a file
-	FILE				*openFile(const char *,const char *,const char *extension=NULL,TSearchpath *search=NULL);
+	FILE				*openFile(const char *,const char *,const char *extension=(char*)NULL,TSearchpath *search=(TSearchpath *)NULL);
 
 																				// The following functions are about texture management and are implemented in texture.cpp
 	void				rendererThread(void *);
