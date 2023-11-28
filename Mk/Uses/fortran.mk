# Fortran support
#
# Feature:	fortran
# Usage:	USES=fortran
# Valid ARGS:	gfortran
#
# MAINTAINER:	fortran@FreeBSD.org

.if !defined(_INCLUDE_USES_FORTRAN_MK)
_INCLUDE_USES_FORTRAN_MK=	yes

.  if empty(fortran_ARGS)
fortran_ARGS=	${FORTRAN_DEFAULT}
.  endif

.  if ${fortran_ARGS} == gfortran
.    if empty(USE_GCC)
_GCC_VER=	${GCC_DEFAULT:S/.//}
.    else
_GCC_VER=	${_USE_GCC}
.    endif
BUILD_DEPENDS+=	gfortran${_GCC_VER}:lang/gcc${_GCC_VER}
RUN_DEPENDS+=	gfortran${_GCC_VER}:lang/gcc${_GCC_VER}
F77=		gfortran${_GCC_VER}
F90=		gfortran${_GCC_VER}
FC=		gfortran${_GCC_VER}
FFLAGS+=	-Wl,-rpath=${LOCALBASE}/lib/gcc${_GCC_VER}
F90FLAGS+=	-Wl,-rpath=${LOCALBASE}/lib/gcc${_GCC_VER}
FCFLAGS+=	-Wl,-rpath=${LOCALBASE}/lib/gcc${_GCC_VER}
LDFLAGS+=	-Wl,-rpath=${LOCALBASE}/lib/gcc${_GCC_VER} \
		-L${LOCALBASE}/lib/gcc${_GCC_VER}
CFLAGS_F2018=	-I${LOCALBASE}/include/gcc${_GCC_VER}
.  else
IGNORE=		USES=fortran: invalid arguments: ${fortran_ARGS}
.  endif

USE_BINUTILS=	yes
CONFIGURE_ENV+=	F77="${F77}" F90="${FC}" FC="${FC}"	\
		FFLAGS="${FFLAGS}" F90FLAGS="${FFLAGS}" FCFLAGS="${FCFLAGS}"
MAKE_ENV+=	F77="${F77}" F90="${FC}" FC="${FC}"	\
		FFLAGS="${FFLAGS}" F90FLAGS="${FFLAGS}" FCFLAGS="${FCFLAGS}"

.endif
