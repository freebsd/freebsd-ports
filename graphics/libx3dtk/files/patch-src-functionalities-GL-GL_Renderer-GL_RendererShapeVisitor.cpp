*** src/functionalities/GL/GL_Renderer/GL_RendererShapeVisitor.cpp.orig	Sat Dec 16 15:45:37 2006
--- src/functionalities/GL/GL_Renderer/GL_RendererShapeVisitor.cpp	Sat Dec 16 15:47:15 2006
***************
*** 19,25 ****
  
  void RendererShapeVisitor::enterMaterial(Material *M) 
  {
!   RendererStateVariables *stateVariables = Singleton<RendererStateVariables>::getInstance();
    
    glMaterialfv(GL_FRONT, GL_DIFFUSE, &M->getDiffuseColor().front());
    glMaterialfv(GL_FRONT, GL_AMBIENT, &M->getAmbientColor().front());
--- 19,25 ----
  
  void RendererShapeVisitor::enterMaterial(Material *M) 
  {
!   /* RendererStateVariables *stateVariables = */ Singleton<RendererStateVariables>::getInstance();
    
    glMaterialfv(GL_FRONT, GL_DIFFUSE, &M->getDiffuseColor().front());
    glMaterialfv(GL_FRONT, GL_AMBIENT, &M->getAmbientColor().front());
