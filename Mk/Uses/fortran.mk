# $FreeBSD$
#
# Fortran support
#
# Feature:	fortran
# Usage:	USES=fortran
# Valid ARGS:	gcc (default)
#
# MAINTAINER:	fortran@FreeBSD.org

.if !defined(_INCLUDE_USES_FORTRAN_MK)
_INCLUDE_USES_FORTRAN_MK=	yes

.if empty(fortran_ARGS)
fortran_ARGS=	gcc
.endif

.if ${fortran_ARGS} == gcc
.include "${PORTSDIR}/Mk/bsd.default-versions.mk"
_GCC_VER=	${GCC_DEFAULT:S/.//}
.if ${GCC_DEFAULT} == ${LANG_GCC_IS}
BUILD_DEPENDS+=	gfortran${_GCC_VER}:lang/gcc
RUN_DEPENDS+=	gfortran${_GCC_VER}:lang/gcc
.else
BUILD_DEPENDS+=	gfortran${_GCC_VER}:lang/gcc${_GCC_VER}
RUN_DEPENDS+=	gfortran${_GCC_VER}:lang/gcc${_GCC_VER}
.endif
USE_BINUTILS=	yes
F77=		gfortran${_GCC_VER}
FC=		gfortran${_GCC_VER}
FFLAGS+=	-Wl,-rpath=${LOCALBASE}/lib/gcc${_GCC_VER}
FCFLAGS+=	-Wl,-rpath=${LOCALBASE}/lib/gcc${_GCC_VER}
LDFLAGS+=	-Wl,-rpath=${LOCALBASE}/lib/gcc${_GCC_VER} \
		-L${LOCALBASE}/lib/gcc${_GCC_VER} -B${LOCALBASE}/bin
.else
IGNORE=		USES=fortran: invalid arguments: ${fortran_ARGS}
.endif

CONFIGURE_ENV+=	F77="${F77}" FC="${FC}" FFLAGS="${FFLAGS}" FCFLAGS="${FCFLAGS}"
MAKE_ENV+=	F77="${F77}" FC="${FC}" FFLAGS="${FFLAGS}" FCFLAGS="${FCFLAGS}"

.endif
