PORTNAME=	libmusicbrainz
DISTVERSIONPREFIX=	release-
DISTVERSION=	5.1.0-19
DISTVERSIONSUFFIX=	-ge29cc9a
CATEGORIES=	audio
PKGNAMESUFFIX=	5

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	MusicBrainz client library for audio metadata lookup

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.txt

LIB_DEPENDS=	libneon.so:www/neon

USES=		cmake compiler:c++11-lang gnome iconv:build pathfix
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	metabrainz

post-patch:
	${REINPLACE_CMD} -e 's|%%ICONV_PREFIX%%|${ICONV_PREFIX}|g' \
		 ${WRKSRC}/src/CMakeLists.txt
	${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		 ${WRKSRC}/cmake/modules/*.cmake
	${RM} ${WRKSRC}/cmake/modules/FindLibXml2.cmake

.include <bsd.port.mk>
