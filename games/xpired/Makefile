# New ports collection makefile for:	xpired
# Date created:				2 July 2002
# Whom:					Edwin Groothuis <edwin@mavetju.org>
#
# $FreeBSD$
#

PORTNAME=	xpired
PORTVERSION=	1.22
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	xpired
DISTNAME=	${PORTNAME}-${PORTVERSION}-linux_source

MAINTAINER=	edwin@mavetju.org

LIB_DEPENDS=	SDL_gfx.0:${PORTSDIR}/graphics/sdl_gfx \
		SDL_image.10:${PORTSDIR}/graphics/sdl_image \
		SDL_mixer.2:${PORTSDIR}/audio/sdl_mixer \
		SDL-1.1.4:${PORTSDIR}/devel/sdl12

WRKSRC=		${WRKDIR}/src

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/xpired ${WRKSRC}/xpiredit ${PREFIX}/bin
	@${MKDIR} ${DATADIR}/img
	@${MKDIR} ${DATADIR}/snd
.for files in xpired.lvl xpired.cfg bgimages.txt readme.txt xpired.dmo
	@${INSTALL_DATA} ${WRKSRC}/${files} ${DATADIR}
.endfor
	@${INSTALL_DATA} ${WRKSRC}/img/* ${DATADIR}/img
	@${INSTALL_DATA} ${WRKSRC}/snd/* ${DATADIR}/snd

.include <bsd.port.mk>
