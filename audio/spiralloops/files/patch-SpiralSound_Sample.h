--- SpiralSound/Sample.h.orig	2001-04-19 20:48:13 UTC
+++ SpiralSound/Sample.h
@@ -21,6 +21,7 @@
 
 #include <assert.h>
 #include <iostream>
+#include <cstring>
 #include "SpiralInfo.h"
 
 static const unsigned short UMAX_LEV  = 65535;
@@ -63,13 +64,13 @@ public:
 	void Shrink(int Length);
 	void CropTo(int NewLength);
 
-	inline short &Sample::operator[](int i) const
+	inline short &operator[](int i) const
 	{
 		assert(i>=0 && i<m_Length);
 		return m_Data[i];
 	}
 
-	inline void Sample::Set(int i, long int v) 
+	inline void Set(int i, long int v) 
 	{	
 		assert(i>=0 && i<m_Length);
 		// clip
@@ -79,7 +80,7 @@ public:
 		m_Data[i]=(short)v;
 	}	
 	
-	inline Sample &Sample::operator=(const Sample &rhs)
+	inline Sample &operator=(const Sample &rhs)
 	{
 		Allocate(rhs.GetLength());		
 		memcpy(m_Data,rhs.GetBuffer(),GetLengthInBytes());
