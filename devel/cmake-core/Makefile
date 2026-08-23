PORTNAME=	cmake
DISTVERSION=	${_CMAKE_VERSION}
CATEGORIES=	devel
PKGNAMESUFFIX=	-core
MASTER_SITES=	https://arrowd.name/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Cross-platform Makefile generator
WWW=		https://www.cmake.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libidn2.so:dns/libidn2 \
		libjsoncpp.so:devel/jsoncpp \
		libpkg.so:${PKG_ORIGIN} \
		librhash.so:security/rhash \
		libuv.so:devel/libuv

USES=		cmake:_internal compiler:c++17-lang cpe localbase:ldflags \
		pkgconfig python:env ncurses ssl
CPE_VENDOR=	cmake_project

HAS_CONFIGURE=	yes
CONFIGURE_CMD=	${WRKSRC}/bootstrap
CONFIGURE_LOG=	Bootstrap.cmk/cmake_bootstrap.log
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--datadir="/${DATADIR_REL}" \
		--docdir="/${DOCSDIR_REL}" \
		--parallel=${MAKE_JOBS_NUMBER} \
		--bootstrap-system-jsoncpp \
		--bootstrap-system-librhash \
		--bootstrap-system-libuv \
		--system-bzip2 \
		--system-expat \
		--system-jsoncpp \
		--system-liblzma \
		--system-libarchive \
		--system-librhash \
		--system-libuv \
		--system-zlib \
		--system-zstd \
		--no-system-cppdap \
		--no-system-curl \
		--no-system-nghttp2 \
		--verbose \
		${CONFIGURE_ARGS_CACHE} \
		-- \
		-DCMake_TEST_NO_NETWORK:BOOL=ON \
		-DCMake_TEST_Qt5:BOOL=OFF \
		-DLibArchive_INCLUDE_DIR:STRING="/usr/include" \
		-DLibArchive_LIBRARY:STRING="/usr/lib/libarchive.so" \
		${CMAKE_ARGS_COMMON}

.if defined(WITH_CCACHE_BUILD)
CONFIGURE_ARGS_CACHE=	--enable-ccache
.endif
CONFIGURE_ENV=	MAKE=${MAKE}

# Quick fix to enable build with non-base SSL (CFLAGS/LDFLAGS only) (PR: 274512)
CFLAGS+=	-I${OPENSSLINC}
CXXFLAGS+=	-D__BSD_VISIBLE
LDFLAGS+=	-L${OPENSSLLIB}

BUILD_WRKSRC=		${WRKDIR}/.build
CONFIGURE_WRKSRC=	${BUILD_WRKSRC}
INSTALL_WRKSRC=		${BUILD_WRKSRC}
TEST_WRKSRC=		${BUILD_WRKSRC}

TEST_TARGET=		test

OPTIONS_DEFINE=		DOCS
OPTIONS_SUB=		yes

USE_GITLAB=yes
GL_SITE=https://gitlab.kitware.com
GL_TAGNAME=30a6e89923ee53491a6a529f978a69ec1558e3f5

post-patch:
# 	@(${FIND} ${WRKSRC}/Modules -name "*.cmake" -print0; \
# 		${FIND} ${WRKSRC}/Tests -name "CMakeLists.txt" -print0 ) | \
# 		${XARGS} -0 -n 100 ${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g; \
# 			s|/usr/X11R6|${LOCALBASE}|g'
# 	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
# 		${WRKSRC}/Source/cmLocalGenerator.cxx \
# 		${WRKSRC}/Source/CPack/cmCPackGenerator.cxx \
# 		${WRKSRC}/bootstrap
# 	@${REINPLACE_CMD} -e 's|_compiler=\"ccache|_compiler="${CCACHE_BIN}|g' \
# 		${WRKSRC}/bootstrap
# 	@${REINPLACE_CMD} -e 's|/usr/include|${LOCALBASE}/include|' \
# 		${WRKSRC}/Modules/FindDCMTK.cmake
# 	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
# 		${WRKSRC}/Modules/FindFLEX.cmake
# 	@${REINPLACE_CMD} -e 's|/opt/kde4|${PREFIX}|g' \
# 		${WRKSRC}/Modules/FindKDE4.cmake
	@${REINPLACE_CMD} -e \
		'/set(_$${_PYTHON_PREFIX}_VERSIONS 3/s/VERSIONS 3/VERSIONS ${PYTHON_VER} 3/' \
		${WRKSRC}/Modules/FindPython/Support.cmake
# cmake-gui(1) is installed by devel/cmake-gui. Remove the man page's source to
# prevent it from being built/installed by devel/cmake.
	@${RM} ${WRKSRC}/Help/manual/cmake-gui.1.rst

pre-configure:
	@${FIND} ${WRKSRC} -name "*.bak" -delete -o -name "*.orig" -delete

.include <bsd.port.mk>
