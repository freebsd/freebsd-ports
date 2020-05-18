# Created by: Anton Shterenlikht
# $FreeBSD$

PORTNAME=	opencoarrays
DISTVERSION=	2.7.1
PORTREVISION=	3
CATEGORIES=	lang parallel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Transport layer for coarray Fortran compilers

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_aarch64=		fails to build: Can't open module file 'ieee_arithmetic.mod' for reading at (1): No such file or directory
BROKEN_FreeBSD_12_powerpc64=	fails to build: CMake Warning at CMakeLists.txt:280 (message): Could not find all MPI components!
BROKEN_FreeBSD_13_powerpc64=	fails to build: Can't open module file 'ieee_arithmetic.mod' for reading at (1): No such file or directory

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
OPTIONS_SINGLE_MPI=	MPICH OPENMPI
OPTIONS_DEFAULT=	MPICH

MPICH_DESC=		Parallel processing support via MPICH
MPICH_BUILD_DEPENDS=	mpif90:net/mpich
MPICH_RUN_DEPENDS=	mpif90:net/mpich
MPICH_CONFIGURE_ENV=	MPI_HOME=${LOCALBASE}

OPENMPI_BUILD_DEPENDS=	${LOCALBASE}/mpi/openmpi/bin/mpif90:net/openmpi
OPENMPI_RUN_DEPENDS=	${LOCALBASE}/mpi/openmpi/bin/mpif90:net/openmpi
OPENMPI_CONFIGURE_ENV=	MPI_HOME=${LOCALBASE}/mpi/openmpi
OPENMPI_CMAKE_ON=	-DMPI_C_COMPILE_OPTIONS="-lpthread" \
			-DMPI_Fortran_COMPILE_OPTIONS="-lpthread"

.include <bsd.port.options.mk>

.if ${GCC_DEFAULT} >= 8
PLIST_SUB+=	SOVERSION=3
.elif ${GCC_DEFAULT} == 7
PLIST_SUB+=	SOVERSION=2
.elif ${GCC_DEFAULT} == 6
PLIST_SUB+=	SOVERSION=1
.else
IGNORE=		requires GCC 6 or higher
.endif

post-patch:
	@${REINPLACE_CMD} '/mod_dir_tail/s/$${CMAKE_Fortran_COMPILER_VERSION}/${_GCC_VER}/' \
		${WRKSRC}/CMakeLists.txt

do-test:
	(cd ${TEST_WRKSRC} && ctest)

.include <bsd.port.mk>
