# New Ports collection makefile for:	SDL_Lopan
# Date created:		2012-04-26
# Whom:			nemysis@gmx.ch
#
# $FreeBSD$
#

PORTNAME=	sdl_lopan
PORTVERSION=	10
CATEGORIES=	games
MASTER_SITES=	http://www.linuxmotors.com/sdllopan/downloads/
DISTNAME=	${PORTNAME:S/_//}-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Mahjong game remake

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/sdllopan-${PORTVERSION}

USE_SDL=	sdl image mixer
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes

PLIST_FILES=	bin/sdllopan

PORTDATA=	*
PORTDOCS=	Changelog README

ALL_TARGET=

post-patch:
# Fix data location
	@${REINPLACE_CMD} -e 's!data/bg%d.pcx!${DATADIR}/data/bg%d.pcx!' \
	-e 's!data/tiles%d.pcx!${DATADIR}/data/tiles%d.pcx!' \
	-e 's!char temp\[64\];!char temp\[256\];!' \
	${WRKSRC}/lopan.c

do-install:
# Executable
	${INSTALL_PROGRAM} ${WRKSRC}/lopan ${PREFIX}/bin/sdllopan
# Data
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} data ${DATADIR})

# Documentation
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
