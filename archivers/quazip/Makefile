# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	quazip
DISTVERSION=	0.7.3
PORTREVISION=	3
CATEGORIES=	archivers
MASTER_SITES=	SF
PKGNAMESUFFIX=	-${FLAVOR}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt/C++ wrapper for ZIP/UNZIP package

LICENSE=	LGPL21

FLAVORS=	qt5 qt4
FLAVOR?=	${FLAVORS:[1]}

qt4_DEPRECATED=		Qt4 has been EOL since december 2015
qt4_EXPIRATION_DATE=	2019-03-15

USES=		cmake:outsource
USE_LDCONFIG=	yes

.  if ${FLAVOR} == qt4
USES+=		qt:4
USE_QT=		corelib moc_build network_build qmake_build rcc_build uic_build
CMAKE_ARGS=	-DBUILD_WITH_QT4:BOOL=TRUE
.  else
USES+=		compiler:c++11-lang qt:5
USE_QT=		core buildtools_build qmake_build
CMAKE_ARGS=	-DBUILD_WITH_QT4:BOOL=FALSE
QTVER_SUFFIX=	5
.  endif

PLIST_SUB=	QTVER_SUFFIX="${QTVER_SUFFIX}"

.include <bsd.port.mk>
