--- gtk2_ardour/automation_selectable.h.orig	2009-02-24 12:37:42 UTC
+++ gtk2_ardour/automation_selectable.h
@@ -36,7 +36,7 @@ struct AutomationSelectable : public Sel
     AutomationSelectable (nframes_t s, nframes_t e, double l, double h, TimeAxisView& atv)
 	    : start (s), end (e), low_fract (l), high_fract (h), track (atv) {}
 
-    bool operator== (const AutomationSelectable& other) {
+    bool operator== (const AutomationSelectable& other) const {
 	    return start == other.start &&
 		    end == other.end &&
 		    low_fract == other.low_fract &&
