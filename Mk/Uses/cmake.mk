# $FreeBSD$
#
# Provide support for CMake based projects
#
# Feature:		cmake
# Usage:		USES=cmake or USES=cmake:ARGS
# Valid ARGS:		outsource
# ARGS description:
# outsource		perform an out-of-source build
#
#
# Additional variables that affect cmake behaviour:
#
# User defined variables:
# CMAKE_VERBOSE		- Enable verbose build output
#			Default: not set, until BATCH or PACKAGE_BUILDING is defined
# CMAKE_NOCOLOR		- Disable colour build output
#			Default: not set, until BATCH or PACKAGE_BUILDING is defined
# CMAKE_NINJA		- Use ninja instead of make(1)
#
# Variables for ports:
# CMAKE_ENV		- Environment passed to cmake.
#			Default: ${CONFIGURE_ENV}
# CMAKE_ARGS		- Arguments passed to cmake
#			Default: see below
# CMAKE_BUILD_TYPE	- Type of build (cmake predefined build types).
#			Projects may have their own build profiles.
#			CMake supports the following types: Debug,
#			Release, RelWithDebInfo and MinSizeRel.
#			Debug and Release profiles respect system
#			CFLAGS, RelWithDebInfo and MinSizeRel will set
#			CFLAGS to "-O2 -g" and "-Os -DNDEBUG".
#			Default: Release, if WITH_DEBUG is not set,
#			Debug otherwise
# CMAKE_SOURCE_PATH	- Path to the source directory
#			Default: ${WRKSRC}
#
# MAINTAINER: kde@FreeBSD.org

.if !defined(_INCLUDE_USES_CMAKE_MK)
_INCLUDE_USES_CMAKE_MK=	yes

_valid_ARGS=		outsource run
_cmake_ARGS=		${cmake_ARGS:C/\:/ /g}

# Sanity check
.if defined(cmake_ARGS)
.  for arg in ${_cmake_ARGS}
.    if empty(_valid_ARGS:M${arg})
IGNORE=	Incorrect 'USES+= cmake:${cmake_ARGS}' usage: argument [${arg}] is not recognized
.    endif
.  endfor
.endif

CMAKE_BIN=		${LOCALBASE}/bin/cmake
BUILD_DEPENDS+=		${CMAKE_BIN}:${PORTSDIR}/devel/cmake

.if ${_cmake_ARGS:Mrun}
RUN_DEPENDS+=		${CMAKE_BIN}:${PORTSDIR}/devel/cmake
.endif

.if defined(WITH_DEBUG)
CMAKE_BUILD_TYPE?=	Debug
.else
CMAKE_BUILD_TYPE?=	Release
.endif #defined(WITH_DEBUG)

PLIST_SUB+=		CMAKE_BUILD_TYPE="${CMAKE_BUILD_TYPE:L}"

.if defined(STRIP) && ${STRIP} != ""
INSTALL_TARGET?=	install/strip
.endif

CMAKE_ENV?=		${CONFIGURE_ENV}
CMAKE_ARGS+=		-DCMAKE_C_COMPILER:STRING="${CC}" \
			-DCMAKE_CXX_COMPILER:STRING="${CXX}" \
			-DCMAKE_C_FLAGS:STRING="${CFLAGS}" \
			-DCMAKE_C_FLAGS_DEBUG:STRING="${CFLAGS}" \
			-DCMAKE_C_FLAGS_RELEASE:STRING="${CFLAGS}" \
			-DCMAKE_CXX_FLAGS:STRING="${CXXFLAGS}" \
			-DCMAKE_CXX_FLAGS_DEBUG:STRING="${CXXFLAGS}" \
			-DCMAKE_CXX_FLAGS_RELEASE:STRING="${CXXFLAGS}" \
			-DCMAKE_EXE_LINKER_FLAGS:STRING="${LDFLAGS}" \
			-DCMAKE_MODULE_LINKER_FLAGS:STRING="${LDFLAGS}" \
			-DCMAKE_SHARED_LINKER_FLAGS:STRING="${LDFLAGS}" \
			-DCMAKE_INSTALL_PREFIX:PATH="${PREFIX}" \
			-DCMAKE_BUILD_TYPE:STRING="${CMAKE_BUILD_TYPE}" \
			-DTHREADS_HAVE_PTHREAD_ARG:BOOL=YES \
			-DCMAKE_INSTALL_RPATH_USE_LINK_PATH=YES

.if defined(BATCH) || defined(PACKAGE_BUILDING)
CMAKE_VERBOSE=		yes
CMAKE_NOCOLOR=		yes
.endif

.if defined(CMAKE_VERBOSE)
CMAKE_ARGS+=		-DCMAKE_VERBOSE_MAKEFILE:BOOL=ON
.endif
.if defined(CMAKE_NOCOLOR)
CMAKE_ARGS+=		-DCMAKE_COLOR_MAKEFILE:BOOL=OFF
.endif

.if defined(CMAKE_NINJA)
.include "${USESDIR}/ninja.mk"
.endif

_CMAKE_MSG=		"===>  Performing in-source build"
CMAKE_SOURCE_PATH?=	${WRKSRC}

.if ${_cmake_ARGS:Moutsource}
_CMAKE_MSG=		"===>  Performing out-of-source build"
CONFIGURE_WRKSRC=	${WRKDIR}/.build
BUILD_WRKSRC=		${CONFIGURE_WRKSRC}
INSTALL_WRKSRC=		${CONFIGURE_WRKSRC}
.endif

.if !target(do-configure)
do-configure:
	@${ECHO_MSG} ${_CMAKE_MSG}
	${MKDIR} ${CONFIGURE_WRKSRC}
	@cd ${CONFIGURE_WRKSRC}; ${SETENV} ${CMAKE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} ${CMAKE_SOURCE_PATH}
.endif

.endif #!defined(_INCLUDE_USES_CMAKE_MK)
