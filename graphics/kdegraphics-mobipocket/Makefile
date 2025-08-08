PORTNAME=	kdegraphics-mobipocket
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	graphics kde kde-applications
PKGNAMESUFFIX=	-${FLAVOR}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Mobipocket plugins for Strigi indexing and thumbnails
WWW=		https://invent.kde.org/graphics/kdegraphics-mobipocket

FLAVORS=	qt6 qt5
FLAVOR?=	qt6

USES=		cmake compiler:c++11-lang kde:${FLAVOR:S/qt//} \
		qt:${FLAVOR:S/qt//} tar:xz
USE_KDE=	completion config coreaddons jobwidgets kio service solid \
		widgetsaddons windowsystem \
		ecm:build
_USE_QT_qt5=	concurrent core dbus gui network widgets \
		buildtools:build qmake:build
_USE_QT_qt6=	base
USE_QT=		${_USE_QT_${FLAVOR}}

PLIST=		pkg-plist.${FLAVOR}

USE_LDCONFIG=	yes

.include <bsd.port.mk>
