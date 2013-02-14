--- ../orig/HLLib/SGAFile.cpp	2012-11-20 20:17:10.000000000 -0200
+++ ./HLLib/SGAFile.cpp	2013-02-11 17:56:51.289212795 -0200
@@ -387,6 +387,8 @@
 						}
 						return hlFalse;
 					}
+					default:
+						;
 				}
 				break;
 			}
@@ -448,9 +450,13 @@
 						}
 						return hlFalse;
 					}
+					default:
+						;
 				}
 				break;
 			}
+			default:
+				;
 		}
 	}
 	return hlFalse;
@@ -624,4 +630,4 @@
 	{
 		delete []static_cast<const hlByte *>(static_cast<Streams::CMemoryStream &>(Stream).GetBuffer());
 	}
-}
\ No newline at end of file
+}
Only in ./HLLib: SGAFile.cpp.orig
diff -ru ../orig/HLLib/SGAFile.h ./HLLib/SGAFile.h
