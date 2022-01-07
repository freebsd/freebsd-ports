# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>

PORTNAME=	${GH_PROJECT:[1]:tl}
PORTVERSION=	0.02
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
GH_TAGNAME=	9f28798:c 04ad3bd:fd 4c280e7:fw 31f30d3:f 827056a:sa \
		4e10b78:ss 262acc3:xa 7b01fc0:xc 9a471e5:xcf 0eee644:xdex \
		c1f16dc:xd 0651e63:xdw 5e289ac:xdv 59db94d:xew 149d635:xhw \
		61378c6:xhv 9b0103f:xmmw 0e9e3e5:xo b0ffc17:xq a58955c:xs \
		1d23cca:xst 9fcacfa:s
GH_SUBDIR=	Controls:c FormatDialogs:fd FormatWidgets:fw Formats:f \
		SpecAbstract:sa StaticScan:ss XArchive:xa XCapstone:xc \
		XCppfilt:xcf XDEX:xdex XDemangle:xd XDemangleWidget:xdw \
		XDisasmView:xdv XEntropyWidget:xew XHashWidget:xhw \
		XHexView:xhv XMemoryMapWidget:xmmw XOptions:xo XQwt:xq \
		XShortcuts:xs XStyles:xst signatures:s

post-extract:
	@${CHMOD} +x ${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

post-build:
	@cd ${WRKSRC}/gui_source && ${LUPDATE} gui_source_tr.pro
	@${LRELEASE} ${WRKSRC}/gui_source/translation/*.ts

do-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/build/release/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin
	cd ${INSTALL_WRKSRC}/DEBIAN && ${COPYTREE_SHARE} hicolor \
		${STAGEDIR}${PREFIX}/share/icons
	${SED} -e 's,#VERSION#,${PORTVERSION},' \
		${WRKSRC}/DEBIAN/${PORTNAME}.desktop > \
		${STAGEDIR}${PREFIX}/share/applications/${PORTNAME}.desktop
	cd ${WRKSRC_xst} && ${COPYTREE_SHARE} qss ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DATADIR}/lang
	${INSTALL_DATA} ${INSTALL_WRKSRC}/gui_source/translation/*.qm \
		${STAGEDIR}${DATADIR}/lang
	@${MKDIR} ${STAGEDIR}${DATADIR}/signatures
	${INSTALL_DATA} ${WRKSRC_s}/crypto.db ${STAGEDIR}${DATADIR}/signatures

.include <bsd.port.mk>

PATCH_ARGS+=	-l
