# $FreeBSD$

PORTNAME=	xpdf
PORTVERSION=	4.02
PORTEPOCH=	1
CATEGORIES=	graphics print
MASTER_SITES=	https://xpdfreader-dl.s3.amazonaws.com/
.if !defined(MASTERDIR)
PKGNAMESUFFIX=	4
.endif

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Display PDF files and convert them to other formats

LICENSE=	GPLv2

CONFLICTS_INSTALL=	xpdf
.if !defined(MASTERDIR)
CONFLICTS_INSTALL+=	xpdf3-* xpdf-*
.else
CONFLICTS_INSTALL+=	xpdf3-*	xpdf4-*
.endif

USES=		compiler:c++11-lang cmake localbase:ldflags
LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libpng.so:graphics/png
BUILD_DEPENDS=	${LOCALBASE}/share/ghostscript/fonts/d050000l.pfb:print/gsfonts
RUN_DEPENDS=	${LOCALBASE}/share/ghostscript/fonts/d050000l.pfb:print/gsfonts
MANPREFIX=	${PREFIX}/share/xpdf
SUB_FILES=	xpdf-man.conf
CMAKE_ARGS+=	-DOPI_SUPPORT:BOOL=ON -DCMAKE_DISABLE_FIND_PACKAGE_Qt4:BOOL=ON \
		-DUSE_LCMS:BOOL=OFF -DSYSTEM_XPDFRC=${PREFIX}/etc/xpdfrc \
		-DCMAKE_INSTALL_PREFIX=${PREFIX} \
		-DCMAKE_INSTALL_BINDIR=${PREFIX}/libexec/xpdf \
		-DCMAKE_INSTALL_MANDIR=${PREFIX}/share/xpdf/man \
		-DNO_TEXT_SELECT:BOOL=OFF \
		-DCMAKE_DISABLE_FIND_PACKAGE_Qt5Widgets:BOOL=FALSE

PLIST_SUB=		DESKTOPDIR="${DESKTOPDIR}"

OPTIONS_DEFINE=		FONTCONFIG GUI LIBPAPER PRINT TYPE1
OPTIONS_DEFAULT=	FONTCONFIG GUI PRINT TYPE1
OPTIONS_SUB=		yes

TYPE1_CMAKE_BOOL=	TYPE1
TYPE1_DESC=		Ghostscript type1 fonts
TYPE1_RUN_DEPENDS=	${LOCALBASE}/share/ghostscript/fonts/d050000l.pfb:print/gsfonts

LIBPAPER_CMAKE_BOOL=	USE_LIBPAPER
LIBPAPER_LIB_DEPENDS=	libpaper.so:print/libpaper

GUI_CMAKE_OFF=		-DCMAKE_DISABLE_FIND_PACKAGE_Qt5Widgets=1
GUI_DESC=		QT5 interface
GUI_USES=		qt:5 desktop-file-utils
GUI_USE=		QT=buildtools_build,qmake_build,concurrent,core,gui,widgets,printsupport,svg,network,printsupport

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

.include <bsd.port.mk>
