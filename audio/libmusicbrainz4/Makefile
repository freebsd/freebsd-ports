# $FreeBSD$

PORTNAME=	libmusicbrainz
PORTVERSION=	4.0.3
CATEGORIES=	audio
MASTER_SITES=	https://cloud.github.com/downloads/metabrainz/${PORTNAME}/
PKGNAMESUFFIX=	4

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	MusicBrainz client library for audio metadata lookup

LICENSE=	LGPL21

LIB_DEPENDS=	libneon.so:${PORTSDIR}/www/neon29

DEPRECATED=	Please use audio/libmusicbrainz5 instead
EXPIRATION_DATE=	2014-04-28

USES=		cmake
USE_LDCONFIG=	yes

post-patch:
	${REINPLACE_CMD} -e '/pkgconfig/s|$${LIB_INSTALL_DIR}|libdata|' \
		 ${WRKSRC}/CMakeLists.txt
	${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		 ${WRKSRC}/cmake/modules/*.cmake

.include <bsd.port.mk>
