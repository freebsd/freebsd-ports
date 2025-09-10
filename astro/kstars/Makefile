PORTNAME=	kstars
DISTVERSION=	3.7.8
PORTEPOCH=	1
CATEGORIES=	astro kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${DISTVERSION}/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE desktop planetarium
WWW=		https://edu.kde.org/kstars

LICENSE=	GPLv2

LIB_DEPENDS=	libXISF.so:graphics/libxisf \
		libcfitsio.so:astro/cfitsio \
		libqt5keychain.so:security/qtkeychain@qt5 \
		libraw.so:graphics/libraw \
		libgsl.so:math/gsl \
		libindiclient.so:devel/indi \
		libopencv_core.so:graphics/opencv \
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

.include <bsd.port.mk>
