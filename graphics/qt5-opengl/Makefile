# $FreeBSD$

PORTNAME=	opengl
DISTVERSION=	${QT5_VERSION}
CATEGORIES=	graphics
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt 5-compatible OpenGL support module

USES=		compiler:c++11-lang gl qmake:no_env qt-dist:5,base
USE_GL=		gl
USE_QT=		core gui widgets qmake_build buildtools_build
HAS_CONFIGURE=	yes
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

BUILD_WRKSRC=	${WRKSRC}/src/${PORTNAME}
INSTALL_WRKSRC=	${BUILD_WRKSRC}

QT_DEFINES=	OPENGL
QT_CONFIG=	opengl

post-configure:
.for d in src/opengl
	${MKDIR} ${WRKSRC}/${d}
	cd ${WRKSRC}/${d} && ${SETENV} ${QMAKE_ENV} ${_QMAKE} ${QMAKE_ARGS} ${WRKSRC}/${d}
.endfor

.include <bsd.port.mk>
