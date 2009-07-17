# New ports collection makefile for:	rezerwar
# Date created:		09 Jul 2009
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rezerwar
PORTVERSION=	0.2
CATEGORIES=	games
MASTER_SITES=	http://tamentis.com/projects/rezerwar/files/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Puzzle game involving organizing blocks with pipes

USE_GMAKE=	yes
USE_SDL=	sdl mixer
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	Unix
MAKE_JOBS_SAFE=	yes

PORTDOCS=	README

post-patch:
	@${REINPLACE_CMD} -e 's|make|$${MAKE}|' ${WRKSRC}/mkfiles/Makefile.unix \
		${WRKSRC}/data/Makefile ${WRKSRC}/data/gfx/Makefile
	@${REINPLACE_CMD} -e 's|/usr/share/games/rezerwar/data|${DATADIR}|' \
		${WRKSRC}/mkfiles/config_h_unix
	@${REINPLACE_CMD} -e 's|hiscore.dat|.rezerwar.hiscore|' \
		${WRKSRC}/src/hiscore.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/rezerwar ${PREFIX}/bin/
	${MKDIR} ${DATADIR}/gfx
	cd ${WRKSRC}/data/gfx && ${COPYTREE_SHARE} . ${DATADIR}/gfx "-name *\.bmp"
	${MKDIR} ${DATADIR}/sfx
	${INSTALL_DATA} ${WRKSRC}/data/sfx/*.wav ${DATADIR}/sfx/
	${MKDIR} ${DATADIR}/music
	${INSTALL_DATA} ${WRKSRC}/data/music/*.mp3 ${DATADIR}/music/
	${MKDIR} ${DATADIR}/levels
	${INSTALL_DATA} ${WRKSRC}/data/levels/*.lvl ${DATADIR}/levels/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
