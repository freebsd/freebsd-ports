--- Sources/Core/IOData/Generic/datafile_inputprovider.h.orig	2006-10-27 01:55:01 UTC
+++ Sources/Core/IOData/Generic/datafile_inputprovider.h
@@ -144,7 +144,7 @@ protected:
 			cache.insert(
-				std::make_pair<std::string const, std::pair<int, int> >(
+				std::make_pair(
 				resource_id,
-				std::make_pair<int,int>(data_pos, data_size)));
+				std::make_pair(data_pos, data_size)));
 		}
 
 	private:
