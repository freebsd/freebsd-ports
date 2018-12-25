# Created by: Dima Panov <fluffy@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libdbusmenu-qt
PORTVERSION=	${MAJOR_VER}.${SNAPSHOT_VER:S/.//g}
PORTREVISION=	7
CATEGORIES=	devel
MASTER_SITES=	http://archive.ubuntu.com/ubuntu/pool/main/libd/${PORTNAME}/ \
		LOCAL/tcberner/${PORTNAME}/${PORTVERSION}
PKGNAMESUFFIX=	${FLAVOR:C/qt//}
DISTNAME=	${PORTNAME}_${MAJOR_VER}+${SNAPSHOT_VER}.orig

MAINTAINER=	kde@FreeBSD.org
COMMENT?=	Qt4 implementation of the DBusMenu protocol

LICENSE=	LGPL20

FLAVORS=	qt5 qt4
FLAVOR?=	${FLAVORS:[1]}

USES=		compiler:c++11-lib cmake
USE_LDCONFIG=	yes

.  if ${FLAVOR} == qt4
DEPRECATED=	Qt4 has been EOL since december 2015
EXPIRATION_DATE=2019-03-15
USES+=		qt:4
USE_QT=		corelib dbus gui \
		moc_build qmake_build rcc_build uic_build
CMAKE_ON=	USE_QT4
CMAKE_OFF=	USE_QT5
QTVER_SUFFIX=	# empty
.  else
USES+=		qt:5
USE_QT=		core dbus gui widgets \
		buildtools_build qmake_build
CMAKE_ON=	USE_QT5
CMAKE_OFF=	USE_QT4
QTVER_SUFFIX=	5
.  endif

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
