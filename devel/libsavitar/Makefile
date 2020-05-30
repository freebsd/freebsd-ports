# $FreeBSD$

PORTNAME=	libSavitar
DISTVERSION=	4.5.0
PORTREVISION=	1
CATEGORIES=	devel cad
DIST_SUBDIR=	Ultimaker

MAINTAINER=	db@FreeBSD.org
COMMENT=	C++ implementation of 3mf loading/python bindings

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sip>0:devel/py-sip@${PY_FLAVOR}
LIB_DEPENDS=	libpugixml.so:textproc/pugixml

USES=		cmake compiler:c++11-lang python:3.4+
USE_GITHUB=	yes
GH_ACCOUNT=	Ultimaker
GH_TAGNAME=	96eba0e
USE_LDCONFIG=	yes
CFLAGS+=	"-I${LOCALBASE}/include"
LDFLAGS+=	"-L${LOCALBASE}/lib"

.include <bsd.port.mk>
