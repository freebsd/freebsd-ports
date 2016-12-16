--- Sources/ptImage.cpp.orig	2016-03-22 03:34:55 UTC
+++ Sources/ptImage.cpp
@@ -40,8 +40,11 @@
 #include <QString>
 #include <QTime>
 
-#include <algorithm>
+#ifdef __GLIBCXX__
 #include <parallel/algorithm>
+#else
+#include <algorithm>
+#endif
 #include <stack>
 
 // std stuff needs to be declared apparently for jpeglib
@@ -1718,7 +1721,7 @@ ptImage* ptImage::ApplyCurve(const ptCur
   if (ChannelMask & 1) Channel.push_back(0);
   if (ChannelMask & 2) Channel.push_back(1);
   if (ChannelMask & 4) Channel.push_back(2);
-  __gnu_parallel::for_each (m_Data.begin(), m_Data.end(), [&](TPixel16 &Pixel) {
+  std::for_each (m_Data.begin(), m_Data.end(), [&](TPixel16 &Pixel) {
     std::for_each (Channel.begin(), Channel.end(), [&](const short &Value){
       Pixel[Value] = Curve->Curve[ Pixel[Value] ];
     });
@@ -1742,7 +1745,7 @@ ptImage* ptImage::ApplyLByHueCurve(const
   // neutral value for a* and b* channel
   const float WPH = 0x8080;
 
-  __gnu_parallel::for_each (m_Data.begin(), m_Data.end(), [&](TPixel16 &Pixel) {
+  std::for_each (m_Data.begin(), m_Data.end(), [&](TPixel16 &Pixel) {
     // Factor by hue
     float ValueA = (float)Pixel[1]-WPH;
     float ValueB = (float)Pixel[2]-WPH;
