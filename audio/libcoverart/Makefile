# $FreeBSD$

PORTNAME=	libcoverart
PORTVERSION=	1.0.0
PORTREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	https://github.com/metabrainz/${PORTNAME}/releases/download/release-${PORTVERSION}/

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Library for accessing the MusicBrainz cover art archive

LICENSE=	LGPL20

LIB_DEPENDS=	libjansson.so:devel/jansson \
		libneon.so:www/neon

USES=		compiler:c11 cmake pathfix
USE_CSTD=	c99
USE_CXXSTD=	c++98
USE_LDCONFIG=	yes

CXXFLAGS+=	-Wno-implicit-fallthrough

.if exists(/usr/lib/libstdc++.so)
CXXFLAGS+=	-Wno-unused-function -Wno-class-memaccess -Wno-catch-value
CFLAGS+=	-Wno-format-overflow
.endif

post-patch:
	${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		 ${WRKSRC}/cmake/modules/*.cmake

.include <bsd.port.mk>
