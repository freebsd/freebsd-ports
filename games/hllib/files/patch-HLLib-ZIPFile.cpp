--- ../orig/HLLib/ZIPFile.cpp	2012-09-18 19:51:30.000000000 -0300
+++ ./HLLib/ZIPFile.cpp	2013-02-11 17:56:51.305211203 -0200
@@ -393,9 +393,13 @@
 					delete []lpComment;
 					return hlTrue;
 				}
+				default:
+					;
 			}
 			break;
 		}
+		default:
+			;
 	}
 
 	return hlFalse;
@@ -598,4 +602,4 @@
 	{
 		delete []static_cast<const hlByte *>(static_cast<Streams::CMemoryStream &>(Stream).GetBuffer());
 	}
-}
\ No newline at end of file
+}
Only in ./HLLib: ZIPFile.cpp.orig
