*** examples/simpleAnimationViewer/Viewer.cpp.orig	Sat Oct 29 15:58:21 2005
--- examples/simpleAnimationViewer/Viewer.cpp	Sat Oct 29 16:05:47 2005
***************
*** 46,52 ****
    scene.init();
  
    // QGLViewer settings.
!   setSceneBoundingBox(scene.getBBoxMin().f_data(), scene.getBBoxMax().f_data());
    setSceneRadius(2.0f*sceneRadius());
    showEntireScene();
  }
--- 46,55 ----
    scene.init();
  
    // QGLViewer settings.
!   setSceneBoundingBox(
!     qglviewer::Vec(scene.getBBoxMin()[0],scene.getBBoxMin()[1],scene.getBBoxMin()[2]), 
!     qglviewer::Vec(scene.getBBoxMax()[0],scene.getBBoxMax()[1],scene.getBBoxMax()[2])
!   );
    setSceneRadius(2.0f*sceneRadius());
    showEntireScene();
  }
