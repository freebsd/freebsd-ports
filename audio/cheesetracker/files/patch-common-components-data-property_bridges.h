--- common/components/data/property_bridges.h.orig	Wed Apr 11 23:57:19 2007
+++ common/components/data/property_bridges.h	Thu Apr 12 00:02:25 2007
@@ -41,7 +41,7 @@
   */
 
   #define BRIDGE_COPY_VALUE(T) \
-	virtual bool T::copy_value(const Property_Bridge& rvalue) {\
+	virtual bool copy_value(const Property_Bridge& rvalue) {\
 		T* rcast = dynamic_cast<T*>((T*)&rvalue);\
 		if (rcast) {\
 			set(rcast->get());\
