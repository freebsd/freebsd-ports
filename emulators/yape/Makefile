# New ports collection makefile for:    yape
# Date created:         31.10.2002
# Whom:                 Janos.Mohacsi@bsd.hu
#
# $FreeBSD$
#

PORTNAME=	yape
PORTVERSION=	0.32.3
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	http://yape.homeserver.hu/download/
DISTNAME=	yapeSDL-${PORTVERSION}

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	Yet Another Commodore +4 Emulator

LIB_DEPENDS=	SDL-1.1.5:${PORTSDIR}/devel/sdl12

NO_WRKSUBDIR=	yes
USE_REINPLACE=	yes
SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config
USE_GMAKE=	yes
ALL_TARGET=	yape

post-patch:
	@${REINPLACE_CMD} -e "s|sdl-config|${SDL_CONFIG}|" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/yape ${PREFIX}/bin

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.Linux ${DOCSDIR}
.endif

.include <bsd.port.mk>
