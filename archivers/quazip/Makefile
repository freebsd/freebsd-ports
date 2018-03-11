# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	quazip
DISTVERSION=	0.7.3
PORTREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	SF
PKGNAMESUFFIX=	-${FLAVOR}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt/C++ wrapper for ZIP/UNZIP package

LICENSE=	LGPL21

FLAVORS=	qt4 qt5
FLAVOR?=	${FLAVORS:[1]}

USES=		cmake:outsource
USE_LDCONFIG=	yes

.  if ${FLAVOR} == qt4
USE_QT4=	corelib moc_build network_build qmake_build rcc_build uic_build
CMAKE_ARGS=	-DBUILD_WITH_QT4:BOOL=TRUE
.  else
USE_QT5=	core buildtools_build qmake_build
CMAKE_ARGS=	-DBUILD_WITH_QT4:BOOL=FALSE
QTVER_SUFFIX=	5
.  endif

PLIST_SUB=	QTVER_SUFFIX="${QTVER_SUFFIX}"

.include <bsd.port.mk>
