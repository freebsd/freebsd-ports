# Handle dependencies on Blas / Lapack
#
# Feature:	blaslapack
# Usage:	USES=blaslapack or USES=blaslapack:ARGS
# Valid ARGS:	atlas blis flexiblas netlib (default) openblas openblas64
#
# Provides:	BLASLIB and LAPACKLIB
#
# Maintainer:	thierry@FreeBSD.org
#
# /!\ Avoid mixing libraries using different BLAS-LAPACK implementations!

.if !defined(_INCLUDE_USES_BLASLAPACK_MK)
_INCLUDE_USES_BLASLAPACK_MK=	yes

_valid_ARGS=	atlas blis flexiblas netlib openblas openblas64

_DEFAULT_BLASLAPACK=	netlib

.  if empty(blaslapack_ARGS)
blaslapack_ARGS=	${_DEFAULT_BLASLAPACK}
.  endif

LDFLAGS+=	-L${LOCALBASE}/lib

.  if ${blaslapack_ARGS} == atlas
LIB_DEPENDS+=	libatlas.so:math/atlas
_BLASLIB=	ptf77blas
LAPACKLIB=	-lalapack -lptcblas
_ATLASLIB=	atlas
ATLASLIB=	-l${_ATLASLIB}
BLA_VENDOR=	ATLAS
.  elif ${blaslapack_ARGS} == blis
LIB_DEPENDS+=	libblis.so:math/blis
LIB_DEPENDS+=	libflame.so:math/libflame
_BLASLIB=	blis
LAPACKLIB=	-lflame
BLA_VENDOR=	FLAME
.  elif ${blaslapack_ARGS} == flexiblas
LIB_DEPENDS+=	libflexiblas.so:math/flexiblas
_BLASLIB=	flexiblas
BLA_VENDOR=	FlexiBLAS
.  elif ${blaslapack_ARGS} == netlib
LIB_DEPENDS+=	libblas.so:math/blas
LIB_DEPENDS+=	liblapack.so:math/lapack
_BLASLIB=	blas
LAPACKLIB=	-llapack
BLA_VENDOR=	Generic
.  elif ${blaslapack_ARGS} == openblas
LIB_DEPENDS+=	libopenblas.so:math/openblas
_BLASLIB=	openblas
LAPACKLIB=	-lopenblas
BLA_VENDOR=	OpenBLAS
.  elif ${blaslapack_ARGS} == openblas64
LIB_DEPENDS+=	libopenblas_64.so:math/openblas64
_BLASLIB=	openblas_64
LAPACKLIB=	-lopenblas_64
BLA_VENDOR=	OpenBLAS
CFLAGS+=	-I${LOCALBASE}/include/openblas64
.  else
IGNORE=		USES=blaslapack: invalid arguments: ${blaslapack_ARGS}
.  endif

BLASLIB=	-l${_BLASLIB}

.  if ${USES:Mcmake} || ${USES:Mcmake\:*}
CONFIGURE_ENV+=	BLA_VENDOR="${BLA_VENDOR}"
.  endif

.endif
