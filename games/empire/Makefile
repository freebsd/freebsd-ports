# New ports collection makefile for:	empire
# Date created:				13 May 1997
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	empire
PORTVERSION=	1.9
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.catb.org/~esr/vms-empire/
DISTNAME=	vms-${PORTNAME}-${PORTVERSION}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Simulation of a full-scale war between two emperors

LICENSE=	GPLv2


MAN6=		empire.6

PORTDOCS=	AUTHORS BUGS NEWS README

PLIST_FILES=	bin/empire \
		share/pixmaps/empire.png

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's/^CFLAGS/#CFLAGS/ ; \
		 s/-lncurses/-lcurses/' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's/static void/void/g' ${WRKSRC}/game.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vms-empire ${PREFIX}/bin/empire
	${INSTALL_MAN} ${MAN6:S|^|${WRKSRC}/|} ${MAN6PREFIX}/man/man6
	${INSTALL_DATA} ${WRKSRC}/empire-logo.png ${PREFIX}/share/pixmaps/empire.png

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
