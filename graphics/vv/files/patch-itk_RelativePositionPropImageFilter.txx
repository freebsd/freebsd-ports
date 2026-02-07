Remove register storage class specifier.

C++17 removed the 'register' keyword which was deprecated in C++11.

--- itk/RelativePositionPropImageFilter.txx.orig	2025-04-17 12:54:38 UTC
+++ itk/RelativePositionPropImageFilter.txx
@@ -365,12 +365,12 @@ namespace itk
 	
     typename TabulationImageType::IndexType start;
 	
-    for(register int i=0;i<ImageDimension;i++)
+    for(int i=0;i<ImageDimension;i++)
       start[i]=0;
 	
     typename TabulationImageType::SizeType size = this->GetInput()->GetLargestPossibleRegion().GetSize();
 	
-    for(register int i=0;i<ImageDimension;i++)
+    for(int i=0;i<ImageDimension;i++)
       size[i]*=2;
 	
     typename TabulationImageType::RegionType region;
@@ -390,7 +390,7 @@ namespace itk
       m_AngleTabulation->GetRequestedRegion().GetIndex();
 	
     typename TabulationImageType::SizeType center = this->GetInput()->GetLargestPossibleRegion().GetSize();
-    for(register int i=0;i<ImageDimension;i++)
+    for(int i=0;i<ImageDimension;i++)
       center[i]-=1;
 		
     VectorType vecttemp;
