--- libs/shadervm/dsoshadeops.cpp.orig	2012-02-20 18:12:04.000000000 +0300
+++ libs/shadervm/dsoshadeops.cpp	2012-02-20 18:12:22.000000000 +0300
@@ -101,13 +101,13 @@
 				// If the path points to a directory, we add each library in the
 				// named directory to the list of DSO candidates.
 				std::vector<std::string> files = Glob(
-						((*path)/"*" SHARED_LIBRARY_SUFFIX).file_string() );
+						((*path)/"*" SHARED_LIBRARY_SUFFIX).string() );
 				m_DSOPathList.insert(m_DSOPathList.end(), files.begin(), files.end());
 			}
 			else
 			{
 				// else add the file itself.
-				m_DSOPathList.push_back(path->file_string());
+				m_DSOPathList.push_back(path->string());
 			}
 		}
 		catch(boost::filesystem::filesystem_error& /*e*/)
