# $FreeBSD$
#
# Fortran support
#
# Feature:	fortran
# Usage:	USES=fortran
# Valid ARGS:	flang, gfortran (default)
#
# MAINTAINER:	fortran@FreeBSD.org

.if !defined(_INCLUDE_USES_FORTRAN_MK)
_INCLUDE_USES_FORTRAN_MK=	yes

.if empty(fortran_ARGS)
fortran_ARGS=	${FORTRAN_DEFAULT}
.endif

.if ${fortran_ARGS} == flang
.if ${ARCH} == amd64
BUILD_DEPENDS+=	flang>0:devel/flang
RUN_DEPENDS+=	flang>0:devel/flang
F77=		flang
FC=		flang
LDFLAGS+=	-L${LOCALBASE}/flang/lib -Wl,--as-needed -lflang -lexecinfo -Wl,--no-as-needed
.else
IGNORE=		USES=fortran: flang argument only available for amd64
.endif
.elif ${fortran_ARGS} == gfortran
_GCC_VER=	${GCC_DEFAULT:S/.//}
BUILD_DEPENDS+=	gfortran${_GCC_VER}:lang/gcc${_GCC_VER}
RUN_DEPENDS+=	gfortran${_GCC_VER}:lang/gcc${_GCC_VER}
F77=		gfortran${_GCC_VER}
FC=		gfortran${_GCC_VER}
FFLAGS+=	-Wl,-rpath=${LOCALBASE}/lib/gcc${_GCC_VER}
FCFLAGS+=	-Wl,-rpath=${LOCALBASE}/lib/gcc${_GCC_VER}
LDFLAGS+=	-Wl,-rpath=${LOCALBASE}/lib/gcc${_GCC_VER} \
		-L${LOCALBASE}/lib/gcc${_GCC_VER} -B${LOCALBASE}/bin
.else
IGNORE=		USES=fortran: invalid arguments: ${fortran_ARGS}
.endif

USE_BINUTILS=	yes
CONFIGURE_ENV+=	F77="${F77}" FC="${FC}" FFLAGS="${FFLAGS}" FCFLAGS="${FCFLAGS}"
MAKE_ENV+=	F77="${F77}" FC="${FC}" FFLAGS="${FFLAGS}" FCFLAGS="${FCFLAGS}"

.endif
