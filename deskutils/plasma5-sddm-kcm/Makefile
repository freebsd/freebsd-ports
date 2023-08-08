PORTNAME=	sddm-kcm
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	deskutils kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma5 config module for SDDM
WWW=		https://www.kde.org/plasma-desktop

USES=		cmake compiler:c++11-lib gettext kde:5 pkgconfig qt:5 tar:xz \
		xorg
USE_KDE=	archive attica auth codecs completion config configwidgets \
		coreaddons ecm i18n jobwidgets kcmutils kdeclarative kio \
		newstuff service widgetsaddons windowsystem xmlgui
USE_QT=		concurrent core dbus declarative designer gui network uiplugin \
		widgets x11extras xml \
		buildtools:build qmake:build
USE_XORG=	ice sm x11 xcb xcursor xext xfixes

CMAKE_ARGS=	-DSDDM_CONFIG_FILE:FILEPATH=${LOCALBASE}/etc/sddm.conf \
		-DSDDM_CONFIG_DIR:PATH=${LOCALBASE}/etc/sddm.conf.d

.include <bsd.port.mk>
