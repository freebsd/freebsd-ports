--- utilities/decimator.cpp.orig
+++ utilities/decimator.cpp
@@ -67,8 +67,8 @@ bool	downDecimator::doDecimate (DSPFLOAT
  */
 	this -> inSamplerate	= inSamplerate;
 	this -> outSamplerate	= outSamplerate;
-	inperiod		= (int64_t)(100000000000) / inSamplerate; 
-	outperiod		= (int64_t)(100000000000) / outSamplerate;
+	inperiod		= (int64_t)(100000000000LL) / inSamplerate; 
+	outperiod		= (int64_t)(100000000000LL) / outSamplerate;
 	oldinsampleTime		= 0;
 	currentinsampleTime	= 0;
 	oldinsampleValue	= 0;
