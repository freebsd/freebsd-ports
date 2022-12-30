PORTNAME=	libdbusmenu-qt
PORTVERSION=	${MAJOR_VER}.${SNAPSHOT_VER:S/.//g}
PORTREVISION=	13
CATEGORIES=	devel
MASTER_SITES=	http://archive.ubuntu.com/ubuntu/pool/main/libd/${PORTNAME}/ \
		LOCAL/tcberner/${PORTNAME}/${PORTVERSION}
DISTNAME=	${PORTNAME}_${MAJOR_VER}+${SNAPSHOT_VER}.orig

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt${PKGNAMESUFFIX} implementation of the DBusMenu protocol
WWW=		https://launchpad.net/libdbusmenu-qt

LICENSE=	LGPL20

FLAVORS=	qt5 qt6
FLAVOR?=	qt5
qt5_PKGNAMESUFFIX=	5
qt6_PKGNAMESUFFIX=	6

USES=		compiler:c++11-lib cmake qt:${FLAVOR:S/qt//}
USE_LDCONFIG=	yes
_USE_QT5=	core dbus gui widgets \
		buildtools:build qmake:build
_USE_QT6=	base
USE_QT=		${_USE_QT${FLAVOR:S/qt//}}
CMAKE_ON=	USE_QT${FLAVOR:S/qt//}
QTVER_SUFFIX=	${FLAVOR:S/qt//}

OPTIONS_DEFINE=		DOXYGEN
OPTIONS_SUB=		YES
DOXYGEN_DESC=		Build documentation (requires doxygen)
DOXYGEN_CMAKE_BOOL=	WITH_DOC
DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen

.  if defined(PACKAGE_BUILDING)
OPTIONS_DEFAULT+=	DOXYGEN
.  endif

MAJOR_VER=	0.9.3
SNAPSHOT_VER=	16.04.20160218

WRKSRC=		${WRKDIR}/${PORTNAME}-${MAJOR_VER}+${SNAPSHOT_VER}
PLIST_SUB=	QTVER_SUFFIX="${QTVER_SUFFIX}"

post-patch:
	@${REINPLACE_CMD} -e '/add_subdirectory(tests)/ d' \
			  -e '/add_subdirectory(tools)/ d' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
