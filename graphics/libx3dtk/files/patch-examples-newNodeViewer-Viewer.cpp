*** examples/newNodeViewer/Viewer.cpp.orig	Sat Oct 29 15:58:21 2005
--- examples/newNodeViewer/Viewer.cpp	Sat Oct 29 16:02:06 2005
***************
*** 48,54 ****
    cout << endl;
    
    // QGLViewer settings.
!   setSceneBoundingBox(scene.getBBoxMin().f_data(), scene.getBBoxMax().f_data());
    showEntireScene();
  }
  
--- 48,57 ----
    cout << endl;
    
    // QGLViewer settings.
!   setSceneBoundingBox(
!     qglviewer::Vec(scene.getBBoxMin()[0],scene.getBBoxMin()[1],scene.getBBoxMin()[2]), 
!     qglviewer::Vec(scene.getBBoxMax()[0],scene.getBBoxMax()[1],scene.getBBoxMax()[2])
!   );
    showEntireScene();
  }
  
