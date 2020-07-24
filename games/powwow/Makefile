# Created by: Juraj Lutter <otis@sk.freebsd.org>
# $FreeBSD$

PORTNAME=	powwow
PORTVERSION=	1.2.22
CATEGORIES=	games
MASTER_SITES=	https://hoopajoo.net/static/projects/ \
		https://ftp.sk.FreeBSD.org/pub/FreeBSD/local/distfiles/

MAINTAINER=	juraj@lutter.sk
COMMENT=	Client to play MUDs

LICENSE=	GPLv2

USES=		gmake ncurses
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-bsd

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	1

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/powwow ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/powwow-movieplay ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/powwow-muc ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/catrw ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/follow ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${MAN6PREFIX}/man/man6
	${INSTALL_MAN} ${WRKSRC}/man/powwow.6 ${STAGEDIR}${MAN6PREFIX}/man/man6
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/powwow.doc ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/powwow.help ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
