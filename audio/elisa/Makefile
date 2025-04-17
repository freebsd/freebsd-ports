PORTNAME=	elisa
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	audio kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Audio player with QML and KDE Plasma integration
WWW=		https://userbase.kde.org/Elisa

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++14-lang desktop-file-utils gettext kde:6 \
		pkgconfig qt:6 tar:xz xorg
USE_KDE=	auth baloo bookmarks codecs completion config configwidgets \
		coreaddons crash dbusaddons filemetadata i18n iconthemes \
		itemviews jobwidgets kcmutils kdeclarative kio kirigami-addons \
		kirigami2 package qqc2-desktop-style service solid \
		widgetsaddons windowsystem xmlgui \
		ecm:build
USE_QT=		base multimedia
USE_XORG=	x11

OPTIONS_DEFINE=		DOCS VLC
OPTIONS_DEFAULT=	DOCS # VLC still uses Qt5

VLC_DESC=		Use VLC instead of QtMultimedia
VLC_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_LIBVLC
VLC_LIB_DEPENDS=	libvlc.so:multimedia/vlc

.include <bsd.port.mk>
