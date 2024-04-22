PORTNAME=	qcustomplot
DISTVERSION=	2.1.1
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	https://www.qcustomplot.com/release/${PORTVERSION}/
PKGNAMESUFFIX=	-${FLAVOR}
DISTNAME=	QCustomPlot
DIST_SUBDIR=	${PORTNAME}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Qt C++ widget for plotting and data visualization
WWW=		https://www.qcustomplot.com

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/GPL.txt

FLAVORS=	qt5 qt6
FLAVOR?=	qt5

USES=		cmake compiler:c++11-lang qt:${FLAVOR:S/qt//}
USE_QT=		${_USE_QT_${FLAVOR}}
USE_LDCONFIG=	yes
_USE_QT_qt5=	core gui printsupport widgets buildtools:build qmake:build
_USE_QT_qt6=	base tools:build

CMAKE_ARGS=	-DUSE_QT_VERSION=${FLAVOR:S/qt//}

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_SUB=	SHLIB_VER=${DISTVERSION}

${FLAVOR}_PLIST=	${.CURDIR}/pkg-plist.${FLAVOR}

post-patch:
	${CP} ${FILESDIR}/CMakeLists.txt ${FILESDIR}/Config.cmake.in \
		${WRKSRC}

.include <bsd.port.mk>
