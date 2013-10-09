# $FreeBSD$

PORTNAME=	libcoverart
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	https://cloud.github.com/downloads/metabrainz/${PORTNAME}/

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Library for accessing the MusicBrainz cover art archive

LICENSE=	LGPL20

LIB_DEPENDS=	libjansson.so:${PORTSDIR}/devel/jansson \
		libneon.so:${PORTSDIR}/www/neon29

USES=		cmake
USE_LDCONFIG=	yes

# {PROJECT_VERSION} is not a variable nor a typo, just part of the directory name
WRKSRC=		${WRKDIR}/${PORTNAME}-{PROJECT_VERSION}

post-patch:
	${REINPLACE_CMD} -e '/pkgconfig/s|$${LIB_INSTALL_DIR}|libdata|' \
		 ${WRKSRC}/CMakeLists.txt
	${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		 ${WRKSRC}/cmake/modules/*.cmake

.include <bsd.port.mk>
