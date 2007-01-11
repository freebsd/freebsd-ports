--- src/EpochClockModel.hpp.orig	Thu Jan 11 21:39:06 2007
+++ src/EpochClockModel.hpp	Thu Jan 11 21:39:26 2007
@@ -67,7 +67,7 @@
                       PRNMode mode = ALWAYS)
          :ObsClockModel(sigma, elmask, mode){}
 
-      virtual double EpochClockModel::getOffset(const gpstk::DayTime& t) const
+      virtual double getOffset(const gpstk::DayTime& t) const
          throw(gpstk::InvalidArgumentException) 
       {
          if (t!=time) 
@@ -92,7 +92,7 @@
 
       // An unchecked accessor for programs that don't need the generic
       // interface
-      double EpochClockModel::getOffset() const
+      double getOffset() const
          throw() {return clkc;};
 
       bool isOffsetValid() const 
