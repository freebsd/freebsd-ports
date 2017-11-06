# Created by: Anton Shterenlikht
# $FreeBSD$

PORTNAME=	opencoarrays
PORTVERSION=	1.9.1
PORTREVISION=	1
CATEGORIES=	lang parallel

MAINTAINER=	as@cmplx.uk
COMMENT=	Transport layer for coarray Fortran compilers

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash:shells/bash
RUN_DEPENDS=	bash:shells/bash

USE_GITHUB=	yes
GH_ACCOUNT=	sourceryinstitute
GH_PROJECT=	OpenCoarrays

USES=		cmake:outsource fortran shebangfix
PLIST_SUB=	GCC_VER=${_GCC_VER}
SHEBANG_FILES=	src/extensions/caf-head \
		src/extensions/cafrun-head

OPTIONS_SINGLE=		MPI
OPTIONS_SINGLE_MPI=	MPICH OPENMPI OPENMPI2
OPTIONS_DEFAULT=	MPICH

MPICH_DESC=		Parallel processing support via MPICH
MPICH_BUILD_DEPENDS=	mpif90:net/mpich
MPICH_RUN_DEPENDS=	mpif90:net/mpich

OPENMPI_BUILD_DEPENDS=	${LOCALBASE}/mpi/openmpi/bin/mpif90:net/openmpi
OPENMPI_RUN_DEPENDS=	${LOCALBASE}/mpi/openmpi/bin/mpif90:net/openmpi
OPENMPI_CONFIGURE_ENV=	MPI_HOME=${LOCALBASE}/mpi/openmpi

OPENMPI2_DESC=		Parallel processing support via Open MPI v2
OPENMPI2_BUILD_DEPENDS=	${LOCALBASE}/mpi/openmpi2/bin/mpif90:net/openmpi2
OPENMPI2_RUN_DEPENDS=	${LOCALBASE}/mpi/openmpi2/bin/mpif90:net/openmpi2
OPENMPI2_CONFIGURE_ENV=	MPI_HOME=${LOCALBASE}/mpi/openmpi2

.include <bsd.port.options.mk>

.if ${GCC_DEFAULT:R} < 5
IGNORE=		requires GCC 5 or higher.  Add DEFAULT_VERSIONS+=gcc=5 to /etc/make.conf
.endif

post-patch:
	@${REINPLACE_CMD} '/mod_install/s/$${CMAKE_Fortran_COMPILER_VERSION}/${_GCC_VER}/' \
		${WRKSRC}/src/mpi/CMakeLists.txt

do-test:
	(cd ${TEST_WRKSRC} && ctest)

.include <bsd.port.mk>
