--- src/XESCore/DEMTables.cpp.orig	2018-07-05 06:58:51 UTC
+++ src/XESCore/DEMTables.cpp
@@ -481,6 +481,8 @@ bool	ReadNewTerrainInfo(const vector<str
 				&info.composite_params[4],
 				&info.composite_params[5]) != 23) return false;
 			break;
+		default:
+			break;
 		}
 		
 		info.proj_angle = proj_Down;
