# Created by: Juraj Lutter <otis@sk.freebsd.org>
# $FreeBSD$

PORTNAME=	powwow
PORTVERSION=	1.2.17
CATEGORIES=	games
MASTER_SITES=	http://hoopajoo.net/static/projects/ \
		ftp://ftp.wilbury.sk/pub/FreeBSD/local/distfiles/

MAINTAINER=	otis@sk.FreeBSD.org
COMMENT=	Client to play MUDs

USES=		ncurses
GNU_CONFIGURE=	yes

pre-build:
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|' ${WRKSRC}/defines.h \
		${WRKSRC}/list.c ${WRKSRC}/main.c ${WRKSRC}/cmd2.c ${WRKSRC}/beam.c
	@${REINPLACE_CMD} -e 's|^DEFS = |DEFS = -DPOSIX |' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/powwow ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/powwow-movieplay ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/powwow-muc ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/catrw ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/follow ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/powwow.6 ${STAGEDIR}${PREFIX}/man/man6
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/powwow.doc ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/powwow.help ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
