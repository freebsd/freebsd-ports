# $FreeBSD$

PORTNAME=	cmake
DISTVERSION=	3.13.4
CATEGORIES=	devel
MASTER_SITES=	https://www.cmake.org/files/v${PORTVERSION:R}/
PKGNAMESUFFIX=	-gui

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt-based GUI for CMake

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/Copyright.txt

BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libexpat.so:textproc/expat2 \
		libjsoncpp.so:devel/jsoncpp \
		libuv.so:devel/libuv \
		librhash.so:security/rhash

USES=		cmake:run,insource compiler:c++11-lang desktop-file-utils libarchive \
		shared-mime-info qt:5
USE_QT=		core gui widgets buildtools_build qmake_build
CMAKE_OFF=	BUILD_CursesDialog \
		CMake_SPHINX_DEPEND_ON_EXECUTABLES
CMAKE_ON=	BUILD_QtDialog \
		CMAKE_USE_SYSTEM_LIBRARIES \
		SPHINX_MAN
CMAKE_ARGS=	-DCMAKE_DATA_DIR:STRING="/${DATADIR_REL}" \
		-DCMAKE_DOC_DIR:STRING="/${DOCSDIR_REL}" \

ALL_TARGET=	cmake-gui documentation
INSTALL_WRKSRC=	${WRKSRC}/Source/QtDialog

DISTINFO_FILE=	${.CURDIR}/../cmake/distinfo

post-patch:
	@(${FIND} ${WRKSRC}/Modules -name "*.cmake" -print0; \
		${FIND} ${WRKSRC}/Tests -name "CMakeLists.txt" -print0 ) | \
		${XARGS} -0 -n 100 ${REINPLACE_CMD} -e 's,/usr/local,${LOCALBASE},g; \
			s,/usr/X11R6,${LOCALBASE},g'

pre-install:
	${LN} -sf ${CMAKE_BIN} ${WRKSRC}/bin

post-install:
	${INSTALL_MAN} ${WRKSRC}/Utilities/Sphinx/man/cmake-gui.1 \
		${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
