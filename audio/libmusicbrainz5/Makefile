# $FreeBSD$

PORTNAME=	libmusicbrainz
PORTVERSION=	5.1.0
CATEGORIES=	audio
PKGNAMESUFFIX=	5

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	MusicBrainz client library for audio metadata lookup

LICENSE=	LGPL21

LIB_DEPENDS=	libneon.so:${PORTSDIR}/www/neon

USES=		cmake
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	metabrainz
GH_TAGNAME=	release-${PORTVERSION}

post-patch:
	${REINPLACE_CMD} -e '/pkgconfig/s|$${LIB_INSTALL_DIR}|libdata|' \
		 ${WRKSRC}/CMakeLists.txt
	${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		 ${WRKSRC}/cmake/modules/*.cmake
	${RM} -f ${WRKSRC}/cmake/modules/FindLibXml2.cmake

.include <bsd.port.mk>
