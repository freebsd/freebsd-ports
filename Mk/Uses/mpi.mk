# $FreeBSD$
#
# Handle dependencies on MPICH / OpenMPI
#
# Feature:	mpi
# Usage:	USES=mpi or USES=mpi:ARGS
# Valid ARGS:	mpich (default) openmpi
# Note: mpich2 and openmpi3 are not handled
#
# Provides:	MPI_LIBS MPI_CFLAGS MPICC MPICXX MPIF90 MPIFC MPI_HOME	\
#		MPIEXEC MPIRUN
# Sets:		LIB_DEPENDS
#		+ CMAKE_ARGS if cmake is enabled to drive FindMPI.cmake
#
# Maintainer:	thierry@FreeBSD.org

.if !defined(_INCLUDE_USES_MPI_MK)
_INCLUDE_USES_MPI_MK=	yes

_valid_ARGS=	mpich openmpi

_DEFAULT_MPI=	mpich

.if empty(mpi_ARGS)
mpi_ARGS=	${_DEFAULT_MPI}
.endif

.if ! ${USES:Mpkgconfig}
USES+=	pkgconfig
.endif

.if ${mpi_ARGS} == mpich
LIB_DEPENDS+=	libmpich.so:net/mpich
MPI_HOME=	${LOCALBASE}
MPI_LIBS+=	`pkgconf --libs mpich`
. if ${USES:Mfortran}
MPI_LIBS+=	-lmpifort
MPIFC=		${MPI_HOME}/bin/mpif90
MPIF90=		${MPIFC}
. endif
MPI_CFLAGS+=	`pkgconf --cflags mpich`
.elif ${mpi_ARGS} == openmpi
LIB_DEPENDS+=	libmpi_cxx.so:net/openmpi
MPI_HOME=	${LOCALBASE}/mpi/openmpi
. if ${USES:Mfortran}
MPI_LIBS+=	`pkgconf --libs ompi-fort`
MPIFC=		${MPI_HOME}/bin/mpif90
MPIF90=		${MPIFC}
. else
MPI_LIBS+=	`pkgconf --libs ompi`
. endif
MPI_CFLAGS+=	`pkgconf --cflags ompi`
.else
IGNORE=		USES=mpi: invalid arguments: ${mpi_ARGS}
.endif

MPICC=		${MPI_HOME}/bin/mpicc
MPICXX=		${MPI_HOME}/bin/mpicxx
MPIEXEC=	${MPI_HOME}/bin/mpiexec
MPIRUN=		${MPI_HOME}/bin/mpirun

.if ${USES:Mcmake}
CMAKE_ARGS+=	-DMPIEXEC_EXECUTABLE:FILEPATH="${MPIEXEC}"	\
		-DMPI_HOME:PATH="${MPI_HOME}"
.endif

.endif
