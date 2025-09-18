#-*- tab-width: 4; -*-
# ex:ts=4
#
# User settable:
#  - WITH_CCACHE_BUILD - enables depending on ccache and using it in the build.
#  - CCACHE_PKG_PREFIX - where ccache is already installed.  Default: LOCALBASE
#                       This should not be set unless it differs from the
#                       default.
#  - CCACHE_DIR (optional) - where ccache stores its cache. See ccache(1).
#                       This should not be set unless it differs from the
#                       default.
#
# Port use (users should not modify these):
#  - CCACHE_ENABLED - tells the port if ccache is enabled.
#  - CCACHE_BIN - path to the ccache binary.  Intended to be prefixed before CC.
#  - CCACHE_WRAPPER_PATH - path to directory containing compiler symlinks back
#                          to ccache.  For example, gcc5 -> ccache.  Intended
#                          to be added to $PATH
#                          This is expected to end in /libexec/ccache.
#
#   In general CCACHE_WRAPPER_PATH should be placed into the env PATH for a
#   port build rather than directly invoking CCACHE_BIN.  Then when the port
#   runs 'cc' or 'gcc5' it will find the symlinks.  If a port is directly
#   using a full path to a specific compiler then CCACHE_BIN can possibly be
#   prefixed in front of it, if the CC path cannot be fixed to be relative.
#
# Port use (special case):
#  - NO_CCACHE - disable using ccache entirely.  This is for when a port build
#                fails with ccache being used.  Typically this should be
#                temporary only.
#  - NO_CCACHE_DEPEND - avoid automatically depending on ccache but still
#                       attempt to use it in PATH.  This is typically only
#                       needed in devel/ccache itself.
#

COMMANDS_Include_MAINTAINER=	portmgr@FreeBSD.org

.if !defined(_CCACHEMKINCLUDED)

_CCACHEMKINCLUDED=	yes

.  if defined(NOCCACHE)
NO_CCACHE=	t
.  endif

.  if defined(WITH_CCACHE_BUILD)
CCACHE_ENABLED= yes
.  else
CCACHE_ENABLED= no
.  endif

# HOME is always set to ${WRKDIR} now. Try to use /root/.ccache as default.
.  if defined(WITH_CCACHE_BUILD) && !defined(CCACHE_DIR)
.    if defined(USER) && ${USER} == root
CCACHE_DIR=	/root/.ccache
.    else
CCACHE_ENABLED=	no
NO_CCACHE=	yes
WARNING+=	WITH_CCACHE_BUILD support disabled, please set CCACHE_DIR.
.    endif
.  endif

# Support NO_CCACHE for common setups, require WITH_CCACHE_BUILD, and
# don't use if ccache already set in CC
.  if !defined(NO_CCACHE) && defined(WITH_CCACHE_BUILD) && !${CC:M*ccache*} && \
  !defined(NO_BUILD)

# Poudriere will only define CCACHE_WRAPPER_PATH for using a host-static ccache
# binary.
.    if defined(CCACHE_WRAPPER_PATH)
CCACHE_PKG_PREFIX=		${CCACHE_WRAPPER_PATH:C,/libexec/ccache$,,}
.    endif
CCACHE_PKG_PREFIX?=		${LOCALBASE}
CCACHE_WRAPPER_PATH?=	${CCACHE_PKG_PREFIX}/libexec/ccache
CCACHE_BIN?=			${CCACHE_PKG_PREFIX}/bin/ccache

# Avoid depends loops between ccache and pkg
.    if !defined(NO_CCACHE_DEPEND) && \
    ${PKGORIGIN} != ${PKG_ORIGIN}
BUILD_DEPENDS+=		${CCACHE_BIN}:devel/ccache
.    endif

.    if exists(${CCACHE_WRAPPER_PATH})
# Prepend the ccache dir into the PATH and setup ccache env
PATH:=	${CCACHE_WRAPPER_PATH}:${PATH}
#.MAKEFLAGS:		PATH=${PATH}
.      if !${MAKE_ENV:MPATH=*} && !${CONFIGURE_ENV:MPATH=*}
MAKE_ENV+=			PATH=${PATH}
CONFIGURE_ENV+=		PATH=${PATH}
.      endif

# Ensure this is always in subchild environments
.      if defined(CCACHE_DIR)
#.MAKEFLAGS:		CCACHE_DIR=${CCACHE_DIR}
MAKE_ENV+=		CCACHE_DIR="${CCACHE_DIR}"
CONFIGURE_ENV+=	CCACHE_DIR="${CCACHE_DIR}"
.      endif
.    endif

# Some ports will truncate CCACHE_DIR from the env and due to HOME=${WRKDIR}
# will incorrectly use ${WRKDIR}/.ccache.  Symlink to the proper place.
${WRKDIR}/.ccache: ${WRKDIR}
	@${LN} -sf ${CCACHE_DIR} ${WRKDIR}/.ccache
ccache-wrkdir-link: ${WRKDIR}/.ccache .PHONY
post-extract: ccache-wrkdir-link

# enable ccache in case of USES=llvm and cmake
.    if defined(_INCLUDE_USES_LLVM_MK) && \
        defined(_INCLUDE_USES_CMAKE_MK)
CMAKE_ARGS+=	-DCMAKE_C_COMPILER_LAUNCHER=${CCACHE_BIN} \
              -DCMAKE_CXX_COMPILER_LAUNCHER=${CCACHE_BIN}
.    endif
.  endif

.endif
