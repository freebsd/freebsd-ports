PORTNAME=	cmake
DISTVERSION=	${_CMAKE_VERSION}
CATEGORIES=	devel
PKGNAMESUFFIX=	-gui

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt-based GUI for CMake
WWW=		https://www.cmake.org

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/Copyright.txt

BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx@${PY_FLAVOR}
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libexpat.so:textproc/expat2 \
		libjsoncpp.so:devel/jsoncpp \
		libuv.so:devel/libuv \
		librhash.so:security/rhash

USES=		cmake:run,insource compiler:c++17-lang desktop-file-utils libarchive \
		python:build shared-mime-info qt:6
USE_QT=		base

CMAKE_ARGS=	-DCMAKE_DATA_DIR:STRING="/${DATADIR_REL}" \
		-DCMAKE_DOC_DIR:STRING="/${DOCSDIR_REL}" \
		-DCMake_QT_MAJOR_VERSION=6
CMAKE_ON=	BUILD_QtDialog \
		CMAKE_USE_SYSTEM_CURL \
		CMAKE_USE_SYSTEM_EXPAT \
		CMAKE_USE_SYSTEM_FORM \
		CMAKE_USE_SYSTEM_JSONCPP \
		CMAKE_USE_SYSTEM_LIBARCHIVE \
		CMAKE_USE_SYSTEM_LIBRHASH \
		CMAKE_USE_SYSTEM_LIBUV \
		SPHINX_MAN
CMAKE_OFF=	BUILD_CursesDialog \
		CMake_SPHINX_DEPEND_ON_EXECUTABLES \
		CMAKE_USE_SYSTEM_CPPDAP

ALL_TARGET=	cmake-gui documentation

CXXFLAGS+=	-D__BSD_VISIBLE

INSTALL_WRKSRC=	${WRKSRC}/Source/QtDialog

DISTINFO_FILE=	${.CURDIR}/../cmake-core/distinfo

post-patch:
	@(${FIND} ${WRKSRC}/Modules -name "*.cmake" -print0; \
		${FIND} ${WRKSRC}/Tests -name "CMakeLists.txt" -print0 ) | \
		${XARGS} -0 -n 100 ${REINPLACE_CMD} -e 's,/usr/local,${LOCALBASE},g; \
			s,/usr/X11R6,${LOCALBASE},g'

pre-install:
	${LN} -sf ${CMAKE_BIN} ${WRKSRC}/bin

post-install:
	${INSTALL_MAN} ${WRKSRC}/Utilities/Sphinx/man/cmake-gui.1 \
		${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
