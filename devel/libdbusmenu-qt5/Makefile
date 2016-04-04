# Created by: Tobias Berner <tcberner@gmail.com>
# $FreeBSD$

PORTNAME=	libdbusmenu-qt5
PORTVERSION=	${MAJOR_VER}.${SNAPSHOT_VER:S/.//g}
CATEGORIES=	devel
MASTER_SITES=	http://archive.ubuntu.com/ubuntu/pool/main/libd/${PORTNAME:C/5//}/
DISTNAME=	${PORTNAME:C/5//}_${MAJOR_VER}+${SNAPSHOT_VER}.orig

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt5 implementation of the DBusMenu protocol

LICENSE=	LGPL20

MAJOR_VER=	0.9.3
SNAPSHOT_VER=	15.10.20150604

WRKSRC=		${WRKDIR}/${PORTNAME:C/5//}-${MAJOR_VER}+${SNAPSHOT_VER}

USE_QT5=	buildtools_build core dbus qmake_build widgets
USES=		compiler:c++11-lib cmake:outsource
CMAKE_ARGS=	-DUSE_QT4:BOOL=FALSE -DUSE_QT5:BOOL=TRUE

USE_LDCONFIG=	yes

OPTIONS_DEFINE=		DOXYGEN
OPTIONS_SUB=		YES
DOXYGEN_DESC=		Build documentation (requires doxygen)
DOXYGEN_CMAKE_ON=	-DWITH_DOC:BOOL=TRUE
DOXYGEN_CMAKE_OFF=	-DWITH_DOC:BOOL=FALSE
DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen

.if defined(PACKAGE_BUILDING)
OPTIONS_DEFAULT+=	DOXYGEN
.endif

post-patch:
	@${REINPLACE_CMD} -e '/add_subdirectory(tests)/ d' \
			  -e '/add_subdirectory(tools)/ d' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
