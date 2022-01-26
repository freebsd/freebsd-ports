PORTNAME=	ga
DISTVERSION=	5.8.1
CATEGORIES=	devel
MASTER_SITES=	https://github.com/GlobalArrays/ga/releases/download/v${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Partitioned Global Address Space (PGAS) library for distributed arrays

LICENSE=	BMIL
LICENSE_NAME=	Battelle Memorial Institute License
LICENSE_FILE=	${WRKSRC}/COPYRIGHT
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libblas.so:math/blas \
		liblapack.so:math/lapack \
		libscalapack.so:math/scalapack

USES=		autoreconf fortran gmake libtool localbase
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-peigs --enable-shared --disable-static --with-blas4 --with-scalapack
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

LDFLAGS+=	-lscalapack

OPTIONS_RADIO=		MPI
OPTIONS_RADIO_MPI=	MPICH OPENMPI
OPTIONS_DEFAULT=	MPICH # the default should be the same as for the MPI option in math/scalapack

MPICH_LIB_DEPENDS=	libmpich.so:net/mpich

OPENMPI_BUILD_DEPENDS=		openmpi>0:net/openmpi
OPENMPI_RUN_DEPENDS=		openmpi>0:net/openmpi
OPENMPI_CONFIGURE_ENV=		CC=${LOCALBASE}/mpi/openmpi/bin/mpicc MPICC=${LOCALBASE}/mpi/openmpi/bin/mpicc \
				CXX=${LOCALBASE}/mpi/openmpi/bin/mpic++ MPICXX=${LOCALBASE}/mpi/openmpi/bin/mpic++ \
				F77=${LOCALBASE}/mpi/openmpi/bin/mpif77 MPIF77=${LOCALBASE}/mpi/openmpi/bin/mpif77 \
				FC=${LOCALBASE}/mpi/openmpi/bin/mpif90 MPIFC=${LOCALBASE}/mpi/openmpi/bin/mpif90 \
				LDFLAGS="-L${LOCALBASE}/mpi/openmpi/lib -Wl,-rpath,${LOCALBASE}/mpi/openmpi/lib"
OPENMPI_MAKE_ARGS=		FREEBSD_LINK_FLAGS="-L${LOCALBASE}/mpi/openmpi/lib -Wl,-rpath,${LOCALBASE}/mpi/openmpi/lib -lmpi"

.include <bsd.port.mk>
