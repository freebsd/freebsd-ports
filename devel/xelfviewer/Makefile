# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>

PORTNAME=	${GH_PROJECT:[1]:tl}
PORTVERSION=	0.03
CATEGORIES=	devel

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Cross-platform graphical ELF file viewer/editor

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		pkgconfig qt:5
GNU_CONFIGURE=	yes
USE_QT=		buildtools_build linguisttools_build qmake_build \
		concurrent core gui opengl printsupport widgets
USE_GITHUB=	yes
GH_ACCOUNT=	horsicq
GH_PROJECT=	XELFViewer ${GH_SUBDIR}
GH_TAGNAME=	1ae8d31:c ed0fba7:fd 65ef8ae:fw 0fbdbfb:f 0378c3d:sa \
		a0980b6:sc d5f5ce4:xa a9da5dd:xc 76405a6:xcf fa28140:xdex \
		c540d31:xd 10bc917:xdw 1a54d75:xdv 83db895:xew c4c41b8:xhw \
		c711a41:xhv 1f3f4c3:xmmw e0d2b0d:xo b0ffc17:xq 5d9d990:xs \
		1d23cca:xst 9fcacfa:s
GH_SUBDIR=	Controls:c FormatDialogs:fd FormatWidgets:fw Formats:f \
		SpecAbstract:sa StaticScan:sc XArchive:xa XCapstone:xc \
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
