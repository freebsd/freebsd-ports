PORTNAME=	xpdf
PORTVERSION=	4.06
PORTEPOCH=	1
CATEGORIES=	graphics print
MASTER_SITES=	https://dl.xpdfreader.com/

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Display PDF files and convert them to other formats
WWW=		https://www.xpdfreader.com/

LICENSE=	GPLv2

CONFLICTS_INSTALL=	xpdf
.if !defined(MASTERDIR)
CONFLICTS_INSTALL+=	xpdf3 xpdf
.else
CONFLICTS_INSTALL+=	xpdf3 xpdf4
.endif

FLAVORS=	qt5 qt6
FLAVOR?=	${FLAVORS:[1]}
.if !defined(MASTERDIR)
qt5_PKGNAMESUFFIX=	4
qt6_PKGNAMESUFFIX=	4-qt6
qt5_CONFLICTS_INSTALL=  ${PORTNAME}4-qt6
qt6_CONFLICTS_INSTALL=  ${PORTNAME}4
.else
qt5_PKGNAMESUFFIX=
qt6_PKGNAMESUFFIX=	-qt6
qt5_CONFLICTS_INSTALL=  ${PORTNAME}-qt6
qt6_CONFLICTS_INSTALL=  ${PORTNAME}
.endif

USES=		compiler:c++11-lang cmake cpe localbase:ldflags
LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libpng.so:graphics/png \
		libfontconfig.so:x11-fonts/fontconfig
BUILD_DEPENDS=	${LOCALBASE}/share/ghostscript/fonts/d050000l.pfb:print/gsfonts
RUN_DEPENDS=	${LOCALBASE}/share/ghostscript/fonts/d050000l.pfb:print/gsfonts
MANDIRS=	${PREFIX}/share/xpdf/man
SUB_FILES=	xpdf-man.conf
CMAKE_ARGS+=	-DOPI_SUPPORT:BOOL=ON -DCMAKE_DISABLE_FIND_PACKAGE_Qt4:BOOL=ON \
		-DUSE_LCMS:BOOL=OFF -DSYSTEM_XPDFRC=${PREFIX}/etc/xpdfrc \
		-DCMAKE_INSTALL_PREFIX=${PREFIX} \
		-DCMAKE_INSTALL_BINDIR=${PREFIX}/libexec/xpdf \
		-DCMAKE_INSTALL_MANDIR=${PREFIX}/share/xpdf/man \
		-DNO_TEXT_SELECT:BOOL=OFF
CPE_VENDOR=	xpdfreader

PLIST_SUB=		DESKTOPDIR="${DESKTOPDIR}"

OPTIONS_DEFINE=		FONTCONFIG GUI LIBPAPER PRINT TYPE1
OPTIONS_DEFAULT=	FONTCONFIG GUI PRINT TYPE1
OPTIONS_SUB=		yes

TYPE1_CMAKE_BOOL=	TYPE1
TYPE1_DESC=		Ghostscript type1 fonts
TYPE1_RUN_DEPENDS=	${LOCALBASE}/share/ghostscript/fonts/d050000l.pfb:print/gsfonts

LIBPAPER_CMAKE_BOOL=	USE_LIBPAPER
LIBPAPER_LIB_DEPENDS=	libpaper.so:print/libpaper

GUI_DESC=		GUI interface
GUI_USES=		desktop-file-utils

.if ${FLAVOR} == qt5
USES+=		qt:5
GUI_USE=	QT=buildtools:build,qmake:build,concurrent,core,gui,network,printsupport,svg,widgets
CMAKE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_Qt5Widgets:BOOL=FALSE \
		-DCMAKE_DISABLE_FIND_PACKAGE_Qt6Widgets:BOOL=ON
.else
USES+=		qt:6
GUI_USE=	QT=base,tools:build
CMAKE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_Qt5Widgets:BOOL=ON \
		-DCMAKE_DISABLE_FIND_PACKAGE_Qt6Widgets:BOOL=FALSE
.endif

PRINT_CMAKE_ON=		-DXPDFWIDGET_PRINTING:BOOL=ON -DCUPS:BOOL=ON
PRINT_CMAKE_OFF=	-DXPDFWIDGET_PRINTING:BOOL=OFF -DCUPS:BOOL=OFF
PRINT_DESC=		Print support (CUPS dependency)
PRINT_LDFLAGS=		-L${LOCALBASE}/lib
PRINT_LIB_DEPENDS=	libcups.so:print/cups

FONTCONFIG_DESC=		Enable use of libfontconfig (not for XFCE)
FONTCONFIG_IMPLIES=		GUI
FONTCONFIG_CMAKE_BOOL_OFF=	NO_FONTCONFIG

post-install:
		@cd ${STAGEDIR}${PREFIX}; \
		${LN} -sf ../libexec/xpdf/xpdf bin/xpdf
		${INSTALL_DATA} ${WRKSRC}/doc/sample-xpdfrc ${STAGEDIR}${PREFIX}/etc/xpdfrc.sample
		${INSTALL_DATA} ${WRKDIR}/xpdf-man.conf \
			${STAGEDIR}${PREFIX}/etc/man.d/xpdf.conf
		${INSTALL_DATA} ${FILESDIR}/xpdf.desktop ${STAGEDIR}${DESKTOPDIR}
		${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/256x256
		${INSTALL_DATA} ${WRKSRC}/xpdf-qt/xpdf-icon.ico ${STAGEDIR}${PREFIX}/share/icons/hicolor/256x256/xpdf.png
		${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable
		${INSTALL_DATA} ${WRKSRC}/xpdf-qt/xpdf-icon.svg ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/xpdf.svg

.include <bsd.port.mk>
