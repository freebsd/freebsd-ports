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

# Sanity check
.for arg in ${pure_ARGS}
.    if empty(_valid_ARGS:M${arg})
IGNORE= Incorrect 'USES+= pure:${pure_ARGS}' usage: argument [${arg}] is not recognized
.    endif
.endfor

LIB_DEPENDS+=	libpure.so:lang/pure
.include "${USESDIR}/gmake.mk"

.if ${pure_ARGS:Mffi}
RUN_DEPENDS+=	${LOCALBASE}/lib/pure/ffi.pure:devel/pure-ffi
.endif

MAKE_ARGS+=	prefix=${PREFIX} mandir=${PREFIX}/man \
		CC=${CC} CFLAGS="${CFLAGS}" \
		CXX=${CXX} CXXFLAGS="${CXXFLAGS}" \
		CPPFLAGS+=-I${LOCALBASE}/include \
		LDFLAGS+=-L${LOCALBASE}/lib

.endif #!defined(_INCLUDE_USES_PURE_MK)
