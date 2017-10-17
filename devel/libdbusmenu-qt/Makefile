# Created by: Dima Panov <fluffy@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libdbusmenu-qt
PORTVERSION=	${MAJOR_VER}.${SNAPSHOT_VER:S/.//g}
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://archive.ubuntu.com/ubuntu/pool/main/libd/${PORTNAME}/
DISTNAME=	${PORTNAME}_${MAJOR_VER}+${SNAPSHOT_VER}.orig

MAINTAINER=	kde@FreeBSD.org
COMMENT?=	Qt4 implementation of the DBusMenu protocol

LICENSE=	LGPL20

MAJOR_VER=	0.9.3
SNAPSHOT_VER=	16.04.20160218

WRKSRC=		${WRKDIR}/${PORTNAME}-${MAJOR_VER}+${SNAPSHOT_VER}

.if empty(PKGNAMESUFFIX)
USE_QT4=	corelib dbus gui moc_build qmake_build rcc_build uic_build
CMAKE_ARGS=	-DUSE_QT4:BOOL=TRUE -DUSE_QT5:BOOL=FALSE
.else
USE_QT5=	buildtools_build core dbus gui qmake_build widgets
CMAKE_ARGS=	-DUSE_QT4:BOOL=FALSE -DUSE_QT5:BOOL=TRUE
.endif

USES=		compiler:c++11-lib cmake:outsource

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

PLIST_SUB=	QTVER_SUFFIX="${PKGNAMESUFFIX}"

post-patch:
	@${REINPLACE_CMD} -e '/add_subdirectory(tests)/ d' \
			  -e '/add_subdirectory(tools)/ d' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
