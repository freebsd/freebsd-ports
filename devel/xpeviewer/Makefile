PORTNAME=	${GH_PROJECT:[1]:tl}
PORTVERSION=	0.04
CATEGORIES=	devel

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Cross-platform graphical PE file viewer/editor
WWW=		https://github.com/horsicq/XPEViewer

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		desktop-file-utils pkgconfig qt:5
GNU_CONFIGURE=	yes
USE_QT=		buildtools:build linguisttools:build qmake:build \
		concurrent core gui opengl network printsupport widgets
USE_GITHUB=	yes
GH_ACCOUNT=	horsicq
GH_PROJECT=	XPEViewer ${GH_SUBDIR}
GH_TAGNAME=	fee875c:c d55bbc5:fd d016978:fw 8734c1f:f 3085682:sa \
		d47ee1a:ss b3b2a0e:xaw 25fbd58:xa c4bb949:xc 24d3559:xcf \
		eaa05c8:xdex 09da781:xd 1e0a59b:xdw 75200aa:xdv \
		5c41416:xew f631741:xfi 0813fdd:xhw e18a5ae:xhe \
		f2af7f8:xhv 0cad087:xidb 8b6ef00:xmmw ed26781:xot \
		f0c7af4:xo 2dc4373:xp 2290f6a:xq 1774308:xs \
		1c55034:xst 0adeea3:xsw d6312c6:s
GH_SUBDIR=	Controls:c FormatDialogs:fd FormatWidgets:fw Formats:f \
		SpecAbstract:sa StaticScan:ss XAboutWidget:xaw XArchive:xa \
		XCapstone:xc XCppfilt:xcf XDEX:xdex XDemangle:xd \
		XDemangleWidget:xdw XDisasmView:xdv XEntropyWidget:xew \
		XFileInfo:xfi XHashWidget:xhw XHexEdit:xhe XHexView:xhv \
		XInfoDB:xidb XMemoryMapWidget:xmmw XOnlineTools:xot \
		XOptions:xo XPDF:xp XQwt:xq XShortcuts:xs XStyles:xst \
		XSymbolsWidget:xsw signatures:s

post-extract:
	@${CHMOD} +x ${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

post-patch:
	@${REINPLACE_CMD} -e '/checking for Qt5Sql/,+70d' ${WRKSRC}/configure

post-build:
	@cd ${WRKSRC}/gui_source && ${LUPDATE} gui_source_tr.pro
	@${LRELEASE} ${WRKSRC}/gui_source/translation/*.ts

do-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/build/release/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin
	cd ${INSTALL_WRKSRC}/LINUX && ${COPYTREE_SHARE} hicolor \
		${STAGEDIR}${PREFIX}/share/icons
	${SED} -e 's,#VERSION#,${PORTVERSION},' \
		${WRKSRC}/LINUX/${PORTNAME}.desktop > \
		${STAGEDIR}${PREFIX}/share/applications/${PORTNAME}.desktop
	cd ${WRKSRC_xst} && ${COPYTREE_SHARE} qss ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DATADIR}/lang
	${INSTALL_DATA} ${INSTALL_WRKSRC}/gui_source/translation/*.qm \
		${STAGEDIR}${DATADIR}/lang
	@${MKDIR} ${STAGEDIR}${DATADIR}/signatures
	${INSTALL_DATA} ${WRKSRC_s}/crypto.db ${STAGEDIR}${DATADIR}/signatures

.include <bsd.port.mk>

PATCH_ARGS+=	-l
