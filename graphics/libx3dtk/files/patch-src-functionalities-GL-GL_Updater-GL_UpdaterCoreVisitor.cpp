*** src/functionalities/GL/GL_Updater/GL_UpdaterCoreVisitor.cpp.orig	Sat Dec 16 15:50:47 2006
--- src/functionalities/GL/GL_Updater/GL_UpdaterCoreVisitor.cpp	Sat Dec 16 15:53:01 2006
***************
*** 19,25 ****
  
  void UpdaterCoreVisitor::enterScene(Scene *S) 
  {
!   UpdaterStateVariables *stateVariables = Singleton<UpdaterStateVariables>::getInstance();
    S->update();
    
    if (chdir(S->getFileName().getPath()) != 0)
--- 19,25 ----
  
  void UpdaterCoreVisitor::enterScene(Scene *S) 
  {
!   /* UpdaterStateVariables *stateVariables = */ Singleton<UpdaterStateVariables>::getInstance();
    S->update();
    
    if (chdir(S->getFileName().getPath()) != 0)
***************
*** 28,34 ****
  
  void UpdaterCoreVisitor::enterX3DNode(X3DNode *N) 
  {
!   UpdaterStateVariables *stateVariables = Singleton<UpdaterStateVariables>::getInstance();
    N->update();
  }
  
--- 28,34 ----
  
  void UpdaterCoreVisitor::enterX3DNode(X3DNode *N) 
  {
!   /* UpdaterStateVariables *stateVariables = */ Singleton<UpdaterStateVariables>::getInstance();
    N->update();
  }
  
