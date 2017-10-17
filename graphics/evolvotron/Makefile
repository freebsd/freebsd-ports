# Created by: David Yeske <dyeske@gmail.com>
# $FreeBSD$

PORTNAME=	evolvotron
PORTVERSION=	0.6.3
PORTREVISION=	7
CATEGORIES=	graphics
MASTER_SITES=	SF \
		SF/nemysisfreebsdp/${CATEGORIES}/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}_icons${EXTRACT_SUFX}:icons

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generative software that evolves images/textures/patterns

LICENSE=	GPLv3+ # LICENSE file is GPLv2 though

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		python qmake
USE_QT4=	corelib gui xml moc_build
QMAKE_ARGS=	VERSION_NUMBER="${PORTVERSION}"
QMAKE_SOURCE_PATH=	${WRKSRC}/main.pro
MAKE_JOBS_UNSAFE=	yes

PORTDOCS=	NEWS README TODO USAGE evolvotron.html

INSTALLS_ICONS=	yes
ICON_SIZES=	32x32 48x48 64x64 72x72 96x96 128x128

DESKTOP_ENTRIES="Evolvotron" "Interactive image generator" "${PORTNAME}" \
		"${PORTNAME}" "Graphics;2DGraphics;" ""

OPTIONS_DEFINE=	DOCS

.for i in libevolvotron libfunction
CXXFLAGS+=	-include ${WRKSRC}/${i}/${i}_precompiled.h
.endfor

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

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
