#
# $FreeBSD$
#
# bsd.cabal.options.mk -- Support options for ports based on Haskell Cabal.
#
# Created by: Gabor Pali <pgj@FreeBSD.org>
#
# Maintained by: haskell@FreeBSD.org
#

CABALOPTIONSMKINCLUDED=	yes

HSPREFIX=		hs-
PKGNAMEPREFIX?=		${HSPREFIX}

LOCALBASE?=	/usr/local
GHC_CMD?=	${LOCALBASE}/bin/ghc
HADDOCK_CMD?=	${LOCALBASE}/bin/haddock
HSCOLOUR_CMD?=	${LOCALBASE}/bin/HsColour

GHC_VERSION?=	7.10.2
LLVM_VERSION=	35

HSCOLOUR_DESC?=	Colorize generated documentation by HsColour
DYNAMIC_DESC?=	Add support for dynamic linking
PROFILE_DESC?=	Add support for profiling
LLVM_DESC?=	Use the LLVM backend for code generation
PCLANG_DESC=		Build with Clang from ports
BCLANG_DESC=		Build with Clang from base

OPTIONS_SINGLE+=		C_Compiler
OPTIONS_SINGLE_C_Compiler=	GCC PCLANG BCLANG
OPTIONS_DEFAULT+=		GCC

.if (!exists(${GHC_CMD}) || exists(${LOCALBASE}/lib/ghc-${GHC_VERSION}/rts/libHSrts-ghc${GHC_VERSION}.so)) && !defined(IGNORE_DYNAMIC)
OPTIONS_DEFINE+=	DYNAMIC
OPTIONS_DEFAULT+=	DYNAMIC
.endif

.if (!exists(${GHC_CMD}) || exists(${LOCALBASE}/lib/ghc-${GHC_VERSION}/rts/libHSrts_p.a)) && !defined(IGNORE_PROFILE)
OPTIONS_DEFINE+=	PROFILE
.endif

.if !defined(IGNORE_LLVM)
OPTIONS_DEFINE+=	LLVM
.endif

.if ((!exists(${GHC_CMD}) || exists(${LOCALBASE}/lib/ghc-${GHC_VERSION}/html)) || exists(${HADDOCK_CMD})) && !defined(IGNORE_DOCS)
OPTIONS_DEFINE+=	DOCS
OPTIONS_DEFAULT+=	DOCS
HADDOCK_AVAILABLE=	yes

.if (${PORTNAME} != hscolour || exists(${HSCOLOUR_CMD})) && !defined(IGNORE_HSCOLOUR)
OPTIONS_DEFINE+=	HSCOLOUR
.endif
.endif

.if defined(OPTIONSMKINCLUDED)
IGNORE?=	options fail: bsd.cabal.mk already includes bsd.options.mk
.endif

OPTIONS_DEFINE+=	${FLAGS_DEFINE}
OPTIONS_SINGLE+=	${FLAGS_SINGLE}
OPTIONS_MULTI+=		${FLAGS_MULTI}
OPTIONS_DEFAULT+=	${FLAGS_DEFAULT}

_ALL_FLAGS:=		${FLAGS_DEFINE} ${FLAGS_SINGLE} ${FLAGS_MULTI}
_COMPLETE_FLAGS=	${_ALL_FLAGS}

.for f in ${_ALL_FLAGS}
.  if defined(FLAGS_SINGLE_${f})
_COMPLETE_FLAGS+=	${FLAGS_SINGLE_${f}}
OPTIONS_SINGLE_${f}=	${FLAGS_SINGLE_${f}}
.  endif
.  if defined(FLAGS_MULTI_${f})
_COMPLETE_FLAGS+=	${FLAGS_MULTI_${f}}
OPTIONS_MULTI_${f}=	${FLAGS_MULTI_${f}}
.  endif
.endfor

.include <bsd.port.options.mk>

.for f in ${_COMPLETE_FLAGS}
.  if defined(${f}_FLAG_DEPENDS)
.    for r in ${${f}_FLAG_DEPENDS}
.      if !${PORT_OPTIONS:M${r}}
_${f}_DEPENDS_FAIL=	yes
.      endif
.    endfor
.  endif
.  if ${PORT_OPTIONS:M${f}} && !defined(_${f}_DEPENDS_FAIL)
.    if defined(${f}_FLAG_ENABLE)
CONFIGURE_ARGS+=	--flags="${${f}_FLAG_ENABLE}"
.    endif
.    if defined(${f}_FLAG_CONFIGURE_ON)
CONFIGURE_ARGS+=	${${f}_FLAG_CONFIGURE_ON}
.    endif
.    if defined(${f}_FLAG_CABAL)
USE_CABAL+=		${${f}_FLAG_CABAL}
.    endif
.    if defined(${f}_FLAG_EXECUTABLE)
EXECUTABLE+=		${${f}_FLAG_EXECUTABLE}
.    endif
.    if defined(${f}_FLAG_LIB)
LIB_DEPENDS+=		${${f}_FLAG_LIB}
.    endif
.    if defined(${f}_FLAG_XORG)
USE_XORG+=		${${f}_FLAG_XORG}
.    endif
.    if defined(${f}_BROKEN)
BROKEN=			${${f}_BROKEN} with the ${f} flag enabled
.    endif
.    if defined(${f}_DYNAMIC_BROKEN) && ${PORT_OPTIONS:MDYNAMIC}
BROKEN=			${${f}_DYNAMIC_BROKEN}
.    endif
.  else
.    if defined(${f}_FLAG_ENABLE)
CONFIGURE_ARGS+=	--flags="-${${f}_FLAG_ENABLE}"
.    endif
.    if defined(${f}_FLAG_CONFIGURE_OFF)
CONFIGURE_ARGS+=	${${f}_FLAG_CONFIGURE_OFF}
.    endif
.  endif
.endfor

.if defined(FLAGS_ENABLE)
CONFIGURE_ARGS+=	--flags="${FLAGS_ENABLE}"
.endif

.if defined(FLAGS_DISABLE)
.  for f in ${FLAGS_DISABLE}
CONFIGURE_ARGS+=	--flags="-${f}"
.  endfor
.endif
