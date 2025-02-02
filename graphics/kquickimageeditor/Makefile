PORTNAME=	kquickimageeditor
DISTVERSION=	0.3.0
CATEGORIES=	graphics
MASTER_SITES=	KDE/stable/${PORTNAME}/
PKGNAMESUFFIX=	-${FLAVOR}

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Simple image editor for QtQuick applications
WWW=		https://invent.kde.org/libraries/kquickimageeditor

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSES/LGPL-2.1-or-later.txt

FLAVORS=	qt6 qt5
FLAVOR?=	qt6

USES=		cmake compiler:c++17-lang gl kde:${FLAVOR:S/qt//} pkgconfig \
		qt:${FLAVOR:S/qt//} tar:xz
USE_GL=		gl
_USE_QT_qt5=	core declarative gui network quickcontrols2 \
		buildtools:build linguist:build qmake:build
_USE_QT_qt6=	3d base
USE_QT=		${_USE_QT_${FLAVOR}}
USE_KDE=	ecm:build

PLIST=		pkg-plist.${FLAVOR}

.include <bsd.port.mk>
