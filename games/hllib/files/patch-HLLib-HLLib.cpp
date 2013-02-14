--- ../orig/HLLib/HLLib.cpp	2010-11-01 19:45:14.000000000 -0200
+++ ./HLLib/HLLib.cpp	2013-02-11 17:56:51.284213443 -0200
@@ -153,6 +153,8 @@
 	case HL_PACKAGE_BOUND:
 		*pValue = pPackage != 0;
 		return hlTrue;
+	default:
+		;
 	}
 
 	return hlFalse;
@@ -171,6 +173,8 @@
 	case HL_FORCE_DEFRAGMENT:
 		bForceDefragment = bValue;
 		break;
+	default:
+		;
 	}
 }
 
@@ -533,6 +537,8 @@
 	case HL_PROC_DEFRAGMENT_PROGRESS_EX:
 		pDefragmentProgressExProc = (PDefragmentProgressExProc)pValue;
 		break;
+	default:
+		;
 	}
 }
 
Only in ./HLLib: HLLib.cpp.orig
diff -ru ../orig/HLLib/Makefile ./HLLib/Makefile
