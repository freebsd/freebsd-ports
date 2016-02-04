# Created by: glewis@FreeBSD.org
# $FreeBSD$

PORTNAME=	moria
PORTVERSION=	5.5.2
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.funet.fi/pub/unix/games/moria/source/ \
		ftp://ftp.greyhelm.com/pub/Games/Moria/source/
DISTNAME=	um${PORTVERSION}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	Dungeon exploration game

USES=		alias ncurses
WRKSRC=		${WRKDIR}/umoria
ALL_TARGET=	moria
MAKE_ARGS=	CURSES="${LDFLAGS} -lncurses"
MAKE_ENV+=	DOCSDIR="${DOCSDIR}" MKDIR="${MKDIR}" TOUCH="${TOUCH}" \
		STAGEDIR="${STAGEDIR}" DATADIR="${DATADIR}"

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

do-configure:
	${REINPLACE_CMD} -e "s:%%DATADIR%%:${DATADIR}:g" ${WRKSRC}/source/config.h
	cd ${WRKSRC} && ${LN} -sf source/* unix/* .

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/moria.6 ${STAGEDIR}${PREFIX}/man/man6/

post-install-DOCS-on:
	cd ${WRKSRC}/doc && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} install

.include <bsd.port.mk>
