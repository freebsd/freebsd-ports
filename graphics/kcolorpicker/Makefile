PORTNAME=	kColorPicker
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.1
CATEGORIES=	graphics kde
PKGNAMESUFFIX=	-qt6

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt-based color picker library with popup menu
WWW=		https://github.com/ksnip/kColorPicker

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++17-lang gl qt:6
USE_GITHUB=	yes
GH_ACCOUNT=	ksnip
USE_GL=		opengl
USE_QT=		base

CMAKE_ON=	BUILD_SHARED_LIBS BUILD_WITH_QT6

PLIST_SUB=	SHLIB_VER=${DISTVERSION} \
		SHLIB_VER_MAJ=${DISTVERSION:R:R}

.include <bsd.port.mk>
