# $FreeBSD$

PORTNAME=	libcoverart
PORTVERSION=	1.0.0
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	GHC

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Library for accessing the MusicBrainz cover art archive

LICENSE=	LGPL20

LIB_DEPENDS=	libjansson.so:devel/jansson \
		libneon.so:www/neon

USES=		cmake pathfix
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	metabrainz

# {PROJECT_VERSION} is not a variable nor a typo, just part of the directory name
WRKSRC=		${WRKDIR}/${PORTNAME}-{PROJECT_VERSION}

post-patch:
	${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		 ${WRKSRC}/cmake/modules/*.cmake

.include <bsd.port.mk>
