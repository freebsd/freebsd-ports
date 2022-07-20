PORTNAME=	${GH_PROJECT:[1]:tl}
PORTVERSION=	0.03
CATEGORIES=	devel

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Cross-platform graphical PE file viewer/editor

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		desktop-file-utils pkgconfig qt:5
GNU_CONFIGURE=	yes
USE_QT=		buildtools_build linguisttools_build qmake_build \
		concurrent core gui opengl printsupport widgets
USE_GITHUB=	yes
GH_ACCOUNT=	horsicq
GH_PROJECT=	XPEViewer ${GH_SUBDIR}
GH_TAGNAME=	851bd20:c 7041d09:fd ef61592:fw f1c190b:f 8a59a1e:sa \
		c7a1c8c:ss 5c13737:xa bd1d8fc:xc d6e3eeb:xcf 3de4ac6:xdex \
		568419a:xd 87f781b:xdw 65db43d:xdv d20e51b:xew \
		a314278:xfi 33a3ccb:xhw 4f785b5:xhe fd3e26d:xhv \
		382a8b6:xmmw ee01f8d:xo 87672e3:xp f20ba0f:xq a803f01:xs \
		5f5c94c:xst 3b45183:s
GH_SUBDIR=	Controls:c FormatDialogs:fd FormatWidgets:fw Formats:f \
		SpecAbstract:sa StaticScan:ss XArchive:xa XCapstone:xc \
		XCppfilt:xcf XDEX:xdex XDemangle:xd XDemangleWidget:xdw \
		XDisasmView:xdv XEntropyWidget:xew XFileInfo:xfi \
		XHashWidget:xhw XHexEdit:xhe XHexView:xhv \
		XMemoryMapWidget:xmmw XOptions:xo XPDF:xp XQwt:xq \
		XShortcuts:xs XStyles:xst signatures:s

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
