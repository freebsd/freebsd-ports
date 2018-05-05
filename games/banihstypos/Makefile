# Created by: Philippe Audeoud <jadawin@tuxaco.net>
# $FreeBSD$

PORTNAME=	banihstypos
PORTVERSION=	0.2
CATEGORIES=	games
MASTER_SITES=	http://www.vanheusden.com/banihstypos/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	Banihstypos is a simple game to teach you typing, FAST

USES=		ncurses
MAKE_ARGS=	LDFLAGS="${LDFLAGS} -lncurses"
SUB_FILES=	pkg-message
SUB_LIST=	PORTNAME=${PORTNAME}

PLIST_FILES=	bin/banihstypos

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MDOCS}
PORTDOCS=	readme.txt
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/banihstypos ${STAGEDIR}${PREFIX}/bin
.if ! ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
