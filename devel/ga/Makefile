PORTNAME=	ga
DISTVERSION=	5.9.2
CATEGORIES=	devel
MASTER_SITES=	https://github.com/GlobalArrays/ga/releases/download/v${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Partitioned Global Address Space (PGAS) library for distributed arrays
WWW=		https://globalarrays.github.io/ \
		https://github.com/GlobalArrays/ga

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libblas.so:math/blas \
		liblapack.so:math/lapack \
		libscalapack.so:math/scalapack

USES=		autoreconf fortran gmake libtool localbase
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-peigs --enable-shared --disable-static --with-scalapack # PeIGS is part of NWChem, usure why the --enable-peigs even exists here

LDFLAGS+=	-lscalapack

INSTALL_TARGET=	install-strip
TEST_TARGET=	check # test asserts, see https://github.com/GlobalArrays/ga/issues/312

MPIEXEC_ARGS=	-np 2

OPTIONS_RADIO=			BLAS_SIZE MPI
OPTIONS_RADIO_BLAS_SIZE=	BLAS_SIZE_4 BLAS_SIZE_8 # the default BLAS_SIZE below should be same as the same choice in science/nwchem and in math/blas or math/openblas
OPTIONS_RADIO_MPI=		MPICH OPENMPI # the default MPI choice below should be the same as for the MPI option in math/scalapack
OPTIONS_DEFAULT=		BLAS_SIZE_4 MPICH

BLAS_SIZE_DESC=		BLAS_SIZE value to use during build (should be same as in devel/ga)
BLAS_SIZE_4_DESC=	BLAS_SIZE=4
BLAS_SIZE_4_CONFIGURE_ON=	--with-blas4
BLAS_SIZE_8_DESC=	BLAS_SIZE=8
BLAS_SIZE_8_CONFIGURE_ON=	--with-blas8

MPICH_LIB_DEPENDS=	libmpich.so:net/mpich
MPICH_VARS=		TEST_ARGS+=MPIEXEC="${LOCALBASE}/bin/mpiexec ${MPIEXEC_ARGS}"

OPENMPI_BUILD_DEPENDS=		openmpi>0:net/openmpi
OPENMPI_RUN_DEPENDS=		openmpi>0:net/openmpi
OPENMPI_CONFIGURE_ENV=		CC=${LOCALBASE}/mpi/openmpi/bin/mpicc MPICC=${LOCALBASE}/mpi/openmpi/bin/mpicc \
				CXX=${LOCALBASE}/mpi/openmpi/bin/mpic++ MPICXX=${LOCALBASE}/mpi/openmpi/bin/mpic++ \
				F77=${LOCALBASE}/mpi/openmpi/bin/mpif77 MPIF77=${LOCALBASE}/mpi/openmpi/bin/mpif77 \
				FC=${LOCALBASE}/mpi/openmpi/bin/mpif90 MPIFC=${LOCALBASE}/mpi/openmpi/bin/mpif90 \
				LDFLAGS="-L${LOCALBASE}/mpi/openmpi/lib -Wl,-rpath,${LOCALBASE}/mpi/openmpi/lib"
OPENMPI_MAKE_ARGS=		FREEBSD_LINK_FLAGS="-L${LOCALBASE}/mpi/openmpi/lib -Wl,-rpath,${LOCALBASE}/mpi/openmpi/lib -lmpi"
OPENMPI_VARS=			TEST_ARGS+=MPIEXEC="${LOCALBASE}/mpi/openmpi/bin/mpiexec ${MPIEXEC_ARGS}"

.include <bsd.port.mk>
