# Created by: Nicola Vitale <nivit@FreeBSD.org>

PORTNAME=	quazip
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2
CATEGORIES=	archivers
PKGNAMESUFFIX=	-qt5

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt/C++ wrapper for ZIP/UNZIP package

LICENSE=	LGPL21

USES=		cmake compiler:c++11-lang cpe qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	stachenov
CPE_VENDOR=	quazip_project
USE_LDCONFIG=	yes
USE_QT=		core network \
		buildtools_build testlib_build qmake_build
CMAKE_ARGS=	-DBUILD_WITH_QT4:BOOL=FALSE

PLIST_SUB=	QTVER_SUFFIX=5 \
		QUAZIP_VERSION=${DISTVERSION}

.include <bsd.port.mk>
