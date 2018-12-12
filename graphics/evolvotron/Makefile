# Created by: David Yeske <dyeske@gmail.com>
# $FreeBSD$

PORTNAME=	evolvotron
DISTVERSION=	0.7.1
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	SF \
		SF/nemysisfreebsdp/${CATEGORIES}/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}_icons${EXTRACT_SUFX}:icons

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generative software that evolves images/textures/patterns

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs

USES=		compiler:c++11-lib python qmake qt:5
USE_QT=		core gui widgets xml buildtools_build
USE_GL=		gl
QMAKE_ARGS=	VERSION_NUMBER="${PORTVERSION}"
QMAKE_SOURCE_PATH=	${WRKSRC}/main.pro
USE_CXXSTD=	c++11

WRKSRC=		${WRKDIR}/${PORTNAME}

INSTALLS_ICONS=	yes
ICON_SIZES=	32x32 48x48 64x64 72x72 96x96 128x128

DESKTOP_ENTRIES="Evolvotron" "Interactive image generator" "${PORTNAME}" \
		"${PORTNAME}" "Graphics;2DGraphics;" ""

OPTIONS_DEFINE=	DOCS

PORTDOCS=	NEWS README TODO USAGE evolvotron.html

post-patch:
	@${REINPLACE_CMD} -e \
		'/^CONFIG/s|precompile_header|| ; \
		 /DEFINES/s|_LINUX|_BSD|' ${WRKSRC}/common.pro

do-install:
.for i in evolvotron evolvotron_mutate evolvotron_render
	${INSTALL_PROGRAM} ${WRKSRC}/${i}/${i} ${STAGEDIR}${PREFIX}/bin/
.endfor
.for lib in libevolvotron libfunction
	${INSTALL_DATA} ${WRKSRC}/${lib}/${lib}.a ${STAGEDIR}${PREFIX}/lib/
.endfor
.for s in ${ICON_SIZES}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}/apps/
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}_${s}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}/apps/${PORTNAME}.png
.endfor
	${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/
.for m in evolvotron.1 evolvotron_mutate.1 evolvotron_render.1
	cd ${WRKSRC}/man/man1 && ${INSTALL_MAN} ${m} \
		${STAGEDIR}${MAN1PREFIX}/man/man1/
.endfor

post-install: # delete static libs installed by mistake
	@${RM} -r ${STAGEDIR}${PREFIX}/lib

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
