PORTNAME=	quazip
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5
CATEGORIES=	archivers
PKGNAMESUFFIX=	-${FLAVOR}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt/C++ wrapper for ZIP/UNZIP package
WWW=		https://github.com/stachenov/quazip

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

FLAVORS=	qt5 qt6
FLAVOR?=	qt5

USES=		cmake:testing compiler:c++${"${FLAVOR:Mqt6}" != "":?17:14}-lang \
		cpe qt:${FLAVOR:S/qt//}
CPE_VENDOR=	quazip_project
USE_GITHUB=	yes
GH_ACCOUNT=	stachenov
USE_LDCONFIG=	yes
_USE_QT_qt5=	core \
		buildtools:build qmake:build \
		network:test testlib:test
_USE_QT_qt6=	5compat base
USE_QT=		${_USE_QT_${FLAVOR}}

CMAKE_ARGS=	-DQUAZIP_QT_MAJOR_VERSION=${FLAVOR:S/qt//}
CMAKE_TESTING_ON=	QUAZIP_ENABLE_TESTS

PLIST_SUB=	QTVER_SUFFIX=${FLAVOR:S/qt//} \
		QUAZIP_VERSION=${DISTVERSION}

.include <bsd.port.mk>
