# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vitetris
PORTVERSION=	0.58.0
DISTVERSIONPREFIX=	v
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Terminal-based Tetris clone in vein of Nintendo Tetris

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/licence.txt

USE_GITHUB=	yes
GH_ACCOUNT=	vicgeralds

USES=		ncurses
HAS_CONFIGURE=	yes
ALL_TARGET=	#
CONFIGURE_ARGS=	--prefix=${PREFIX} --datarootdir=${PREFIX}/share \
		curses="-lncurses" xlib=no
MAKE_ENV=	HISCORE_FILENAME=/var/games/vitetris-hiscores
MAKE_JOBS_UNSAFE=	yes

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tetris ${STAGEDIR}${PREFIX}/bin/vitetris
	${INSTALL_DATA} ${WRKSRC}/vitetris.xpm ${STAGEDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/vitetris.desktop ${STAGEDIR}${PREFIX}/share/applications
	@${MKDIR} ${STAGEDIR}/var/games
	${TOUCH} ${STAGEDIR}/var/games/vitetris-hiscores.sample

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/changes.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
