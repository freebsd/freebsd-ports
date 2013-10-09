# $FreeBSD$

PORTNAME=	libmusicbrainz
PORTVERSION=	5.0.1
CATEGORIES=	audio
MASTER_SITES=	https://cloud.github.com/downloads/metabrainz/${PORTNAME}/
PKGNAMESUFFIX=	5

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	MusicBrainz client library for audio metadata lookup

LICENSE=	LGPL21

LIB_DEPENDS=	libneon.so:${PORTSDIR}/www/neon29

USES=		cmake
USE_LDCONFIG=	yes

post-patch:
	${REINPLACE_CMD} -e '/pkgconfig/s|$${LIB_INSTALL_DIR}|libdata|' \
		 ${WRKSRC}/CMakeLists.txt
	${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		 ${WRKSRC}/cmake/modules/*.cmake

.include <bsd.port.mk>
