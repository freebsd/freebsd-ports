# Created by: Dima Panov <fluffy@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libdbusmenu-qt
PORTVERSION=	${MAJOR_VER}.${SNAPSHOT_VER:S/.//g}
CATEGORIES=	devel
MASTER_SITES=	http://archive.ubuntu.com/ubuntu/pool/main/libd/${PORTNAME}/
DISTNAME=	${PORTNAME}_${MAJOR_VER}+${SNAPSHOT_VER}.orig

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt4 implementation of the DBusMenu protocol

LICENSE=	LGPL20

MAJOR_VER=	0.9.3
SNAPSHOT_VER=	15.10.20150604

WRKSRC=		${WRKDIR}/${PORTNAME}-${MAJOR_VER}+${SNAPSHOT_VER}

USE_QT4=	corelib dbus gui moc_build qmake_build rcc_build uic_build
USES=		compiler:c++11-lib cmake:outsource
CMAKE_ARGS=	-DUSE_QT4:BOOL=TRUE -DUSE_QT5:BOOL=FALSE

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
