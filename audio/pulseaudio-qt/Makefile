PORTNAME=	pulseaudio-qt
DISTVERSION=	1.5.0
MASTER_SITES=	KDE/stable/${PORTNAME}
CATEGORIES=	audio kde
PKGNAMESUFFIX=	${FLAVOR:S/qt//}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Pulseaudio bindings for Qt
WWW=		https://github.com/KDE/pulseaudio-qt

FLAVORS=	qt5 qt6
FLAVOR?=	qt5

LIB_DEPENDS=	libcanberra.so:audio/libcanberra \
		libpulse.so:audio/pulseaudio

USES=		cmake compiler:c++11-lib gettext kde:${FLAVOR:S/qt//} \
		pkgconfig qt:${FLAVOR:S/qt//} shebangfix tar:xz
USE_KDE=	ecm:build
_USE_QT_qt5=	core dbus gui \
		buildtools:build qmake:build
_USE_QT_qt6=	base
USE_QT=		${_USE_QT_${FLAVOR}}
CMAKE_ARGS=	-DQT_MAJOR_VERSION=${FLAVOR:S/qt//}

PLIST_SUB=	QT_VER=${FLAVOR:S/qt//}

.include <bsd.port.mk>
