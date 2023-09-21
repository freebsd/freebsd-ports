PORTNAME=	kstars
DISTVERSION=	3.6.6
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	astro kde
MASTER_SITES=	KDE/stable/${PORTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE desktop planetarium
WWW=		https://edu.kde.org/kstars

LICENSE=	GPLv2

LIB_DEPENDS=	libXISF.so:graphics/libxisf \
		libcfitsio.so:astro/cfitsio \
		libqt5keychain.so:security/qtkeychain@qt5 \
		libraw.so:graphics/libraw \
		libgsl.so:math/gsl \
		libsecret-1.so:security/libsecret \
		libnova.so:astro/libnova \
		libstellarsolver.so:astro/stellarsolver \
		libwcs.so:astro/wcslib
BUILD_DEPENDS=	xplanet:astro/xplanet
RUN_DEPENDS=	xplanet:astro/xplanet

USES=		cmake compiler:c++11-lib desktop-file-utils eigen:3 \
		gettext gnome kde:5 localbase:ldflags pkgconfig qt:5 tar:xz xorg
USE_GNOME=	glib20
USE_KDE=	attica auth bookmarks codecs completion config configwidgets\
		coreaddons crash dbusaddons guiaddons i18n \
		iconthemes init itemviews jobwidgets kio newstuff notifications \
		notifyconfig parts plotting service solid texteditor \
		widgetsaddons windowsystem xmlgui \
		doctools:build ecm:build
USE_QT=		concurrent core datavis3d dbus declarative gui multimedia \
		network opengl printsupport sql svg testlib websockets widgets \
		xml \
		buildtools:build qmake:build
USE_XORG=	x11

# Requires devel/indi >= 2.0.0 which is not in the ports tree yet. KStars builds
# fine with INDI 2.0.3, but support for the INDI 2.0 API in astro/phd2 and
# astro/stellarium as of 2023-08-10 appear to be works in progress.
CMAKE_ON=	CMAKE_DISABLE_FIND_PACKAGE_INDI

.include <bsd.port.mk>
