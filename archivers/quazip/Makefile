# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	quazip
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9
CATEGORIES=	archivers
PKGNAMESUFFIX=	-qt5

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt/C++ wrapper for ZIP/UNZIP package

LICENSE=	LGPL21

USES=		cmake compiler:c++11-lang qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	stachenov
USE_LDCONFIG=	yes
USE_QT=		core buildtools_build qmake_build
CMAKE_ARGS=	-DBUILD_WITH_QT4:BOOL=FALSE

PLIST_SUB=	QTVER_SUFFIX=5

.include <bsd.port.mk>
