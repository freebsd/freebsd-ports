PORTNAME=	libqaccessibilityclient
DISTVERSION=	0.6.0
CATEGORIES=	accessibility kde
MASTER_SITES=	KDE/stable/${PORTNAME}/
PKGNAMESUFFIX=	-${FLAVOR}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Helper to make writing accessibility tools easier
WWW=		https://api.kde.org/libqaccessibilityclient/html/index.html

LICENSE=	LGPL21 LGPL3
LICENSE_COMB=	dual
LICENSE_FILE_LGPL21=	${WRKSRC}/LICENSES/LGPL-2.1-only.txt
LICENSE_FILE_LGPL3=	${WRKSRC}/LICENSES/LGPL-3.0-only.txt

FLAVORS=	qt5 qt6
FLAVOR?=	qt5

USES=		cmake compiler:c++11-lang kde:${FLAVOR:S/qt//} \
		qt:${FLAVOR:S/qt//} tar:xz
CMAKE_ARGS=	-DQT_MAJOR_VERSION=${FLAVOR:S/qt//}
USE_KDE=	ecm:build
USE_QT=		${_USE_QT_${FLAVOR}}
_USE_QT_qt5=	core dbus gui widgets buildtools:build qmake:build
_USE_QT_qt6=	base

PLIST=		${.CURDIR}/pkg-plist.${FLAVOR}

.include <bsd.port.mk>
