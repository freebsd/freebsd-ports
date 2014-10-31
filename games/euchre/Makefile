# Created by: Frank Laszlo <laszlof@freebsdmatrix.net>
# $FreeBSD$

PORTNAME=	euchre
PORTVERSION=	0.8
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION} \
		SF/nemysisfreebsdp/${CATEGORIES}/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Very popular card game with variable skill levels

LICENSE=	GPLv2

USES=		pkgconfig
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-silent-rules

PLIST_FILES=	bin/${PORTNAME} \
		share/pixmaps/${PORTNAME}.png

PORTDOCS=	AUTHORS ChangeLog README
OPTIONS_DEFINE=	DOCS

DESKTOP_ENTRIES="Euchre" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;CardGame;" ""

post-patch:
	@${REINPLACE_CMD} -e \
		'/^AM_/s|-Werror||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|int)|long int)|g' \
		${WRKSRC}/src/gui/callbacks.cpp ${WRKSRC}/src/lib/Game.cpp

post-install:
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
