--- src/SALOME_PY/SalomePy.cxx.orig	2010-06-17 12:55:19.000000000 -0230
+++ src/SALOME_PY/SalomePy.cxx	2012-09-13 17:12:24.000000000 -0230
@@ -205,8 +205,9 @@
     SVTK_ViewWindow* aVTKViewWindow = 
       ::GetVTKViewWindow( myCreate ? __Create : __FindOrCreate );
     if( aVTKViewWindow && aPyClass ) {
-      vtkRenderer* aVTKObject = aVTKViewWindow->getRenderer();
-      myResult = PyVTKObject_New( aPyClass, aVTKObject );
+      PyObject* aVTKObject = (PyObject*)aVTKViewWindow->getRenderer();
+      vtkObjectBase *vtk_ptr;
+      myResult = PyVTKObject_New( aPyClass, aVTKObject, vtk_ptr );
     }
   }
 };
@@ -254,8 +255,9 @@
     SVTK_ViewWindow* aVTKViewWindow = 
       ::GetVTKViewWindow( myCreate ? __Create : __FindOrCreate );
     if( aVTKViewWindow && aPyClass ) {
-      vtkRenderWindow* aVTKObject = aVTKViewWindow->getRenderWindow();
-      myResult = PyVTKObject_New( aPyClass, aVTKObject );
+      PyObject* aVTKObject = (PyObject*)aVTKViewWindow->getRenderWindow();
+      vtkObjectBase *vtk_ptr;
+      myResult = PyVTKObject_New( aPyClass, aVTKObject, vtk_ptr );
     }
   }
 };
@@ -303,8 +305,9 @@
     SVTK_ViewWindow* aVTKViewWindow = 
       ::GetVTKViewWindow( myCreate ? __Create : __FindOrCreate );
     if( aVTKViewWindow && aPyClass ) {
-      vtkRenderWindowInteractor* aVTKObject = aVTKViewWindow->getInteractor();
-      myResult = PyVTKObject_New( aPyClass, aVTKObject );
+      PyObject* aVTKObject = (PyObject*)aVTKViewWindow->getInteractor();
+      vtkObjectBase *vtk_ptr;
+      myResult = PyVTKObject_New( aPyClass, aVTKObject, vtk_ptr );
     }
   }
 };
