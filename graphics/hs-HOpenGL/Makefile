# New ports collection makefile for:	HOpenGL
# Date created:				15 January 2003
# Whom:					Janni <janni@hacker7.net>
#
# $FreeBSD$
#

PORTNAME=	HOpenGL
PORTVERSION=	1.04
PORTREVISION=	1
CATEGORIES=	graphics haskell
MASTER_SITES=	http://haskell.cs.yale.edu/HOpenGL/releases/
PKGNAMEPREFIX=	hs-

MAINTAINER= 	ports@FreeBSD.org
COMMENT=	Binding for OpenGL and GLUT for the lazy functional language Haskell

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc5 \
		green-card:${PORTSDIR}/devel/hs-green-card

RUN_DEPENDS=	ghc:${PORTSDIR}/lang/ghc5

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_MESA=	yes

GHC_VERSION?=	5.04.3
LIB_DIR_REL=	lib/ghc-${GHC_VERSION}
LIB_DIR=	${PREFIX}/${LIB_DIR_REL}
IMPORT_DIR=	${LIB_DIR}/imports/HOpenGL
IMPORT_DIR_REL=	${LIB_DIR_REL}/imports/HOpenGL

pre-configure:
	@if [ ! -d ${LIB_DIR} ]; then \
		${ECHO_MSG}; ${ECHO_MSG} "ERROR:"; \
		${ECHO_MSG} "The GHC directory could not be found (${LIB_DIR})."; \
		${ECHO_MSG} 'Please provide a $$PREFIX and a $$GHC_VERSION, so that'; \
		${ECHO_MSG} '$$PREFIX/lib/ghc-$$GHC_VERSION points to the right directory!'; \
		${ECHO_MSG}; exit 1; \
	fi

CONFIGURE_ARGS+=--with-library-dir=${LIB_DIR} --with-import-dir=${IMPORT_DIR} --enable-Mesa
PLIST_SUB=	LIB_DIR=${LIB_DIR_REL} IMPORT_DIR=${IMPORT_DIR_REL}
PLIST_SUB+=	GHC_VERSION="${GHC_VERSION}"

ALL_TARGET=	depend all

EXAMPLESSRC=	${WRKSRC}/examples
MISCDIR=	${EXAMPLESDIR}/misc
MISCSRC=	${EXAMPLESSRC}/misc
CDIR=		${EXAMPLESDIR}/redbook_C
CSRC=		${EXAMPLESSRC}/redbook_C
HSDIR=		${EXAMPLESDIR}/redbook_HS
HSSRC=		${EXAMPLESSRC}/redbook_HS
GFXSRC=		${WRKSRC}/GLUT/Graphics
GFXDIR=		${IMPORT_DIR}/Graphics

CEXAMPLES=	aaindex aapoly aargb accanti accpersp alpha alpha3D anti bezcurve bezmesh bezsurf blendeqn checker clip colormat colormatrix cube depthcue dof double drawf feedback fog fogindex font hello image light lines list material mipmap model movelight multitex nurbs pickdepth picksquare plane planet polyoff polys robot sccolorlight scene scenebamb sceneflat select smooth stencil stroke surface surfpoints teaambient teapots tess tesswind texbind texgen texprox texsub texture3d texturesurf torus trim unproject varray wrap
HSEXAMPLES=	AAIndex AAPoly AARGB AccAnti AccPersp Alpha Alpha3D Anti BezCurve BezMesh BezSurf BlendEqn Checker Clip ColorMat Cube DList DOF DepthCue Double DrawF Feedback Fog FogIndex Font Hello Image Light Lines Material Mipmap Model MoveLight PickDepth PickSquare Plane Planet PolyOff Polys Quadric Robot ScColorLight Scene SceneBAmb SceneFlat Select Smooth Stencil Stroke TeaAmbient Teapots Tess TexBind TexGen TexProx TexSub TextureSurf Torus Unproject Varray Wrap

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502102
BROKEN=		"Does not compile"
.endif

post-install:
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/lib/HOpenGL.conf ${DATADIR}

	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${EXAMPLESSRC}/00Contents ${EXAMPLESDIR}

	${MKDIR} ${MISCDIR}
	${INSTALL_DATA}    ${MISCSRC}/*.hs          ${MISCDIR}
	${INSTALL_PROGRAM} ${MISCSRC}/Info          ${MISCDIR}
	${INSTALL_PROGRAM} ${MISCSRC}/QBSP          ${MISCDIR}
	${INSTALL_PROGRAM} ${MISCSRC}/QuakeMovement ${MISCDIR}
	${INSTALL_PROGRAM} ${MISCSRC}/TestGLUT      ${MISCDIR}

	${MKDIR} ${CDIR}
	${MKDIR} ${CDIR}/Data
	${INSTALL_DATA} ${CSRC}/Data/leeds.bin ${CDIR}/Data
	for i in ${CEXAMPLES}; do \
		${INSTALL_PROGRAM} ${CSRC}/$$i ${CDIR}; \
	done
	${INSTALL_DATA} ${CSRC}/*.c ${CDIR}
	${INSTALL_DATA} ${CSRC}/jitter.h ${CDIR}

	${MKDIR} ${HSDIR}
	for i in ${HSEXAMPLES}; do \
		${INSTALL_PROGRAM} ${HSSRC}/$$i ${HSDIR}; \
	done
	${INSTALL_DATA} ${HSSRC}/*.hs ${HSDIR}

	${MKDIR} ${GFXDIR}
	${MKDIR} ${GFXDIR}/UI
	${MKDIR} ${GFXDIR}/UI/GLUT
	${MKDIR} ${GFXDIR}/UI/GLUT/Callbacks
	${INSTALL_DATA} ${GFXSRC}/UI/GLUT.hi ${GFXDIR}/UI
	${INSTALL_DATA} ${GFXSRC}/UI/GLUT/*.hi ${GFXDIR}/UI/GLUT
	${INSTALL_DATA} ${GFXSRC}/UI/GLUT/Callbacks/*.hi ${GFXDIR}/UI/GLUT/Callbacks

	@${RM} -f ${PREFIX}/lib/ghc-${GHC_VERSION}/package.conf.old

.include <bsd.port.post.mk>
