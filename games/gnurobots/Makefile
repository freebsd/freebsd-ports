# Created by: Aaron VonderHaar <avh4@usa.net>
# $FreeBSD$

PORTNAME=	gnurobots
PORTVERSION=	1.2.0
PORTREVISION=	10
CATEGORIES=	games
MASTER_SITES=	GNU \
		SF/nemysisfreebsdp/${CATEGORIES}/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU diversion wherein Scheme-coded robots explore a world

LICENSE=	GPLv3

LIB_DEPENDS=	libguile.so:${PORTSDIR}/lang/guile

USES=		pkgconfig readline
USE_GNOME=	vte
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS} -w
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

PORTDOCS=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	AUTHORS ChangeLog NEWS README THANKS

DOCSRCDIR2=	${WRKSRC}/doc
DOCSDIR2=	${DOCSDIR}/doc
DOC_FILES2=	Robots-HOWTO contrib

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

	@${MKDIR} ${STAGEDIR}${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${STAGEDIR}${DOCSDIR2}

.include <bsd.port.mk>
