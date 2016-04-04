# $FreeBSD$

COMMANDS_Include_MAINTAINER=	portmgr@FreeBSD.org

.if !defined(_CCACHEMKINCLUDED)

_CCACHEMKINCLUDED=	yes

# HOME is always set to ${WRKDIR} now. Try to use /root/.ccache as default.
.if defined(WITH_CCACHE_BUILD) && !defined(CCACHE_DIR)
.  if defined(USER) && ${USER} == root
CCACHE_DIR=	/root/.ccache
.  else
NO_CCACHE=	yes
WARNING+=	WITH_CCACHE_BUILD support disabled, please set CCACHE_DIR.
.  endif
.endif

# Support NO_CCACHE for common setups, require WITH_CCACHE_BUILD, and
# don't use if ccache already set in CC
.if !defined(NO_CCACHE) && defined(WITH_CCACHE_BUILD) && !${CC:M*ccache*} && \
  !defined(NO_BUILD) && !defined(NOCCACHE)
# Avoid depends loops between ccache and pkg
.	if ${PKGORIGIN} != devel/ccache && ${PKGORIGIN} != ${PKG_ORIGIN}
BUILD_DEPENDS+=		${LOCALBASE}/bin/ccache:devel/ccache
.	endif

_CCACHE_PATH=	${LOCALBASE}/libexec/ccache

# Prepend the ccache dir into the PATH and setup ccache env
PATH:=	${_CCACHE_PATH}:${PATH}
#.MAKEFLAGS:		PATH=${PATH}
.if !${MAKE_ENV:MPATH=*} && !${CONFIGURE_ENV:MPATH=*}
MAKE_ENV+=			PATH=${PATH}
CONFIGURE_ENV+=		PATH=${PATH}
.endif

# Ensure this is always in subchild environments
.	if defined(CCACHE_DIR)
#.MAKEFLAGS:		CCACHE_DIR=${CCACHE_DIR}
MAKE_ENV+=		CCACHE_DIR="${CCACHE_DIR}"
CONFIGURE_ENV+=	CCACHE_DIR="${CCACHE_DIR}"
.	endif
.endif

.endif
