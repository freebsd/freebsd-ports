PORTNAME=	kstars
DISTVERSION=	3.8.4.1
PORTEPOCH=	1
CATEGORIES=	astro kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${DISTVERSION}/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE desktop planetarium
WWW=		https://edu.kde.org/kstars

LICENSE=	GPLv2

LIB_DEPENDS=	libXISF.so:graphics/libxisf \
		libcfitsio.so:astro/cfitsio \
		libqt6keychain.so:security/qtkeychain@qt6 \
		libraw.so:graphics/libraw \
		libgsl.so:math/gsl \
		libindiclient.so:devel/indi \
		libopencv_core.so:graphics/opencv \
		libnova.so:astro/libnova \
		libstellarsolver6.so:astro/stellarsolver \
		libwcs.so:astro/wcslib \
		libcurl.so:ftp/curl
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		xplanet:astro/xplanet
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		xplanet:astro/xplanet

USES=		cmake compiler:c++11-lib desktop-file-utils eigen:3 \
		gettext gnome kde:6 localbase:ldflags pkgconfig \
		python qt:6 tar:xz xorg
USE_GNOME=	glib20
USE_KDE=	config crash i18n kio newstuff notifications \
		notifyconfig plotting widgetsaddons xmlgui \
		ecm:build
USE_QT=		base datavis3d declarative \
		svg websockets
USE_XORG=	x11

CMAKE_ON=	BUILD_WITH_QT6

.include <bsd.port.mk>
