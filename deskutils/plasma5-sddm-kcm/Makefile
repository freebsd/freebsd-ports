# $FreeBSD$

PORTNAME=	sddm-kcm
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	deskutils kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma5 config module for SDDM

USES=		cmake compiler:c++11-lib gettext kde:5 cpe pkgconfig \
		qt:5 tar:xz xorg
USE_KDE=	auth archive attica codecs completion config configwidgets \
		coreaddons ecm i18n jobwidgets kio newstuff service \
		widgetsaddons xmlgui
USE_QT=		concurrent core dbus declarative designer gui network uiplugin widgets \
		x11extras xml \
		buildtools_build qmake_build
USE_XORG=	ice sm x11 xcb xcursor xext xfixes

.include <bsd.port.mk>
