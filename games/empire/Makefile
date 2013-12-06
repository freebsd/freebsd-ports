# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	empire
PORTVERSION=	1.10
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.catb.org/~esr/vms-empire/
DISTNAME=	vms-${PORTNAME}-${PORTVERSION}

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Simulation of a full-scale war between two emperors

LICENSE=	GPLv2

PORTDOCS=	AUTHORS BUGS NEWS README

OPTIONS_DEFINE=	DOCS

PLIST_FILES=	bin/${PORTNAME} \
		man/man6/${PORTNAME}.6.gz \
		share/applications/${PORTNAME}.desktop \
		share/pixmaps/${PORTNAME}.png

post-patch:
	@${REINPLACE_CMD} -e 's/^CFLAGS/#CFLAGS/ ; \
		 s/-lncurses/-lcurses/' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's/static void/void/g' ${WRKSRC}/game.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vms-empire ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}.desktop ${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/empire-logo.png ${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.6 ${STAGEDIR}${MAN6PREFIX}/man/man6/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
