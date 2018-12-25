# Created by: Anton Shterenlikht
# $FreeBSD$

PORTNAME=	opencoarrays
DISTVERSION=	2.2.0
PORTREVISION=	3
CATEGORIES=	lang parallel

MAINTAINER=	as@cmplx.uk
COMMENT=	Transport layer for coarray Fortran compilers

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_aarch64=		fails to build: Can't open module file 'ieee_arithmetic.mod' for reading at (1): No such file or directory

BUILD_DEPENDS=	bash:shells/bash
RUN_DEPENDS=	bash:shells/bash

USES=		cmake fortran
USE_CSTD=	gnu99
USE_GITHUB=	yes
GH_ACCOUNT=	sourceryinstitute
GH_PROJECT=	OpenCoarrays
USE_LDCONFIG=	yes

PLIST_SUB=	GCC_VER=${_GCC_VER} PORTVERSION=${PORTVERSION}

OPTIONS_SINGLE=		MPI
OPTIONS_SINGLE_MPI=	MPICH OPENMPI OPENMPI2
OPTIONS_DEFAULT=	MPICH

MPICH_DESC=		Parallel processing support via MPICH
MPICH_BUILD_DEPENDS=	mpif90:net/mpich
MPICH_RUN_DEPENDS=	mpif90:net/mpich
MPICH_CONFIGURE_ENV=	MPI_HOME=${LOCALBASE}

OPENMPI_BUILD_DEPENDS=	${LOCALBASE}/mpi/openmpi/bin/mpif90:net/openmpi
OPENMPI_RUN_DEPENDS=	${LOCALBASE}/mpi/openmpi/bin/mpif90:net/openmpi
OPENMPI_CONFIGURE_ENV=	MPI_HOME=${LOCALBASE}/mpi/openmpi

OPENMPI2_DESC=		Parallel processing support via Open MPI v2
OPENMPI2_BUILD_DEPENDS=	${LOCALBASE}/mpi/openmpi2/bin/mpif90:net/openmpi2
OPENMPI2_RUN_DEPENDS=	${LOCALBASE}/mpi/openmpi2/bin/mpif90:net/openmpi2
OPENMPI2_CONFIGURE_ENV=	MPI_HOME=${LOCALBASE}/mpi/openmpi2

.include <bsd.port.options.mk>

.if ${GCC_DEFAULT} >= 8
PLIST_SUB+=	SOVERSION=3
.elif ${GCC_DEFAULT} == 7
PLIST_SUB+=	SOVERSION=2
.elif ${GCC_DEFAULT} == 6
PLIST_SUB+=	SOVERSION=1
.elif ${GCC_DEFAULT} == 5
PLIST_SUB+=	SOVERSION=0
.else
IGNORE=		requires GCC 5 or higher
.endif

post-patch:
	@${REINPLACE_CMD} '/mod_dir_tail/s/$${CMAKE_Fortran_COMPILER_VERSION}/${_GCC_VER}/' \
		${WRKSRC}/CMakeLists.txt

do-test:
	(cd ${TEST_WRKSRC} && ctest)

.include <bsd.port.mk>
