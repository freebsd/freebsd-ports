# New ports collection makefile for: opengl-manpage
# Version required:     657
# Date created:         19990120
# Whom:                 cracauer@cons.org "Martin Cracauer"
#
# $Id: Makefile,v 1.3 1998/12/08 08:13:31 obrien Exp $
#

DISTNAME=       opengl-man-657
CATEGORIES=     graphics
MASTER_SITES=   http://www2.cons.org:8000/freebsd-distfiles/ \
		http://www.freebsd.org/~cracauer/freebsd-distfiles/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	cracauer@cons.org

BUILD_DEPENDS=	bzip2:${PORTSDIR}/archivers/bzip2

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

.include <bsd.port.pre.mk>

EXTRACT_CMD=		bzip2
EXTRACT_BEFORE_ARGS=	-dc
EXTRACT_AFTER_ARGS=	| tar -xf -

MAN3=	glDisable.3 glDisableClientState.3 glEdgeFlag.3 \
	glEdgeFlagPointer.3 glEdgeFlagv.3 glEnable.3 \
	glEnableClientState.3 glEndList.3 glEvalCoord1d.3 \
	glEvalCoord1dv.3 glEvalCoord1f.3 glEvalCoord1fv.3 glEvalCoord2d.3 \
	glEvalCoord2dv.3 glEvalCoord2f.3 glEvalCoord2fv.3 glEvalMesh1.3 \
	glEvalMesh2.3 glEvalPoint1.3 glEvalPoint2.3 glFeedbackBuffer.3 \
	glFinish.3 glFlush.3 glFogf.3 glFogfv.3 glFogi.3 glFogiv.3 \
	glFrontFace.3 glFrustum.3 glGenLists.3 glGenTextures.3 \
	glGetBooleanv.3 glGetClipPlane.3 glGetDoublev.3 glGetError.3 \
	glGetFloatv.3 glGetIntegerv.3 glGetLightfv.3 glGetLightiv.3 \
	glGetMapdv.3 glGetMapfv.3 glGetMapiv.3 glGetMaterialfv.3 \
	glGetMaterialiv.3 glGetPixelMapfv.3 glGetPixelMapuiv.3 \
	glGetPixelMapusv.3 glGetPointerv.3 glGetPolygonStipple.3 \
	glGetString.3 glGetTexEnvfv.3 glGetTexEnviv.3 glGetTexGendv.3 \
	glGetTexGenfv.3 glGetTexGeniv.3 glGetTexImage.3 \
	glGetTexLevelParameterfv.3 glGetTexLevelParameteriv.3 \
	glGetTexParameterfv.3 glGetTexParameteriv.3 glHint.3 \
	glIndexMask.3 glIndexPointer.3 glIndexd.3 glIndexdv.3 glIndexf.3 \
	glIndexfv.3 glIndexi.3 glIndexiv.3 glIndexs.3 glIndexsv.3 \
	glIndexub.3 glIndexubv.3 glInitNames.3 glInterleavedArrays.3 \
	glIsEnabled.3 glIsList.3 glIsTexture.3 glLightModelf.3 \
	glLightModelfv.3 glLightModeli.3 glLightModeliv.3 glLightf.3 \
	glLightfv.3 glLighti.3 glLightiv.3 glLineStipple.3 glLineWidth.3 \
	glListBase.3 glLoadIdentity.3 glLoadMatrixd.3 glLoadMatrixf.3 \
	glLoadName.3 glLogicOp.3 glMap1d.3 glMap1f.3 glMap2d.3 glMap2f.3 \
	glMapGrid1d.3 glMapGrid1f.3 glMapGrid2d.3 glMapGrid2f.3 \
	glMaterialf.3 glMaterialfv.3 glMateriali.3 glMaterialiv.3 \
	glMatrixMode.3 glMultMatrixd.3 glMultMatrixf.3 glNewList.3 \
	glNormal3b.3 glNormal3bv.3 glNormal3d.3 glNormal3dv.3 \
	glNormal3f.3 glNormal3fv.3 glNormal3i.3 glNormal3iv.3 \
	glNormal3s.3 glNormal3sv.3 glNormalPointer.3 glOrtho.3 \
	glPassThrough.3 glPixelMapfv.3 glPixelMapuiv.3 glPixelMapusv.3 \
	glPixelStoref.3 glPixelStorei.3 glPixelTransferf.3 \
	glPixelTransferi.3 glPixelZoom.3 glPointSize.3 glPolygonMode.3 \
	glPolygonOffset.3 glPolygonStipple.3 glPopAttrib.3 \
	glPopClientAttrib.3 glPopMatrix.3 glPopName.3 \
	glPrioritizeTextures.3 glPushAttrib.3 glPushClientAttrib.3 \
	glPushMatrix.3 glPushName.3 glRasterPos2d.3 glRasterPos2dv.3 \
	glRasterPos2f.3 glRasterPos2fv.3 glRasterPos2i.3 glRasterPos2iv.3 \
	glRasterPos2s.3 glRasterPos2sv.3 glRasterPos3d.3 glRasterPos3dv.3 \
	glRasterPos3f.3 glRasterPos3fv.3 glRasterPos3i.3 glRasterPos3iv.3 \
	glRasterPos3s.3 glRasterPos3sv.3 glRasterPos4d.3 glRasterPos4dv.3 \
	glRasterPos4f.3 glRasterPos4fv.3 glRasterPos4i.3 glRasterPos4iv.3 \
	glRasterPos4s.3 glRasterPos4sv.3 glReadBuffer.3 glReadPixels.3 \
	glRectd.3 glRectdv.3 glRectf.3 glRectfv.3 glRecti.3 glRectiv.3 \
	glRects.3 glRectsv.3 glRenderMode.3 glRotated.3 glRotatef.3 \
	glScaled.3 glScalef.3 glScissor.3 glSelectBuffer.3 glShadeModel.3 \
	glStencilFunc.3 glStencilMask.3 glStencilOp.3 glTexCoord1d.3 \
	glTexCoord1dv.3 glTexCoord1f.3 glTexCoord1fv.3 glTexCoord1i.3 \
	glTexCoord1iv.3 glTexCoord1s.3 glTexCoord1sv.3 glTexCoord2d.3 \
	glTexCoord2dv.3 glTexCoord2f.3 glTexCoord2fv.3 glTexCoord2i.3 \
	glTexCoord2iv.3 glTexCoord2s.3 glTexCoord2sv.3 glTexCoord3d.3 \
	glTexCoord3dv.3 glTexCoord3f.3 glTexCoord3fv.3 glTexCoord3i.3 \
	glTexCoord3iv.3 glTexCoord3s.3 glTexCoord3sv.3 glTexCoord4d.3 \
	glTexCoord4dv.3 glTexCoord4f.3 glTexCoord4fv.3 glTexCoord4i.3 \
	glTexCoord4iv.3 glTexCoord4s.3 glTexCoord4sv.3 \
	glTexCoordPointer.3 glTexEnvf.3 glTexEnvfv.3 glTexEnvi.3 \
	glTexEnviv.3 glTexGend.3 glTexGendv.3 glTexGenf.3 glTexGenfv.3 \
	glTexGeni.3 glTexGeniv.3 glTexImage1D.3 glTexImage2D.3 \
	glTexParameterf.3 glTexParameterfv.3 glTexParameteri.3 \
	glTexParameteriv.3 glTexSubImage1D.3 glTexSubImage2D.3 \
	glTranslated.3 glTranslatef.3 glVertex2d.3 glVertex2dv.3 \
	glVertex2f.3 glVertex2fv.3 glVertex2i.3 glVertex2iv.3 \
	glVertex2s.3 glVertex2sv.3 glVertex3d.3 glVertex3dv.3 \
	glVertex3f.3 glVertex3fv.3 glVertex3i.3 glVertex3iv.3 \
	glVertex3s.3 glVertex3sv.3 glVertex4d.3 glVertex4dv.3 \
	glVertex4f.3 glVertex4fv.3 glVertex4i.3 glVertex4iv.3 \
	glVertex4s.3 glVertex4sv.3 glVertexPointer.3 glViewport.3 \
	glXChooseVisual.3 glXCopyContext.3 glXCreateContext.3 \
	glXCreateGLXPixmap.3 glXDestroyContext.3 glXDestroyGLXPixmap.3 \
	glXFreeContextEXT.3 glXGetClientString.3 glXGetConfig.3 \
	glXGetContextIDEXT.3 glXGetCurrentContext.3 \
	glXGetCurrentDisplay.3 glXGetCurrentDrawable.3 \
	glXImportContextEXT.3 glXIntro.3 glXIsDirect.3 glXMakeCurrent.3 \
	glXQueryContextInfoEXT.3 glXQueryExtension.3 \
	glXQueryExtensionsString.3 glXQueryServerString.3 \
	glXQueryVersion.3 glXSwapBuffers.3 glXUseXFont.3 glXWaitGL.3 \
	glXWaitX.3 gle.3 gleExtrusion.3 gleHelicoid.3 gleLathe.3 \
	glePolyCone.3 glePolyCylinder.3 gleScrew.3 gleSetJoinStyle.3 \
	gleSpiral.3 gleSuperExtrusion.3 gleTextureMode.3 gleToroid.3 \
	gleTwistExtrusion.3 gluBeginCurve.3 gluBeginPolygon.3 \
	gluBeginSurface.3 gluBeginTrim.3 gluBuild1DMipmaps.3 \
	gluBuild2DMipmaps.3 gluCylinder.3 gluDeleteNurbsRenderer.3 \
	gluDeleteQuadric.3 gluDeleteTess.3 gluDisk.3 gluEndCurve.3 \
	gluEndPolygon.3 gluEndSurface.3 gluEndTrim.3 gluErrorString.3 \
	gluGetNurbsProperty.3 gluGetString.3 gluGetTessProperty.3 \
	gluLoadSamplingMatrices.3 gluLookAt.3 gluNewNurbsRenderer.3 \
	gluNewQuadric.3 gluNewTess.3 gluNextContour.3 gluNurbsCallback.3 \
	gluNurbsCallbackDataEXT.3 gluNurbsCurve.3 gluNurbsProperty.3 \
	gluNurbsSurface.3 gluOrtho2D.3 gluPartialDisk.3 gluPerspective.3 \
	gluPickMatrix.3 gluProject.3 gluPwlCurve.3 gluQuadricCallback.3 \
	gluQuadricDrawStyle.3 gluQuadricNormals.3 gluQuadricOrientation.3 \
	gluQuadricTexture.3 gluScaleImage.3 gluSphere.3 \
	gluTessBeginContour.3 gluTessBeginPolygon.3 gluTessCallback.3 \
	gluTessEndContour.3 gluTessEndPolygon.3 gluTessNormal.3 \
	gluTessProperty.3 gluTessVertex.3 gluUnProject.3 glut.3 \
	glutAddMenuEntry.3 glutAddSubMenu.3 glutAttachMenu.3 \
	glutBitmapCharacter.3 glutBitmapWidth.3 glutButtonBoxFunc.3 \
	glutChangeToMenuEntry.3 glutChangeToSubMenu.3 glutCopyColormap.3 \
	glutCreateMenu.3 glutCreateSubWindow.3 glutCreateWindow.3 \
	glutDestroyMenu.3 glutDestroyWindow.3 glutDeviceGet.3 \
	glutDialsFunc.3 glutDisplayFunc.3 glutEnterGameMode.3 \
	glutEntryFunc.3 glutEstablishOverlay.3 glutExtensionSupported.3 \
	glutForceJoystickFunc.3 glutFullScreen.3 glutGameModeGet.3 \
	glutGameModeString.3 glutGet.3 glutGetColor.3 glutGetModifiers.3 \
	glutIdleFunc.3 glutIgnoreKeyRepeat.3 glutInit.3 \
	glutInitDisplayMode.3 glutInitDisplayString.3 \
	glutInitWindowPosition.3 glutJoystickFunc.3 glutKeyboardFunc.3 \
	glutKeyboardUpFunc.3 glutLayerGet.3 glutMainLoop.3 \
	glutMenuStatusFunc.3 glutMotionFunc.3 glutMouseFunc.3 \
	glutOverlayDisplayFunc.3 glutPopWindow.3 glutPositionWindow.3 \
	glutPostOverlayRedisplay.3 glutPostRedisplay.3 \
	glutRemoveMenuItem.3 glutRemoveOverlay.3 glutReportErrors.3 \
	glutReshapeFunc.3 glutReshapeWindow.3 glutSetColor.3 \
	glutSetCursor.3 glutSetKeyRepeat.3 glutSetMenu.3 glutSetWindow.3 \
	glutSetWindowTitle.3 glutShowOverlay.3 glutShowWindow.3 \
	glutSolidCone.3 glutSolidCube.3 glutSolidDodecahedron.3 \
	glutSolidIcosahedron.3 glutSolidOctahedron.3 glutSolidSphere.3 \
	glutSolidTeapot.3 glutSolidTetrahedron.3 glutSolidTorus.3 \
	glutSpaceballButtonFunc.3 glutSpaceballMotionFunc.3 \
	glutSpaceballRotateFunc.3 glutSpecialFunc.3 glutSpecialUpFunc.3 \
	glutStrokeCharacter.3 glutStrokeWidth.3 glutSwapBuffers.3 \
	glutTabletButtonFunc.3 glutTabletMotionFunc.3 glutTimerFunc.3 \
	glutUseLayer.3 glutVisibilityFunc.3 glutWarpPointer.3

do-install:
	@for file in ${MAN3} ; do \
		$(INSTALL_MAN) $(WRKSRC)/man3/$$file $(PREFIX)/man/man3/. ; \
	done

.include <bsd.port.post.mk>
