*** examples/simplifiedMeshViewer/Viewer.cpp.orig	Sat Oct 29 15:58:21 2005
--- examples/simplifiedMeshViewer/Viewer.cpp	Sat Oct 29 16:12:41 2005
***************
*** 41,47 ****
    scene.load(name);
  
    // QGLViewer settings.
!   setSceneBoundingBox(scene.getBBoxMin(), scene.getBBoxMax());
    showEntireScene(); 
  }
  
--- 41,50 ----
    scene.load(name);
  
    // QGLViewer settings.
!   setSceneBoundingBox(
!     qglviewer::Vec(scene.getBBoxMin()[0],scene.getBBoxMin()[1],scene.getBBoxMin()[2]), 
!     qglviewer::Vec(scene.getBBoxMax()[0],scene.getBBoxMax()[1],scene.getBBoxMax()[2])
!   );
    showEntireScene(); 
  }
  
