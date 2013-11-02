--- src/win_event.cc.orig	2002-12-16 19:09:54.000000000 +0000
+++ src/win_event.cc
@@ -35,7 +35,7 @@ void win_event::py_signal_connect (PyObj
 	    case DESTROY:
 	    {
 	        set_callback_destroy (
-	        makeFunctor (&Functor0wRet<bool>(), *callback, &py_callback::callback_func0ret));
+	        makeFunctor (new Functor0wRet<bool>(), *callback, &py_callback::callback_func0ret));
 	        break;
 	    }
 	
