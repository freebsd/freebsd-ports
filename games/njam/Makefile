# New ports collection makefile for: njam
# Date created:		10 November 2003
# Whom:			<janos.mohacsi@bsd.hu>
#
# $FreeBSD$
#

PORTNAME=	njam
PORTVERSION=	1.00
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	 ${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	Fast paced multiplayer pac-man clone

LIB_DEPENDS=	SDL_mixer.2:${PORTSDIR}/audio/sdl_mixer \
		SDL_image.10:${PORTSDIR}/graphics/sdl_image \
		SDL_net.0:${PORTSDIR}/net/sdl_net

USE_GMAKE=	yes
USE_SDL=	yes
DOC_FILES=	assassin.gif award-2.gif cookie.gif doc-editor.html \
		doc.html doc2.html door.gif freezer.gif ghactive.gif \
		ghinactive.gif hunter.gif invisible.gif juice.gif \
		sample.gif shaddy.gif skin000.gif skin001.gif skin003.gif \
		teleport.gif thinline.gif trap.gif

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/html/* ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
