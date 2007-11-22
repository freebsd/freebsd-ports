--- rf/uevent.cpp.orig	2001-09-19 07:13:09.000000000 +0200
+++ rf/uevent.cpp	2007-11-22 20:00:49.000000000 +0100
@@ -196,7 +196,7 @@
 	int(UCmdTarget::*pfni_VP)(void *);
 };
 
-int UEventSendMessage(int wid, int/*UEventType*/ evt, int arg1, void *arg2)
+int UEventSendMessage(int wid, int/*UEventType*/ evt, int arg1, const void *arg2)
 {
 	if(sTurnOffDispatching)
 		return 0;
@@ -320,7 +320,7 @@
 	targets.erase(i);
 }
 
-int UCmdTarget::UDispatchMessage(int/*UEventType*/ evt, int arg1, void *arg2, UDispatchInfo & dispatchInfo)
+int UCmdTarget::UDispatchMessage(int/*UEventType*/ evt, int arg1, const void *arg2, UDispatchInfo & dispatchInfo)
 {
 	const UMSGMAP* themap;
 	const UMSGMAP_ENTRY *entries;
@@ -357,13 +357,13 @@
 		(this->*mmf.pfnV_V)();
 		break;
 	case epV_VP:
-		(this->*mmf.pfnV_VP)(arg2);
+		(this->*mmf.pfnV_VP)((void *)arg2);
 		break;
 	case epV_iVP:
-		(this->*mmf.pfnV_iVP)(arg1, arg2);
+		(this->*mmf.pfnV_iVP)(arg1, (void *)arg2);
 		break;
 	case epV_IVP:
-		(this->*mmf.pfnV_iVP)(UHIWORD(arg1), arg2);
+		(this->*mmf.pfnV_iVP)(UHIWORD(arg1), (void *)arg2);
 		break;
 	case epV_i:
 		(this->*mmf.pfnV_i)(arg1);
@@ -375,10 +375,10 @@
 		(this->*mmf.pfnV_ii)(ULOWORD(arg1), UHIWORD(arg1));
 		break;
 	case epV_iii:
-		(this->*mmf.pfnV_iii)(ULOWORD(arg1), UHIWORD(arg1), (int)arg2);
+		(this->*mmf.pfnV_iii)(ULOWORD(arg1), UHIWORD(arg1), (size_t)arg2);
 		break;
 	case epV_iiVP:
-		(this->*mmf.pfnV_iiVP)(ULOWORD(arg1), UHIWORD(arg1), arg2);
+		(this->*mmf.pfnV_iiVP)(ULOWORD(arg1), UHIWORD(arg1), (void *)arg2);
 		break;
 	case epi_ii:
 		res = (this->*mmf.pfni_ii)(ULOWORD(arg1), UHIWORD(arg1));
@@ -390,10 +390,10 @@
 		res = (this->*mmf.pfni_V)();
 		break;
 	case epi_iVP:
-		res = (this->*mmf.pfni_iVP)(arg1, arg2);
+		res = (this->*mmf.pfni_iVP)(arg1, (void *)arg2);
 		break;
 	case epi_VP:
-		res = (this->*mmf.pfni_VP)(arg2);
+		res = (this->*mmf.pfni_VP)((void *)arg2);
 		break;
 	default:
 		UAppConsole("Unknown event cast : %d\n", entries->nSig);
