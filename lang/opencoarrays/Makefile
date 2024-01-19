PORTNAME=	opencoarrays
DISTVERSION=	2.10.1
PORTREVISION=	1
CATEGORIES=	lang parallel

MAINTAINER=	miguel@gocobachi.dev
COMMENT=	Transport layer for coarray Fortran compilers
WWW=		http://www.opencoarrays.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_aarch64=	lack of IEEE754 support in gcc causes "Cannot find an intrinsic module named 'ieee_arithmetic'", see bug #255890

BUILD_DEPENDS=	bash:shells/bash
RUN_DEPENDS=	bash:shells/bash

USES=		cmake fortran
USE_CSTD=	gnu99
USE_GCC=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	sourceryinstitute
GH_PROJECT=	OpenCoarrays
USE_LDCONFIG=	yes

PLIST_SUB=	GCC_VER=${_GCC_VER} \
		PORTVERSION=${PORTVERSION} \
		SOVERSION=3

OPTIONS_SINGLE=		MPI
OPTIONS_SINGLE_MPI=	MPICH OPENMPI
OPTIONS_DEFAULT=	MPICH
OPTIONS_EXCLUDE_armv6=	MPICH
OPTIONS_EXCLUDE_armv7=	MPICH
OPTIONS_EXCLUDE_i386=	MPICH
OPTIONS_EXCLUDE_mips=	MPICH
OPTIONS_EXCLUDE_powerpc=	MPICH
OPTIONS_EXCLUDE_powerpcspe=	MPICH
OPTIONS_DEFAULT_armv6=	OPENMPI
OPTIONS_DEFAULT_armv7=	OPENMPI
OPTIONS_DEFAULT_i386=	OPENMPI
OPTIONS_DEFAULT_mips=	OPENMPI
OPTIONS_DEFAULT_powerpc=	OPENMPI
OPTIONS_DEFAULT_powerpcspe=	OPENMPI

CMAKE_C_COMPILER=	gcc

MPICH_BUILD_DEPENDS=	mpif90:net/mpich
MPICH_RUN_DEPENDS=	mpif90:net/mpich
MPICH_CONFIGURE_ENV=	MPI_HOME=${LOCALBASE}

OPENMPI_BUILD_DEPENDS=	${LOCALBASE}/mpi/openmpi/bin/mpif90:net/openmpi
OPENMPI_RUN_DEPENDS=	${LOCALBASE}/mpi/openmpi/bin/mpif90:net/openmpi
OPENMPI_CONFIGURE_ENV=	MPI_HOME=${LOCALBASE}/mpi/openmpi
OPENMPI_CMAKE_ON=	-DMPI_C_COMPILE_OPTIONS="-lpthread" \
			-DMPI_Fortran_COMPILE_OPTIONS="-lpthread"

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} '/mod_dir_tail/s/$${CMAKE_Fortran_COMPILER_VERSION}/${_GCC_VER}/' \
		${WRKSRC}/CMakeLists.txt

do-test:
	(cd ${TEST_WRKSRC} && ctest)

.include <bsd.port.mk>
