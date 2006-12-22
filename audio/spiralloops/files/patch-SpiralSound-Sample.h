--- SpiralSound/Sample.h.orig	Fri Dec 22 18:39:01 2006
+++ SpiralSound/Sample.h	Fri Dec 22 18:39:30 2006
@@ -63,13 +63,13 @@
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
@@ -79,7 +79,7 @@
 		m_Data[i]=(short)v;
 	}	
 	
-	inline Sample &Sample::operator=(const Sample &rhs)
+	inline Sample &operator=(const Sample &rhs)
 	{
 		Allocate(rhs.GetLength());		
 		memcpy(m_Data,rhs.GetBuffer(),GetLengthInBytes());
