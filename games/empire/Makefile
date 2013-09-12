# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	empire
PORTVERSION=	1.10
CATEGORIES=	games
MASTER_SITES=	http://www.catb.org/~esr/vms-empire/
DISTNAME=	vms-${PORTNAME}-${PORTVERSION}

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Simulation of a full-scale war between two emperors

LICENSE=	GPLv2

MAN6=		empire.6

PORTDOCS=	AUTHORS BUGS NEWS README

PLIST_FILES=	bin/empire \
		share/pixmaps/empire.png

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's/^CFLAGS/#CFLAGS/ ; \
		 s/-lncurses/-lcurses/' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's/static void/void/g' ${WRKSRC}/game.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vms-empire ${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${MAN6:S|^|${WRKSRC}/|} ${MAN6PREFIX}/man/man6
	${INSTALL_DATA} ${WRKSRC}/empire-logo.png ${PREFIX}/share/pixmaps/${PORTNAME}.png

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
