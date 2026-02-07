PORTNAME=	evolvotron
DISTVERSION=	0.8.1
PORTREVISION=	9
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION:R} \
		SF/nemysisfreebsdp/${CATEGORIES}/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}_icons${EXTRACT_SUFX}:icons

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Generative software that evolves images/textures/patterns
WWW=		http://www.bottlenose.net/share/evolvotron/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs

USES=		compiler:c++11-lib gl gnome python qmake qt:5
USE_CXXSTD=	c++11
USE_GL=		gl
USE_QT=		core gui widgets xml buildtools:build

QMAKE_ARGS=		VERSION_NUMBER="${PORTVERSION}"
QMAKE_SOURCE_PATH=	${WRKSRC}/main.pro

ICON_SIZES=	32x32 48x48 64x64 72x72 96x96 128x128
DESKTOP_ENTRIES=	"Evolvotron" \
			"Interactive image generator" \
			"${PORTNAME}" \
			"${PORTNAME}" \
			"Graphics;2DGraphics;" \
			""

PORTDOCS=	NEWS README.md TODO USAGE evolvotron.html
OPTIONS_DEFINE=	DOCS

do-install:
.for i in evolvotron evolvotron_mutate evolvotron_render
	${INSTALL_PROGRAM} ${WRKSRC}/obj/${i}/${i} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/man/man1/${i}.1 ${STAGEDIR}${PREFIX}/share/man/man1/
.endfor
.for s in ${ICON_SIZES}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}/apps/
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}_${s}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}/apps/${PORTNAME}.png
.endfor
	${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
