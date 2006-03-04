# New ports collection makefile for:    oolite
# Date created:         04 Oct 2005
# Whom:                 Andriy Gapon <avg@icyb.net.ua>
#
# $FreeBSD$
#

PORTNAME=	oolite
PORTVERSION=	${OOLITE_BASE_VERSION}.${OOLITE_SRC_VERSION}
CATEGORIES=	games
MASTER_SITES=	http://download.berlios.de/oolite-linux/old/ \
		ftp://ftp.alioth.net/oolite/old/
DISTFILES=	${PORTNAME}-src-${OOLITE_BASE_VERSION}-${OOLITE_SRC_VERSION}${EXTRACT_SUFX} \
		${PORTNAME}-data-${OOLITE_BASE_VERSION}-${OOLITE_DATA_VERSION}${EXTRACT_SUFX}

MAINTAINER=	avg@icyb.net.ua
COMMENT=	Trade and combat space simulator, clone of Elite

OOLITE_BASE_VERSION=	1.62
OOLITE_SRC_VERSION=	3
OOLITE_DATA_VERSION=	3

WRKSRC=		${WRKDIR}/${PORTNAME}-src
GNUSTEP_PREFIX?=${LOCALBASE}/GNUstep
PREFIX=		${GNUSTEP_PREFIX}
NO_MTREE=	yes
USE_SDL=	mixer image gfx
USE_GMAKE=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_GUI=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
MAKEFILE=	GNUmakefile
SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

post-extract:
	${MV} ${WRKDIR}/${PORTNAME}-data/Resources ${WRKSRC}

post-patch:
	${REINPLACE_CMD} -e "s#sdl-config#${SDL_CONFIG}#g" ${WRKSRC}/${MAKEFILE}

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
