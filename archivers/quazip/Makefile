PORTNAME=	quazip
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	archivers
PKGNAMESUFFIX=	-${FLAVOR}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt/C++ wrapper for ZIP/UNZIP package
WWW=		https://github.com/stachenov/quazip

LICENSE=	LGPL21

FLAVORS=	qt5 qt6
FLAVOR?=	qt5

USES=		cmake compiler:c++11-lang cpe qt:${FLAVOR:S/qt//}
CPE_VENDOR=	quazip_project
USE_GITHUB=	yes
GH_ACCOUNT=	stachenov
USE_LDCONFIG=	yes
_USE_QT_qt5=	core network \
		buildtools:build testlib:build qmake:build
_USE_QT_qt6=	base 5compat
USE_QT=		${_USE_QT_${FLAVOR}}

CMAKE_ARGS=	-DQUAZIP_QT_MAJOR_VERSION=${FLAVOR:S/qt//}

PLIST_SUB=	QTVER_SUFFIX=${FLAVOR:S/qt//} \
		QUAZIP_VERSION=${DISTVERSION}

.include <bsd.port.mk>
