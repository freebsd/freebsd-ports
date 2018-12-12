# $FreeBSD$

PORTNAME=	designer
DISTVERSION=	${QT5_VERSION}
PORTREVISION=	2
CATEGORIES=	devel
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt 5 graphical user interface designer

USE_QT=		assistant_run core declarative gui network printsupport uiplugin \
		widgets xml buildtools_build
USES=		compiler:c++11-lang qmake qt-dist:5,tools
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

DESKTOP_ENTRIES="Qt 5 Designer" "" \
		"${PREFIX}/share/pixmaps/designer-qt5.png" \
		"${PREFIX}/${QT_BINDIR_REL}/designer" \
		"Development;Qt;" true

BUILD_WRKSRC=	${WRKSRC}/src/${PORTNAME}
INSTALL_WRKSRC=	${WRKSRC}/src/${PORTNAME}

OPTIONS_DEFINE=	WEBKIT
OPTIONS_SUB=	yes
WEBKIT_DESC=	Build WebKit-based WebView widget
WEBKIT_QMAKE_ON=	CONFIG+=use_webkit
WEBKIT_USES=	qt-dist:5,tools
WEBKIT_USE=	QT=webkit

post-patch:
# uiplugin is built in x11-toolkits/qt5-uiplugin.
# uitools is built in devel/qt5-uitools.
	${REINPLACE_CMD} -e '/uiplugin/ d' -e '/uitools/ d' \
		${WRKSRC}/src/${PORTNAME}/src/src.pro

post-install:
	${INSTALL_DATA} ${WRKSRC}/src/${PORTNAME}/src/designer/images/designer.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/designer-qt5.png
	# The generated .pc file refers to a nonexistent other .pc file
	${REINPLACE_CMD} -e '/^Requires/s/Qt5UiPlugin//' \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/Qt5Designer.pc

.include <bsd.port.mk>
