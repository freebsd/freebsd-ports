--- ../orig/HLLib/GCFFile.cpp	2010-11-01 20:56:16.000000000 -0200
+++ ./HLLib/GCFFile.cpp	2013-02-11 17:56:51.281214140 -0200
@@ -789,6 +789,8 @@
 					}
 					return hlTrue;
 				}
+				default:
+					;
 			}
 			break;
 		}
@@ -819,9 +821,13 @@
 					}
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
Only in ./HLLib: GCFFile.cpp.orig
diff -ru ../orig/HLLib/HLLib.cpp ./HLLib/HLLib.cpp
