PORTNAME=	cmake
DISTVERSION=	${_CMAKE_VERSION}
PORTREVISION=	2
CATEGORIES=	devel
PKGNAMESUFFIX=	-core

PATCH_SITES+=	https://github.com/Kitware/CMake/commit/
PATCHFILES+=	2bb8c6aec74bb658b9ef7b8b3c8db75f2fb6c2b5.diff:-p1

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Cross-platform Makefile generator
WWW=		https://www.cmake.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/Copyright.txt

LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libidn2.so:dns/libidn2 \
		libjsoncpp.so:devel/jsoncpp \
		libpkg.so:${PKG_ORIGIN} \
		librhash.so:security/rhash \
		libuv.so:devel/libuv

USES=		cmake:_internal compiler:c++17-lang cpe localbase ncurses ssl
CPE_VENDOR=	cmake_project

HAS_CONFIGURE=	yes
CONFIGURE_CMD=	${WRKSRC}/bootstrap
CONFIGURE_LOG=	Bootstrap.cmk/cmake_bootstrap.log
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--datadir="/${DATADIR_REL}" \
		--docdir="/${DOCSDIR_REL}" \
		--init="${BUILD_WRKSRC}/InitialCache.cmake" \
		--parallel=${MAKE_JOBS_NUMBER} \
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
		--verbose
.if defined(WITH_CCACHE_BUILD)
CONFIGURE_ARGS+=	--enable-ccache
.endif
CONFIGURE_ENV=	MAKE=${MAKE}

# Quick fix to enable build with non-base SSL (CFLAGS/LDFLAGS only) (PR: 274512)
CFLAGS+=	-I${OPENSSLINC}
CXXFLAGS+=	-D__BSD_VISIBLE
LDFLAGS+=	-L${OPENSSLLIB}

SUB_FILES=	InitialCache.cmake

BUILD_WRKSRC=		${WRKDIR}/.build
CONFIGURE_WRKSRC=	${BUILD_WRKSRC}
INSTALL_WRKSRC=		${BUILD_WRKSRC}

OPTIONS_DEFINE=		DOCS
OPTIONS_SUB=		yes

post-patch:
	@(${FIND} ${WRKSRC}/Modules -name "*.cmake" -print0; \
		${FIND} ${WRKSRC}/Tests -name "CMakeLists.txt" -print0 ) | \
		${XARGS} -0 -n 100 ${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g; \
			s|/usr/X11R6|${LOCALBASE}|g'
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/Source/cmLocalGenerator.cxx \
		${WRKSRC}/Source/CPack/cmCPackGenerator.cxx \
		${WRKSRC}/bootstrap
	@${REINPLACE_CMD} -e 's|_compiler=\"ccache|_compiler="${CCACHE_BIN}|g' \
		${WRKSRC}/bootstrap
	@${REINPLACE_CMD} -e 's|/usr/include|${LOCALBASE}/include|' \
		${WRKSRC}/Modules/FindDCMTK.cmake
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/Modules/FindFLEX.cmake
	@${REINPLACE_CMD} -e 's|/opt/kde4|${PREFIX}|g' \
		${WRKSRC}/Modules/FindKDE4.cmake

# cmake-gui(1) is installed by devel/cmake-gui. Remove the man page's source to
# prevent it from being built/installed by devel/cmake.
	@${RM} ${WRKSRC}/Help/manual/cmake-gui.1.rst

pre-configure:
	@${MKDIR} ${BUILD_WRKSRC}
# Before running configure, substitute in the values of options
# for the build. CMake's configure doesn't accept --with-foo
# or similar options: it expects them to be set in CMake-style
# syntax in the initial cache.
	@${CP} ${WRKDIR}/InitialCache.cmake ${BUILD_WRKSRC}
	@${FIND} ${WRKSRC} -name "*.bak" -delete -o -name "*.orig" -delete

post-install:
	${INSTALL_DATA} ${WRKSRC}/Auxiliary/cmake-mode.el ${STAGEDIR}${PREFIX}/share/emacs/site-lisp
	# remove boost module because it is broken and unnecessary and breaks build of many packages
	@${FIND} ${STAGEDIR}${PREFIX} -name "FindBoost.*" -delete

.include <bsd.port.mk>
