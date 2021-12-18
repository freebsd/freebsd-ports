PORTNAME=	opengl
PORTVERSION=	${QT5_VERSION}${QT5_KDE_PATCH}
CATEGORIES=	graphics
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt 5-compatible OpenGL support module

USES=		compiler:c++11-lang gl perl5 qmake:no_env qt-dist:5,base
USE_GL=		gl
USE_PERL5=	extract
USE_QT=		core gui widgets qmake_build buildtools_build
HAS_CONFIGURE=	yes

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
