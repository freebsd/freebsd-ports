PORTNAME=	cmake
# Remember to update devel/cmake-doc and devel/cmake-gui as well.
DISTVERSION=	${_CMAKE_VERSION}
CATEGORIES=	devel
PKGNAMESUFFIX=	-core

PATCH_SITES=	https://gitlab.kitware.com/cmake/cmake/-/commit/
PATCHFILES=	61436858e431b137252b3d5e63ee579c7c575103.patch:-p1 # Fix pkg-config trailing whitespace

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Cross-platform Makefile generator
WWW=		https://www.cmake.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/Copyright.txt

LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libjsoncpp.so:devel/jsoncpp \
		libuv.so:devel/libuv \
		librhash.so:security/rhash

USES=		cmake:_internal compiler:c++11-lang cpe localbase ncurses ssl

CPE_VENDOR=	cmake_project
HAS_CONFIGURE=	yes
CONFIGURE_ENV=	MAKE=make
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--datadir="/${DATADIR_REL}" \
		--docdir="/${DOCSDIR_REL}" \
		--system-expat \
		--system-jsoncpp \
		--system-zlib \
		--system-zstd \
		--system-bzip2 \
		--system-liblzma \
		--system-libarchive \
		--system-librhash \
		--system-libuv \
		--no-system-cppdap \
		--no-system-curl \
		--no-system-nghttp2 \
		--parallel=${MAKE_JOBS_NUMBER} \
		--init="${WRKSRC}/InitialCache.cmake"

# Quick fix to enable build with non-base SSL (PR: 274512)
CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}

OPTIONS_DEFINE=		DOCS CPACK
OPTIONS_DEFAULT=	CPACK
OPTIONS_SUB=		yes

CPACK_DESC=		Enable FreeBSD generator in CPack (experimental)
CPACK_LIB_DEPENDS=	libpkg.so:${PKG_ORIGIN}

CXXFLAGS+=	-D__BSD_VISIBLE

.include <bsd.port.pre.mk>

.if defined(STRIP) && ${STRIP} != "" && !defined(WITH_DEBUG)
INSTALL_TARGET=	install/strip
.endif

# Before running configure, substitute in the values of options
# for the build. CMake's configure doesn't accept --with-foo
# or similar options: it expects them to be set in CMake-style
# syntax in the initial cache.
pre-configure:
	@${CP} "${FILESDIR}/InitialCache.cmake" "${WRKSRC}/InitialCache.cmake"
	@${FIND} ${WRKSRC} -name "*.bak" -delete -o -name "*.orig" -delete

pre-configure-CPACK-on:
	@${REINPLACE_CMD} \
		-e 's/@@CPACK_OPTION_VALUE@@/ON/' \
		-e 's/@@CPACK_OPTION_COMMENT@@//' \
		"${WRKSRC}/InitialCache.cmake"

pre-configure-CPACK-off:
	@${REINPLACE_CMD} \
		-e 's/@@CPACK_OPTION_VALUE@@/OFF/' \
		-e 's/@@CPACK_OPTION_COMMENT@@/# /' \
		"${WRKSRC}/InitialCache.cmake"

post-patch:
	@(${FIND} ${WRKSRC}/Modules -name "*.cmake" -print0; \
		${FIND} ${WRKSRC}/Tests -name "CMakeLists.txt" -print0 ) | \
		${XARGS} -0 -n 100 ${REINPLACE_CMD} -e 's,/usr/local,${LOCALBASE},g; \
			s,/usr/X11R6,${LOCALBASE},g'
	@${REINPLACE_CMD} -e 's,/usr/local,${LOCALBASE},g' \
		${WRKSRC}/Source/cmLocalGenerator.cxx \
		${WRKSRC}/Source/CPack/cmCPackGenerator.cxx \
		${WRKSRC}/bootstrap
	@${REINPLACE_CMD} -e 's,/opt/kde4,${PREFIX},g' \
		${WRKSRC}/Modules/FindKDE4.cmake
	@${REINPLACE_CMD} -e 's,/usr/include,${LOCALBASE}/include,' \
		${WRKSRC}/Modules/FindDCMTK.cmake
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/Modules/FindFLEX.cmake

# cmake-gui(1) is installed by devel/cmake-gui. Remove the man page's source to
# prevent it from being built/installed by devel/cmake.
	${RM} ${WRKSRC}/Help/manual/cmake-gui.1.rst

post-install:
	${INSTALL_DATA} ${WRKSRC}/Auxiliary/cmake-mode.el ${STAGEDIR}${PREFIX}/share/emacs/site-lisp
	# The .NoDartCoverage is supposed to suppress testing in the
	# source directories, but gets accidentally installed.
	@${FIND} ${STAGEDIR}${PREFIX} -name ".NoDartCoverage" -delete

.include <bsd.port.post.mk>
