*** examples/meshViewer/Viewer.cpp.orig	Sat Oct 29 15:58:21 2005
--- examples/meshViewer/Viewer.cpp	Sat Oct 29 16:08:13 2005
***************
*** 41,47 ****
    scene.load(name);
  
    // QGLViewer settings.
!   setSceneBoundingBox(scene.getBBoxMin().f_data(), scene.getBBoxMax().f_data());
    setSceneRadius(2.0f*sceneRadius());
    showEntireScene(); 
  }
--- 41,50 ----
    scene.load(name);
  
    // QGLViewer settings.
!   setSceneBoundingBox(
!     qglviewer::Vec(scene.getBBoxMin()[0],scene.getBBoxMin()[1],scene.getBBoxMin()[2]), 
!     qglviewer::Vec(scene.getBBoxMax()[0],scene.getBBoxMax()[1],scene.getBBoxMax()[2])
!   );
    setSceneRadius(2.0f*sceneRadius());
    showEntireScene(); 
  }
