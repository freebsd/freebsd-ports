PORTNAME=	libSavitar
DISTVERSION=	4.11.0
CATEGORIES=	devel cad
DIST_SUBDIR=	Ultimaker

MAINTAINER=	db@FreeBSD.org
COMMENT=	C++ implementation of 3mf loading/python bindings

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	sip:devel/py-sip4
LIB_DEPENDS=	libpugixml.so:textproc/pugixml

USES=		cmake compiler:c++11-lang python:3.5+ pyqt:5
USE_GITHUB=	yes
GH_ACCOUNT=	Ultimaker
USE_LDCONFIG=	yes
CFLAGS+=	"-I${LOCALBASE}/include"
LDFLAGS+=	"-L${LOCALBASE}/lib"

.include <bsd.port.mk>
