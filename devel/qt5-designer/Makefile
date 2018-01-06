# $FreeBSD$

PORTNAME=	designer
DISTVERSION=	${QT5_VERSION}
CATEGORIES=	devel
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt 5 graphical user interface designer

USE_QT5=	assistant_run core gui network printsupport quick uiplugin \
		widgets xml buildtools_build
QT_DIST=	tools
USES=		qmake
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
WEBKIT_USE=	QT5=webkit

post-patch:
# uiplugin is built in x11-toolkits/qt5-uiplugin.
# uitools is built in devel/qt5-uitools.
	${REINPLACE_CMD} -e '/uiplugin/ d' -e '/uitools/ d' \
		${WRKSRC}/src/${PORTNAME}/src/src.pro

post-install:
	${INSTALL_DATA} ${WRKSRC}/src/${PORTNAME}/src/designer/images/designer.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/designer-qt5.png

.include <bsd.port.mk>
