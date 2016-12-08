# Created by: Aaron VonderHaar <avh4@usa.net>
# $FreeBSD$

PORTNAME=	gnurobots
PORTVERSION=	1.2.0
PORTREVISION=	11
CATEGORIES=	games
MASTER_SITES=	GNU \
		SF/nemysisfreebsdp/${CATEGORIES}/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU diversion wherein Scheme-coded robots explore a world

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libguile.so:lang/guile

USES=		pkgconfig readline
USE_GNOME=	vte
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include -w
LDFLAGS+=	-L${LOCALBASE}/lib -pthread

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

SUB_FILES=	pkg-install pkg-message

DESKTOP_ENTRIES="GNU Robots" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" ""

post-patch:
	@${REINPLACE_CMD} -e 's|^CFLAGS=|#CFLAGS=|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|#include <pty.h>||g' ${WRKSRC}/src/ui-cmdwin.c
	@${REINPLACE_CMD} -E 's,(readline.h|history.h),readline/\1,' ${WRKSRC}/src/ui-cmdwin.c

post-install:
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/
	cd ${WRKSRC} && ${COPYTREE_SHARE} "AUTHORS ChangeLog NEWS README THANKS \
		doc/Robots-HOWTO doc/contrib" ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
