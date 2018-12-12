# Created by: Michael Beer <beerml@sigma6audio.de>
# $FreeBSD$

PORTNAME=	suil
PORTVERSION=	0.10.0
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://download.drobilla.net/

MAINTAINER=	beerml@sigma6audio.de
COMMENT=	Suil is a C library for loading and wrapping LV2 plugin UIs

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	lv2>=1.14.0:audio/lv2
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		gnome pkgconfig python:build tar:bzip2 waf
USE_GNOME=	atk cairo gdkpixbuf2 glib20 gtk20 gtk30 pango
USE_LDCONFIG=	yes

PLIST_SUB=	SUILVERSION=${PORTVERSION}

OPTIONS_DEFINE=		QT4 QT5
OPTIONS_DEFAULT=	QT4 QT5
OPTIONS_SUB=		yes
QT4_CONFIGURE_OFF=	--no-qt4
QT4_LIB_DEPENDS=	libQtCore.so:devel/qt4-corelib \
			libQtGui.so:x11-toolkits/qt4-gui
QT5_CONFIGURE_OFF=	--no-qt5
QT5_LIB_DEPENDS=	libQt5Core.so:devel/qt5-core \
			libQt5Gui.so:x11-toolkits/qt5-gui \
			libQt5Widgets.so:x11-toolkits/qt5-widgets
QT5_USES=	compiler:c++11-lang

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libsuil-0.so.${PORTVERSION}
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/suil-0/*.so

.include <bsd.port.mk>
