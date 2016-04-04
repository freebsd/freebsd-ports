# $FreeBSD$

PORTNAME=	libmusicbrainz
PORTVERSION=	5.1.0
DISTVERSIONPREFIX=	release-
CATEGORIES=	audio
PKGNAMESUFFIX=	5

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	MusicBrainz client library for audio metadata lookup

LICENSE=	LGPL21

LIB_DEPENDS=	libneon.so:www/neon

USES=		cmake iconv:build pathfix
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	metabrainz

post-patch:
	${REINPLACE_CMD} -e 's|%%ICONV_PREFIX%%|${ICONV_PREFIX}|g' \
		 ${WRKSRC}/src/CMakeLists.txt
	${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		 ${WRKSRC}/cmake/modules/*.cmake
	${RM} -f ${WRKSRC}/cmake/modules/FindLibXml2.cmake

.include <bsd.port.mk>
