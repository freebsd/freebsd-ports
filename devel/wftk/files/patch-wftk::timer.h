--- wftk/timer.h.orig	Sat May  7 23:58:33 2005
+++ wftk/timer.h	Sun May  8 00:03:52 2005
@@ -184,7 +184,7 @@
   static std::set<Timer*> runningTimers_;
 
   typedef Application::FloatingEvent<Timer> BaseEvent;
-  friend class BaseEvent;
+  friend class Application::FloatingEvent<Timer>;
   class Event : public BaseEvent
   {
    public:
