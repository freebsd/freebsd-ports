# $FreeBSD$

PORTNAME=	bamtools
DISTVERSIONPREFIX=	v
DISTVERSION=	2.5.1
CATEGORIES=	biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	API and toolkit for handling BAM files

LICENSE=	MIT

LIB_DEPENDS+=	libjsoncpp.so:devel/jsoncpp

USES=		cmake
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	pezmaster31

CMAKE_ON+=	BUILD_SHARED_LIBS

.include <bsd.port.mk>
