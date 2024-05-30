PORTNAME=	libSavitar
DISTVERSION=	4.13.1
PORTREVISION=	1
CATEGORIES=	devel cad
DIST_SUBDIR=	Ultimaker

MAINTAINER=	db@FreeBSD.org
COMMENT=	C++ implementation of 3mf loading/python bindings
WWW=		https://github.com/Ultimaker/libSavitar

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Fails to build with modern python
EXPIRATION_DATE=	2024-06-29

BUILD_DEPENDS=	sip:devel/py-sip4
LIB_DEPENDS=	libpugixml.so:textproc/pugixml

USES=		cmake compiler:c++11-lang python pyqt:5 gettext-runtime
USE_GITHUB=	yes
GH_ACCOUNT=	Ultimaker
USE_LDCONFIG=	yes
CFLAGS+=	"-I${LOCALBASE}/include"
LDFLAGS+=	"-L${LOCALBASE}/lib"

.include <bsd.port.mk>
