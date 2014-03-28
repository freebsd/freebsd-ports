# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$
#
# Provide support for Pure Programming Language based projects
#
# Feature:		pure
# Usage:		USES=pure or USES=pure:ARGS
# Valid ARGS:		ffi
# ARGS description:
# ffi			makes the port depends on pure-ffi at runtime
#
# MAINTAINER= nemysis@FreeBSD.org

.if !defined(_INCLUDE_USES_PURE_MK)
_INCLUDE_USES_PURE_MK=	yes

_valid_ARGS=		ffi
_pure_ARGS=		${pure_ARGS:C/\:/ /g}

# Sanity check
.if defined(pure_ARGS)
.  for arg in ${_pure_ARGS}
.    if empty(_valid_ARGS:M${arg})
IGNORE= Incorrect 'USES+= pure:${pure_ARGS}' usage: argument [${arg}] is not recognized
.    endif
.  endfor
.endif

LIB_DEPENDS+=	libpure.so:${PORTSDIR}/lang/pure
.include "${USESDIR}/gmake.mk"

.if ${_pure_ARGS:Mffi}
RUN_DEPENDS+=	${LOCALBASE}/lib/pure/ffi.pure:${PORTSDIR}/devel/pure-ffi
.endif

MAKE_ARGS+=	prefix=${PREFIX} mandir=${PREFIX}/man \
		CC=${CC} CFLAGS="${CFLAGS}" \
		CXX=${CXX} CXXFLAGS="${CXXFLAGS}" \
		CPPFLAGS+=-I${LOCALBASE}/include \
		LDFLAGS+=-L${LOCALBASE}/lib

.endif #!defined(_INCLUDE_USES_PURE_MK)
