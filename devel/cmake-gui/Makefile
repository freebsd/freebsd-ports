# $FreeBSD$

PORTNAME=	cmake
PORTVERSION=	3.0.1
CATEGORIES=	devel
MASTER_SITES=	http://www.cmake.org/files/v3.0/
PKGNAMESUFFIX=	-gui

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt-based GUI for CMake

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	sphinx-build:${PORTSDIR}/textproc/py-sphinx
LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl \
		libexpat.so:${PORTSDIR}/textproc/expat2

USE_QT5=	core gui widgets buildtools_build qmake_build
USES=		cmake:run shared-mime-info
CMAKE_ARGS=	-DBUILD_QtDialog:bool=on \
		-DBUILD_CursesDialog:BOOL=OFF \
		-DSPHINX_MAN:BOOL=ON \
		-DCMAKE_USE_SYSTEM_LIBRARIES:BOOL=ON \
		-DCMAKE_DATA_DIR:STRING="/${DATADIR_REL}" \
		-DCMAKE_DOC_DIR:STRING="/${DOCSDIR_REL}"

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
