--- IlmImfTest/testOptimizedInterleavePatterns.cpp.orig	2018-08-10 01:34:59 UTC
+++ IlmImfTest/testOptimizedInterleavePatterns.cpp
@@ -226,7 +226,8 @@ bool compare(const FrameBuffer& asRead,
                     writtenHalf=half(i.slice().fillValue);
                 }
 
-                if (writtenHalf.bits()!=readHalf.bits())
+                if (writtenHalf.bits()!=readHalf.bits() &&
+			!(writtenHalf.isNan() && readHalf.isNan()))
                 {
                     if (nonfatal)
                     {
@@ -235,7 +236,8 @@ bool compare(const FrameBuffer& asRead,
                     else
                     {
                         cout << "\n\nerror reading back channel " << i.name() << " pixel " << x << ',' << y << " got " << readHalf << " expected " << writtenHalf << endl;
-                        assert(writtenHalf.bits()==readHalf.bits());
+                        assert(writtenHalf.bits()==readHalf.bits() ||
+			(writtenHalf.isNan() && readHalf.isNan()));
                         exit(1);
                     }
                 }             
