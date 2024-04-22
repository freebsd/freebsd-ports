PORTNAME=	libQGLViewer
DISTVERSIONPREFIX=	v
DISTVERSION=	2.9.1
CATEGORIES=	graphics devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ library based on Qt5 that eases the creation of OpenGL 3D viewers
WWW=		https://github.com/GillesDebunne/libQGLViewer

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENCE

USES=		cmake compiler:c++17-lang gl qt:5
USE_GL=		gl glu
USE_QT=		core designer gui opengl widgets xml \
		buildtools:build qmake:build
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	GillesDebunne

CMAKE_OFF=	USE_QT6

PLIST_SUB=	SHL3=${DISTVERSION} SHL2=${DISTVERSION:C/\.[0-9]$//} SHL1=${DISTVERSION:C/\.[0-9]\.[0-9]$//}

OPTIONS_DEFINE=	DOCS

DOCSDIR=	${PREFIX}/share/doc/QGLViewer
PORTDOCS=	*

.include <bsd.port.mk>
