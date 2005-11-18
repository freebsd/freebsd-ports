*** examples/glNormalViewer/Viewer.cpp.orig	Sat Oct 29 15:58:21 2005
--- examples/glNormalViewer/Viewer.cpp	Sat Oct 29 16:01:33 2005
***************
*** 57,63 ****
    scene.load(name, false);
  
    // QGLViewer settings
!   setSceneBoundingBox(scene.getBBoxMin().f_data(), scene.getBBoxMax().f_data());
    showEntireScene();
  }
  
--- 57,66 ----
    scene.load(name, false);
  
    // QGLViewer settings
!   setSceneBoundingBox(
!     qglviewer::Vec(scene.getBBoxMin()[0],scene.getBBoxMin()[1],scene.getBBoxMin()[2]), 
!     qglviewer::Vec(scene.getBBoxMax()[0],scene.getBBoxMax()[1],scene.getBBoxMax()[2])
!   );
    showEntireScene();
  }
  
