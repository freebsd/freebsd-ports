--- wftk/poll.h.orig	Sun May  8 00:11:35 2005
+++ wftk/poll.h	Sun May  8 00:11:51 2005
@@ -115,7 +115,7 @@
   virtual void event(int mask) = 0;
 
   typedef Application::FloatingEvent<Poll> BaseEvent;
-  friend class BaseEvent;
+  friend class Application::FloatingEvent<Poll>;
   class Event : public BaseEvent
   {
    public:
