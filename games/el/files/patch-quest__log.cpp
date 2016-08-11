--- quest_log.cpp.orig	2014-01-06 13:53:40 UTC
+++ quest_log.cpp
@@ -85,7 +85,7 @@ class Quest_Title_Request
 		Uint16 get_id(void) const { return id; }
 		void request(void);
 		bool been_requested(void) const { return requested; }
-		bool is_too_old(void) const { return (abs(SDL_GetTicks() - request_time) > 5000); }
+		bool is_too_old(void) const { return (abs((Sint32)(SDL_GetTicks() - request_time)) > 5000); }
 	private:
 		Uint16 id;
 		Uint32 request_time;
