# $FreeBSD$

PORTNAME=	libcoverart
PORTVERSION=	1.0.0
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	https://github.com/metabrainz/${PORTNAME}/releases/download/release-${PORTVERSION}/

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Library for accessing the MusicBrainz cover art archive

LICENSE=	LGPL20

LIB_DEPENDS=	libjansson.so:devel/jansson \
		libneon.so:www/neon

USES=		cmake pathfix
USE_LDCONFIG=	yes

post-patch:
	${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		 ${WRKSRC}/cmake/modules/*.cmake

.include <bsd.port.mk>
