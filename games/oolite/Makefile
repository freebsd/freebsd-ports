# New ports collection makefile for:    oolite
# Date created:         04 Oct 2005
# Whom:                 Andriy Gapon <avg@icyb.net.ua>
#
# $FreeBSD$
#

PORTNAME=	oolite
PORTVERSION=	1.55
CATEGORIES=	games
MASTER_SITES=	http://download.berlios.de/oolite-linux/ \
		ftp://ftp.alioth.net/oolite/
DISTFILES=	${PORTNAME}-src-${PORTVERSION}-1${EXTRACT_SUFX} ${PORTNAME}-data-${PORTVERSION}-1${EXTRACT_SUFX}

MAINTAINER=	avg@icyb.net.ua
COMMENT=	Trade and combat space simulator, clone of Elite

WRKSRC=		${WRKDIR}/${PORTNAME}-src
PREFIX=		${LOCALBASE}/GNUstep
NO_MTREE=	yes
USE_REINPLACE=	yes
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
