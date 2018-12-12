# Created by: Yuri Victorovich <yuri@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libQGLViewer
DISTVERSION=	2.7.1
PORTREVISION=	1
CATEGORIES=	graphics devel
MASTER_SITES=	http://www.libqglviewer.com/src/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ library based on Qt5 that eases the creation of OpenGL 3D viewers

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENCE

USES=		compiler:c++11-lang gl qmake qt:5
USE_GL=		gl glu
USE_QT=		core designer gui opengl widgets xml buildtools_build
USE_LDCONFIG=	yes
PLIST_SUB=	SHL3=${DISTVERSION} SHL2=${DISTVERSION:C/\.[0-9]$//} SHL1=${DISTVERSION:C/\.[0-9]\.[0-9]$//}

OPTIONS_DEFINE=	DOCS

DOCSDIR=	${PREFIX}/share/doc/QGLViewer
PORTDOCS=	*

.include <bsd.port.mk>
