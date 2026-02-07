--- src/pfs/pfs.h.orig	2018-02-26 13:58:05 UTC
+++ src/pfs/pfs.h
@@ -141,6 +141,7 @@ namespace pfs
   class TagContainer
     {
     public:
+      virtual ~TagContainer() {};
       /**
        * Get a string tag of the name tagName from the TagContainer.
        * @param tagName name of the tag to retrieve
@@ -187,6 +188,7 @@ namespace pfs
  */
   class Channel : public Array2D {
   public:
+    virtual ~Channel() {};
     /**
      * Gets width of the channel (in pixels).
      * This is a synonym for Array2D::getCols().
@@ -596,7 +598,9 @@ namespace pfs
        */
       Exception( const char* const message )
 	{
-          strcpy( msg, message );
+          const size_t s = sizeof(msg)/sizeof(msg[0]) - 1;
+          strncpy( msg, message, s );
+          msg[s] = '\0';
 	}
 			
       ~Exception() {};
@@ -606,7 +610,7 @@ namespace pfs
        *
        * @return text description of the cause for the exception
        */
-      const char* getMessage()
+      const char* getMessage() const throw()
         {
           return msg;
 	}
