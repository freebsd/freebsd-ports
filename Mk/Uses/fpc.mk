# Support for FPC-based ports. This automatically will install free pascal 
# compiler and units.
#
# Feature:      fpc
# Usage:        USES=fpc
# Valid ARGS:   (none), run
#
# run			- Free pascal compiler and units will be registered also
#			  as run dependencies.
#
# Example:
#	
#	USES+=	fpc:run
#

.if !defined(_INCLUDE_USES_FPC_MK)

FPC_Include_MAINTAINER= acm@FreeBSD.org

_INCLUDE_USES_FPC_MK=   yes

.  if defined(DEFAULT_FPC_VER)
WARNING+=	"DEFAULT_FPC_VER is defined, consider using DEFAULT_VERSIONS=fpc=${DEFAULT_FPC_VER} instead"
.  endif

.  if ${fpc_ARGS:Nrun}
IGNORE=		Unknown argument for USES=fpc: ${fpc_ARGS:Nrun}
.  endif

DEFAULT_FPC_VER=	${FPC_DEFAULT}
# When adding a version, please keep the comment in
# Mk/bsd.default-versions.mk in sync.
FPC_VER=		${DEFAULT_FPC_VER}
FPC_ARCH=		${ARCH:S/amd64/x86_64/}

.  if exists(${LOCALBASE}/bin/fpc)
FPC_CURRENT_VER!=	${LOCALBASE}/bin/fpc -iV
.    if ${FPC_CURRENT_VER} != ${FPC_VER}
IGNORE=	incompatible fpc ${FPC_CURRENT_VER} compiler, please install ${FPC_VER} version
.    endif
.  endif

.  if ${ARCH} == "i386"
PPNAME=			ppc386
.  elif ${ARCH} == "amd64"
PPNAME=			ppcx64
.  else
PPNAME=			ppc_not_yet_ported
ONLY_FOR_ARCHS=		i386 amd64
ONLY_FOR_ARCHS_REASON=	not yet ported to anything other than i386 and amd64
.  endif

.  if !defined(WANT_FPC_DEVEL)
FPC_DEVELSUFFIX=	#
.  else
FPC_DEVELSUFFIX=	-devel
.  endif

BUILD_DEPENDS+=		${LOCALBASE}/bin/as:devel/binutils \
			${LOCALBASE}/lib/fpc/${FPC_VER}/${PPNAME}:lang/fpc${FPC_DEVELSUFFIX}

.  if ${fpc_ARGS:Mrun}
RUN_DEPENDS+=		${LOCALBASE}/bin/as:devel/binutils \
			${LOCALBASE}/lib/fpc/${FPC_VER}/${PPNAME}:lang/fpc${FPC_DEVELSUFFIX}
.  endif

BUILDNAME=		${FPC_ARCH}-${OPSYS:tl}
UNITSDIR=		${LOCALBASE}/lib/fpc/${FPC_VER}/units/${BUILDNAME}
MKINSTDIR=		${LOCALBASE}/lib/fpc/${FPC_VER}/fpmkinst/${BUILDNAME}

.endif
