--- Source/Engine/hud.h.orig	2012-10-27 08:18:51 UTC
+++ Source/Engine/hud.h
@@ -44,7 +44,7 @@ enum HudMap{
 class AlertMessage {
 	public:
 		AlertMessage( string message, Uint32 start );
-		bool operator ==(const AlertMessage& other) {return (start == other.start) && (message == other.message);}
+		bool operator ==(const AlertMessage& other) const {return (start == other.start) && (message == other.message);}
 		string message;
 		Uint32 start;
 };
