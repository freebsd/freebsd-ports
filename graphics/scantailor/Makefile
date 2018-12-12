# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	scantailor
PORTVERSION=	0.9.11.1
PORTREVISION=	15
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Interactive post-processing tool for scanned pages

LICENSE=	GPLv3

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

BROKEN_powerpc64=	fails to compile: core.hpp:69: boost::lambda::<unnamed>::_1 causes a section type conflict

BUILD_DEPENDS=	${LOCALBASE}/include/boost/shared_ptr.hpp:devel/boost-libs
LIB_DEPENDS=	libtiff.so:graphics/tiff \
		libjbig.so:graphics/jbigkit \
		libpng.so:graphics/png

#MAKE_JOBS_UNSAFE=	yes
USES=		cmake gettext jpeg qt:4
USE_CXXSTD=	gnu++98
USE_QT=		corelib gui xml qmake_build uic_build moc_build rcc_build \
		linguist_build
USE_XORG+=	xrender

DESKTOP_ENTRIES="Scan Tailor" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Graphics;Scanning;" false

OPTIONS_GROUP=	DOXYGEN

OPTIONS_GROUP_DOXYGEN=	HTML LATEX

OPTIONS_DEFAULT=

HTML_DESC=	Install HTML Doxygen files
LATEX_DESC=	Install LaTeX Doxygen files

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MHTML} || ${PORT_OPTIONS:MLATEX}
PORTDOCS=	*
.endif

.if ${PORT_OPTIONS:MHTML} || ${PORT_OPTIONS:MLATEX}
BUILD_DEPENDS+=	doxygen:devel/doxygen
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|_[12]|boost::lambda::&|g; s|bind(|boost::lambda::&|' \
		${WRKSRC}/filters/*/Filter.cpp

post-install:
	${INSTALL_DATA} ${WRKSRC}/resources/icons/appicon-about.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

.if ${PORT_OPTIONS:MHTML} || ${PORT_OPTIONS:MLATEX}
	@cd ${WRKSRC} && doxygen .
.endif

.if ${PORT_OPTIONS:MDOCS} && ${PORT_OPTIONS:MHTML}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR})
.endif

.if ${PORT_OPTIONS:MDOCS} && ${PORT_OPTIONS:MLATEX}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} latex ${STAGEDIR}${DOCSDIR})
.endif

.include <bsd.port.mk>
