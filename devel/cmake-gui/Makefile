# $FreeBSD$

PORTNAME=	cmake
PORTVERSION=	3.2.3
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.cmake.org/files/v3.2/
PKGNAMESUFFIX=	-gui

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt-based GUI for CMake

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	sphinx-build:${PORTSDIR}/textproc/py-sphinx
LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl \
		libexpat.so:${PORTSDIR}/textproc/expat2

USE_QT5=	core gui widgets buildtools_build qmake_build
USES=		cmake:run desktop-file-utils shared-mime-info
CMAKE_ARGS=	-DBUILD_QtDialog:bool=on \
		-DBUILD_CursesDialog:BOOL=OFF \
		-DSPHINX_MAN:BOOL=ON \
		-DCMAKE_USE_SYSTEM_LIBRARIES:BOOL=ON \
		-DCMAKE_DATA_DIR:STRING="/${DATADIR_REL}" \
		-DCMAKE_DOC_DIR:STRING="/${DOCSDIR_REL}"

ALL_TARGET=	cmake-gui documentation
INSTALL_WRKSRC=	${WRKSRC}/Source/QtDialog

DISTINFO_FILE=	${.CURDIR}/../cmake/distinfo

.include <bsd.port.pre.mk>

# CMake >= 3.1.0 needs libarchive3 because it calls
# archive_entry_copy_sourcepath_w and archive_write_set_format_7zip.
.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1000009
LIB_DEPENDS+=	libarchive.so.13:${PORTSDIR}/archivers/libarchive
.endif

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

.include <bsd.port.post.mk>
