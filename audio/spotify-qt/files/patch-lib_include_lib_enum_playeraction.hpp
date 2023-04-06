--- lib/include/lib/enum/playeraction.hpp.orig	2023-03-25 10:23:49 UTC
+++ lib/include/lib/enum/playeraction.hpp
@@ -63,3 +63,9 @@ namespace lib
 		transferring_playback,
 	};
 }
+
+namespace std {
+	template <> struct hash<lib::player_action> {
+		size_t operator() (const lib::player_action &t) const { return size_t(t); }
+	};
+}
