# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rocksndiamonds
PORTVERSION=	3.3.0.1
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}.mirror \
		http://www.artsoft.org/RELEASES/unix/rocksndiamonds/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Colorful Boulderdash'n'Emerald Mine'n'Sokoban'n'Stuff

LICENSE=	GPLv2

OPTIONS_DEFINE=	SDL DOCS

USE_GMAKE=	yes
MAKE_ARGS=	CC="${CC}" MAKE="${GMAKE}" OPTIONS="${CFLAGS}" \
		RO_GAME_DIR="${DATADIR}" RW_GAME_DIR="${DATADIR}/scores" \
		X11_PATH="${LOCALBASE}"
MAKE_JOBS_SAFE=	yes

MAN1=		rocksndiamonds.1

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSDL}
LIB_DEPENDS+=	smpeg:${PORTSDIR}/multimedia/smpeg
USE_SDL=	image mixer net sdl
ALL_TARGET=	sdl
.else
USE_XORG=	x11 xpm xt
ALL_TARGET=	x11
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|sdl-config|$${SDL_CONFIG}|g' ${WRKSRC}/src/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rocksndiamonds ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/rocksndiamonds.1 ${MANPREFIX}/man/man1
	@${MKDIR} ${DATADIR}
.for dir in graphics levels music scores sounds
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${dir} ${DATADIR})
.endfor
	@${CHMOD} 777 ${DATADIR}/scores
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for docfile in ChangeLog CREDITS README
	${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
	@${MKDIR} ${DOCSDIR}/elements
	${INSTALL_DATA} ${WRKSRC}/docs/elements/*.txt ${DOCSDIR}/elements
.endif

.include <bsd.port.mk>
