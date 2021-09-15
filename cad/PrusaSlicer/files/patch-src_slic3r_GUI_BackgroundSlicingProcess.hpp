--- src/slic3r/GUI/BackgroundSlicingProcess.hpp.orig	2021-08-14 22:52:55 UTC
+++ src/slic3r/GUI/BackgroundSlicingProcess.hpp
@@ -213,7 +213,7 @@ class BackgroundSlicingProcess (private)
 	State 						m_state = STATE_INITIAL;
 
     PrintState<BackgroundSlicingProcessStep, bspsCount>   	m_step_state;
-    mutable tbb::mutex                      				m_step_state_mutex;
+    mutable std::mutex                      				m_step_state_mutex;
 	bool                set_step_started(BackgroundSlicingProcessStep step);
 	void                set_step_done(BackgroundSlicingProcessStep step);
 	bool 				is_step_done(BackgroundSlicingProcessStep step) const;
