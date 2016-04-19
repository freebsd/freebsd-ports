--- cuneiform_src/Kern/rimage/sources/main/cricontrol.cpp.orig	2011-04-19 12:49:57 UTC
+++ cuneiform_src/Kern/rimage/sources/main/cricontrol.cpp
@@ -594,8 +594,8 @@ Bool32 CRIControl::CreateDestinatonDIB(u
 		return FALSE;
 	}
 
-	wNewHeight = (mbMarginsFlag ? abs(mrMargins.rmBottomMarg - mrMargins.rmTopMarg) : mpSourceDIB->GetLinesNumber());
-	wNewWidth = (mbMarginsFlag ? abs(mrMargins.rmLeftMarg - mrMargins.rmRightMarg) : mpSourceDIB->GetLineWidth());
+	wNewHeight = (mbMarginsFlag ? abs((int32_t)(mrMargins.rmBottomMarg - mrMargins.rmTopMarg)) : mpSourceDIB->GetLinesNumber());
+	wNewWidth = (mbMarginsFlag ? abs((int32_t)(mrMargins.rmLeftMarg - mrMargins.rmRightMarg)) : mpSourceDIB->GetLineWidth());
 	mpSourceDIB->GetResolutionDPM( &wXResolution, &wYResolution);
 
 	if ( !mpDestinationDIB->CreateDIBBegin( wNewWidth, wNewHeight, BitCount) )
