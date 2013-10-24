# Created by: Aaron Zauner <az_mail@gmx.at>
# $FreeBSD$

PORTNAME=	aop
PORTVERSION=	0.6
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/nemysisfreebsdp/${CATEGORIES}/${PORTNAME}/
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Ncurses based arcade game with only 64 lines of code

LICENSE=	GPLv2

RUN_DEPENDS=	xterm:${PORTSDIR}/x11/xterm

ALL_TARGET=	#empty

PORTDOCS=	README

DESKTOP_ENTRIES+="Ambassador of Pain" "${COMMENT}" ${PORTNAME} \
		"xterm -e ${PORTNAME}" "Game;LogicGame;" false

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${STAGEDIR}${PREFIX}|g' \
		${WRKSRC}/Makefile

post-install:
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png ${STAGEDIR}${PREFIX}/share/pixmaps/

	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
