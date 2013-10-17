# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xgalaga++
PORTVERSION=	0.8.4
CATEGORIES=	games
MASTER_SITES=	http://marc.mongenet.ch/OSS/XGalaga/ \
		SF/nemysisfreebsdp/:icons
DISTFILES=	${PORTNAME}_${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
EXTRACT_ONLY=	${PORTNAME}_${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Classic single screen vertical shoot em up

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		gmake
ALL_TARGET=	${PORTNAME}
USE_XORG=	x11 xpm
MAN6=		xgalaga++.6

SUB_FILES=	pkg-install

PLIST_FILES=	bin/${PORTNAME} \
		share/pixmaps/${PORTNAME}.png

PORTDOCS=	README

DESKTOP_ENTRIES="XGalaga++" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" false

OPTIONS_DEFINE=	DOCS

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e '/^CXX =/ d; s|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/xgalaga++.6x ${MAN6PREFIX}/man/man6/xgalaga++.6
	@${CHGRP} games ${PREFIX}/bin/${PORTNAME}
	@${CHMOD} g+s ${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png ${PREFIX}/share/pixmaps/

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
