PORTNAME=	opencollada
DISTVERSIONPREFIX=	v
PORTVERSION=	1.6.68
PORTREVISION=	5
CATEGORIES=	graphics devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library for reading and writing COLLADA files
WWW=		http://opencollada.org/ \
		https://github.com/KhronosGroup/OpenCOLLADA

LICENSE=	MIT

LIB_DEPENDS=	libpcre.so:devel/pcre

USES=		cmake compiler:c++11-lib dos2unix iconv localbase gnome pkgconfig
USE_GNOME=	libxml2

USE_GITHUB=	yes
GH_ACCOUNT=	KhronosGroup
GH_PROJECT=	OpenCOLLADA

CFLAGS+=	-Wno-narrowing
CMAKE_ON=	USE_LIBXML USE_SHARED USE_STATIC
USE_LDCONFIG=	${PREFIX}/lib/opencollada

.include <bsd.port.mk>
