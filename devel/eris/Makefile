PORTNAME=	eris
PORTVERSION=	1.3.23
PORTREVISION=	10
CATEGORIES=	devel
MASTER_SITES=	SF/worldforge/Eris%201.4%20%28client%20lib%29/${PORTVERSION}/

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	WorldForge client entity library
WWW=		https://www.worldforge.org/index.php/components/eris/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	There has been no release for most of the Worldforge libraries in the past 10 years.
EXPIRATION_DATE=2023-12-31

LIB_DEPENDS=	libAtlas-0.6.so:devel/atlas-devel \
		libskstream-0.3.so:net/skstream \
		libwfmath-1.0.so:math/wfmath \
		libsigc-2.0.so:devel/libsigc++20 \
		libmercator-0.3.so:devel/mercator

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		libtool pathfix pkgconfig compiler:c++11-lib
USE_CXXSTD=	c++11

.include <bsd.port.mk>
