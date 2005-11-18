*** examples/X3DViewer/Viewer.cpp.orig	Sat Oct 29 15:58:21 2005
--- examples/X3DViewer/Viewer.cpp	Sat Oct 29 15:59:38 2005
***************
*** 36,42 ****
    scene.load(name);
    
    // QGLViewer settings
!   setSceneBoundingBox(scene.getBBoxMin().f_data(), scene.getBBoxMax().f_data());
    showEntireScene();
  }
  
--- 36,45 ----
    scene.load(name);
    
    // QGLViewer settings
!   setSceneBoundingBox(
!     qglviewer::Vec(scene.getBBoxMin()[0],scene.getBBoxMin()[1],scene.getBBoxMin()[2]), 
!     qglviewer::Vec(scene.getBBoxMax()[0],scene.getBBoxMax()[1],scene.getBBoxMax()[2])
!   );
    showEntireScene();
  }
  
