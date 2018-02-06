# $FreeBSD$

PORTNAME=	xpdf
PORTVERSION=	4.00
PORTEPOCH=	1
CATEGORIES=	graphics print
MASTER_SITES=	https://xpdfreader-dl.s3.amazonaws.com/
.if !defined(MASTERDIR)
PKGNAMESUFFIX=	4
CONFLICTS_INSTALL=	xpdf3-* xpdf-*
.else
CONFLICTS_INSTALL=	xpdf3-*	xpdf4-*
.endif

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Display PDF files and convert them to other formats

LICENSE=	GPLv2

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libpng.so:graphics/png

CONFLICTS_INSTALL=	xpdf

MANPREFIX=	${PREFIX}/share/xpdf
SUB_FILES=	xpdf-man.conf

USES=		cmake:outsource localbase
CMAKE_ARGS+=	-DOPI_SUPPORT:BOOL=ON -DCMAKE_DISABLE_FIND_PACKAGE_Qt4:BOOL=ON \
		-DUSE_LCMS:BOOL=OFF -DSYSTEM_XPDFRC=${PREFIX}/etc/xpdfrc

OPTIONS_DEFINE=		TYPE1 LIBPAPER GUI PRINT
OPTIONS_DEFAULT=	TYPE1 GUI PRINT
OPTIONS_SUB=		yes

TYPE1_CMAKE_BOOL=	TYPE1
TYPE1_DESC=		Ghostscript type1 fonts
TYPE1_RUN_DEPENDS=	${LOCALBASE}/share/ghostscript/fonts/d050000l.pfb:print/gsfonts

LIBPAPER_CMAKE_BOOL=	USE_LIBPAPER
LIBPAPER_LIB_DEPENDS=	libpaper.so:print/libpaper

GUI_CMAKE_ON=		-DCMAKE_DISABLE_FIND_PACKAGE_Qt5Widgets:BOOL=FALSE
GUI_CMAKE_OFF=		-DCMAKE_DISABLE_FIND_PACKAGE_Qt5Widgets:BOOL=TRUE
GUI_DESC=		QT5 interface
GUI_CMAKE_ARGS+=	-DNO_TEXT_SELECT:BOOL=OFF
GUI_USE=		QT5=buildtools_build,qmake_build,concurrent,core,gui,widgets,printsupport,svg

PRINT_CMAKE_ON=		-DXPDFWIDGET_PRINTING:BOOL=ON -DCUPS:BOOL=ON
PRINT_CMAKE_OFF=	-DXPDFWIDGET_PRINTING:BOOL=OFF -DCUPS:BOOL=OFF
PRINT_DESC=		 Print support (CUPS dependency)
PRINT_LDFLAGS=		-L${LOCALBASE}/lib
PRINT_LIB_DEPENDS=	libcups.so:print/cups

post-install:
		@cd ${STAGEDIR}${PREFIX}; \
		${LN} -sf ../libexec/xpdf/xpdf bin/xpdf

		${INSTALL_DATA} ${WRKSRC}/doc/sample-xpdfrc ${STAGEDIR}${PREFIX}/etc/xpdfrc.sample
		${INSTALL_DATA} ${WRKDIR}/xpdf-man.conf \
			${STAGEDIR}${PREFIX}/etc/man.d/xpdf.conf

.include <bsd.port.mk>
