PORTNAME=	scantailor
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.19
CATEGORIES=	graphics

MAINTAINER=	m.ne@gmx.net
COMMENT=	Interactive post-processing tool for scanned pages
WWW=		https://github.com/ScanTailor-Advanced/scantailor-advanced

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/boost/shared_ptr.hpp:devel/boost-libs
LIB_DEPENDS=	libjbig.so:graphics/jbigkit \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff

USES=		cmake compiler:c++11-lang desktop-file-utils jpeg qt:5 \
		shared-mime-info xorg
USE_CXXSTD=	gnu++98
USE_GITHUB=	yes
USE_QT=		core gui network opengl svg widgets xml buildtools:build \
		linguisttools:build qmake:build
USE_XORG+=	xrender

GH_ACCOUNT=	ScanTailor-Advanced
GH_PROJECT=	scantailor-advanced
OPTIONS_GROUP=	DOXYGEN

OPTIONS_GROUP_DOXYGEN=	HTML LATEX

OPTIONS_DEFAULT=

HTML_DESC=	Install HTML Doxygen files
LATEX_DESC=	Install LaTeX Doxygen files

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MHTML} || ${PORT_OPTIONS:MLATEX}
PORTDOCS=	*
.endif

.if ${PORT_OPTIONS:MHTML} || ${PORT_OPTIONS:MLATEX}
BUILD_DEPENDS+=	doxygen:devel/doxygen
.endif

post-patch-NLS-off:
	@${REINPLACE_CMD} -e '/\/translations/s/install/# install/' ${WRKSRC}/CMakeLists.txt

post-install:
	${INSTALL_DATA} ${WRKSRC}/src/resources/ScanTailor.png \
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
