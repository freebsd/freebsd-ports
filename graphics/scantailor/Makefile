# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	scantailor
PORTVERSION=	0.9.11.1
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	vg@FreeBSD.org
COMMENT=	Interactive post-processing tool for scanned pages

LICENSE=	GPLv3

LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg \
		tiff:${PORTSDIR}/graphics/tiff \
		jbig:${PORTSDIR}/graphics/jbigkit \
		png15:${PORTSDIR}/graphics/png
BUILD_DEPENDS=	${LOCALBASE}/include/boost/shared_ptr.hpp:${PORTSDIR}/devel/boost-libs

USES=		cmake gettext iconv
USE_GCC=	yes
USE_QT4=	gui xml qmake_build uic_build moc_build rcc_build \
		linguist_build

DESKTOP_ENTRIES="Scan Tailor" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Graphics;Scanning;" false

OPTIONS_GROUP=	DOXYGEN

OPTIONS_GROUP_DOXYGEN=	HTML LATEX

OPTIONS_DEFAULT=

HTML_DESC=	Install HTML Doxygen files
LATEX_DESC=	Install LaTeX Doxygen files

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MHTML} || ${PORT_OPTIONS:MLATEX}
PORTDOCS=	*
.endif

.if ${PORT_OPTIONS:MHTML} || ${PORT_OPTIONS:MLATEX}
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/resources/icons/appicon-about.png \
		${PREFIX}/share/pixmaps/${PORTNAME}.png

.if ${PORT_OPTIONS:MHTML} || ${PORT_OPTIONS:MLATEX}
	@cd ${WRKSRC} && doxygen .
.endif

.if ${PORT_OPTIONS:MDOCS} && ${PORT_OPTIONS:MHTML}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} html ${DOCSDIR})
.endif

.if ${PORT_OPTIONS:MDOCS} && ${PORT_OPTIONS:MLATEX}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} latex ${DOCSDIR})
.endif

.include <bsd.port.mk>
