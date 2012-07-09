# New Ports collection makefile for:	SDL_jewels
# Date created:		2012-04-25
# Whom:			nemysis@gmx.ch
#
# $FreeBSD$
#

PORTNAME=	sdl_jewels
PORTVERSION=	1.1.1
CATEGORIES=	games
MASTER_SITES=	http://www.linuxmotors.com/gljewel/downloads/
DISTNAME=	${PORTNAME:S/sdl/SDL/}-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	nemysis@gmx.ch
COMMENT=	SDL Jewels is a tile-matching 8x8 puzzle game

LICENSE=	GPLv2

USE_SDL=	sdl image mixer
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes

PLIST_FILES=	bin/sdljewels

PORTDATA=	*
PORTDOCS=	ChangeLog README

ALL_TARGET=

post-patch:
	@${RM} -rf ${WRKSRC}/data/CVS
# Fix data location
	@${REINPLACE_CMD} -e 's!data/bigfont.ppm!${DATADIR}/data/bigfont.ppm!' \
	-e 's!dirlist\[\]="data";!dirlist[]="${DATADIR}/data";'! \
	-e 's!char name[256],!char name[512],!' \
	${WRKSRC}/gljewel.c ${WRKSRC}/sound.c
# Fix CFLAGS/LDFLAGS
	@${REINPLACE_CMD} -e 's!CFLAGS = -O2 -Wall!CFLAGS+=!' \
	-e 's!LDFLAGS =!LDFLAGS+=!' ${WRKSRC}/Makefile

do-install:
# Executable
	${INSTALL_PROGRAM} ${WRKSRC}/gljewel ${PREFIX}/bin/sdljewels
# Data
	(cd ${WRKSRC} && ${COPYTREE_SHARE} data ${DATADIR})

# Documentation
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
