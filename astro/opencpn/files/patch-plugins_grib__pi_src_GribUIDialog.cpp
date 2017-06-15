$NetBSD: patch-plugins_grib_pi_src_GribUIDialog.cpp,v 1.1 2016/06/16 15:52:56 bouyer Exp $

from https://github.com/OpenCPN/OpenCPN/pull/662
fix grib plugin timeline request from crashing when no grib file is loaded

--- plugins/grib_pi/src/GribUIDialog.cpp.orig	2016-06-25 12:26:20 UTC
+++ plugins/grib_pi/src/GribUIDialog.cpp
@@ -1251,11 +1251,14 @@ wxDateTime GRIBUICtrlBar::TimelineTime()
         int tl = (m_TimeLineHours == 0) ? 0 : m_sTimeline->GetValue();
         int stepmin = m_OverlaySettings.GetMinFromIndex(m_OverlaySettings.m_SlicesPerUpdate);
         return MinTime() + wxTimeSpan( tl * stepmin / 60, (tl * stepmin) % 60 );
-    } else {
-        ArrayOfGribRecordSets *rsa = m_bGRIBActiveFile->GetRecordSetArrayPtr();
-        int index = m_cRecordForecast->GetCurrentSelection() < 1 ? 0 : m_cRecordForecast->GetCurrentSelection();
-        return rsa->Item(index).m_Reference_Time;
     }
+    
+    ArrayOfGribRecordSets *rsa = m_bGRIBActiveFile->GetRecordSetArrayPtr();
+    int index = m_cRecordForecast->GetCurrentSelection() < 1 ? 0 : m_cRecordForecast->GetCurrentSelection();
+    if(rsa && index<rsa->GetCount())
+        return rsa->Item(index).m_Reference_Time;        
+
+    return wxDateTime::Now();
 }
 
 wxDateTime GRIBUICtrlBar::MinTime()
@@ -1265,7 +1268,7 @@ wxDateTime GRIBUICtrlBar::MinTime()
         GribRecordSet &first = rsa->Item(0);
         return first.m_Reference_Time;
     }
-    return wxDateTime(0.0);
+    return wxDateTime::Now();
 }
 
 GribTimelineRecordSet* GRIBUICtrlBar::GetTimeLineRecordSet(wxDateTime time)
