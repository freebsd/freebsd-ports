PORTNAME=	kquickimageeditor
DISTVERSION=	0.6.0
CATEGORIES=	graphics
MASTER_SITES=	KDE/stable/${PORTNAME}/
PKGNAMESUFFIX=	-qt6

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Simple image editor for QtQuick applications
WWW=		https://invent.kde.org/libraries/kquickimageeditor

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSES/LGPL-2.1-or-later.txt

LIB_DEPENDS=	libopencv_imgproc.so:graphics/opencv

USES=		cmake compiler:c++17-lang gl kde:6 qt:6 tar:xz
USE_GL=		gl opengl
USE_KDE=	config ecm:build
USE_QT=		base declarative
USE_LDCONFIG=	yes

PLIST_SUB=	SHLIB_VER=${DISTVERSION}

.include <bsd.port.mk>
