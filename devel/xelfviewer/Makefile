PORTNAME=	${GH_PROJECT:[1]:tl}
PORTVERSION=	0.05
CATEGORIES=	devel

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Cross-platform graphical ELF file viewer/editor

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		pkgconfig qt:5
GNU_CONFIGURE=	yes
USE_QT=		buildtools_build linguisttools_build qmake_build \
		concurrent core gui opengl printsupport sql widgets
USE_GITHUB=	yes
GH_ACCOUNT=	horsicq
GH_PROJECT=	XELFViewer ${GH_SUBDIR}
GH_TAGNAME=	8448386:c f4cd98d:fd a065f9a:fw a448cac:f fc10bcd:sa \
		809fb94:ss 127005b:xa 0585048:xc 8e98be9:xcf 15a40bf:xdex \
		2df3dd7:xd 1e0a59b:xdw cd38fa1:xdv a68562e:xew fa65f99:xfi \
		e540a4f:xhw 52261be:xhe c32b205:xhv e8ddc3f:xidb \
		fad1473:xmmw 8bfcd52:xo 2dc4373:xp 2290f6a:xq b09d881:xs \
		1c55034:xst e13c104:xsw d6312c6:s
GH_SUBDIR=	Controls:c FormatDialogs:fd FormatWidgets:fw Formats:f \
		SpecAbstract:sa StaticScan:ss XArchive:xa XCapstone:xc \
		XCppfilt:xcf XDEX:xdex XDemangle:xd XDemangleWidget:xdw \
		XDisasmView:xdv XEntropyWidget:xew XFileInfo:xfi \
		XHashWidget:xhw XHexEdit:xhe XHexView:xhv XInfoDB:xidb \
		XMemoryMapWidget:xmmw XOptions:xo XPDF:xp XQwt:xq \
		XShortcuts:xs XStyles:xst XSymbolsWidget:xsw signatures:s

post-extract:
	@${CHMOD} +x ${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

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
