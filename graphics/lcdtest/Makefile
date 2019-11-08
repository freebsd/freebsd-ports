# Created by: Eric P. Scott <eps+pbug0703@ana.com>
# $FreeBSD$

PORTNAME=	lcdtest
PORTVERSION=	1.18
PORTREVISION=	10
CATEGORIES=	graphics
MASTER_SITES=	http://www.brouhaha.com/~eric/software/lcdtest/download/ \
		SF/nemysisfreebsdp/${CATEGORIES}/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	LCD monitor test pattern generator

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	liberation-fonts-ttf>0:x11-fonts/liberation-fonts-ttf

USES=		sdl
USE_SDL=	sdl image ttf

PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz \
		share/applications/${PORTNAME}.desktop \
		share/pixmaps/${PORTNAME}.png

PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/share/fonts/liberation/|${LOCALBASE}/share/fonts/Liberation/|' \
		${WRKSRC}/src/lcdtest.c

do-build:
	cd ${WRKSRC}/src && \
		${CC} ${CFLAGS} ${LDFLAGS} `sdl-config --cflags --libs` \
			-DRELEASE=${PORTVERSION} \
			-lSDL_image -lSDL_ttf \
			-o lcdtest lcdtest.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/man/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/
	${INSTALL_DATA} ${WRKSRC}/desktop/${PORTNAME}.desktop \
		${STAGEDIR}${DESKTOPDIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
