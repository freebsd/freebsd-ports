# $FreeBSD$

PORTNAME=	libSavitar
DISTVERSION=	4.5.0
PORTREVISION=	5
CATEGORIES=	devel cad
DIST_SUBDIR=	Ultimaker

PATCH_SITES=   https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=    195633cf0c5f.patch:-p1

MAINTAINER=	db@FreeBSD.org
COMMENT=	C++ implementation of 3mf loading/python bindings

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpugixml.so:textproc/pugixml

USES=		cmake compiler:c++11-lang python:3.5+ pyqt:5
USE_PYQT=	sip pysip
USE_GITHUB=	yes
GH_ACCOUNT=	Ultimaker
GH_TAGNAME=	96eba0e
USE_LDCONFIG=	yes
CFLAGS+=	"-I${LOCALBASE}/include"
LDFLAGS+=	"-L${LOCALBASE}/lib"

.include <bsd.port.mk>
