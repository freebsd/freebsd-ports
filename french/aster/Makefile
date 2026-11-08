PORTNAME=	aster
DISTVERSION=	${ASTER_VER}
CATEGORIES=	french cad

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Code_Aster finite element method solver
WWW=		https://www.code-aster.org/

LICENSE=	GPLv2

NOT_FOR_ARCHS=		armv6 armv7 i386 powerpc
NOT_FOR_ARCHS_REASON=	ARG_MAX is too small for Code_Aster on 32 bits systems

BUILD_DEPENDS=	gnproc:sysutils/coreutils	\
		getopt>=0:misc/getopt		\
		gsed:textproc/gsed		\
		pylupdate5:devel/py-qt5-pyqt	\
		pybind11>=0:devel/pybind11
LIB_DEPENDS=	libAsterInterface.so:science/tfel-edf		\
		libMFrontGenericInterface.so:science/mgis	\
		libarpack.so:math/arpack-ng			\
		libhpddm_petsc.so:science/hpddm_petsc		\
		libhdf5-110.so:science/hdf5-110			\
		libmed.so:french/med				\
		libmedcoupling.so:science/medcoupling		\
		libmetis.so:math/metis				\
		libpetsc.so:science/PETSc			\
		libscotch.so:cad/scotch				\
		libslepc.so:math/slepc				\
		${PY_BOOST}
RUN_DEPENDS=	gmsh:cad/gmsh		\
		xmgrace:math/grace
BUILD_RUN_DEPENDS=	bash:shells/bash	\
		codeaster-frontend>0:science/codeaster-frontend		\
		miss3d>0:science/miss3d		\
		rsync:net/rsync			\
		sbatch:sysutils/slurm-wlm	\
		valgrind:devel/valgrind		\
		xterm:x11/xterm			\
		${PYTHON_PKGNAMEPREFIX}ipython>=0:devel/ipython@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}matplotlib>=0:math/py-matplotlib@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}pandas>=0:math/py-pandas@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}petsc4py>0:math/py-petsc4py@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}pyyaml>0:devel/py-pyyaml@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}slepc4py>0:math/py-slepc4py@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}sympy>0:math/py-sympy@${PY_FLAVOR}

USES=		bison blaslapack:openblas fortran gmake gettext gettext-tools	\
		localbase python qt:5 shebangfix
SHEBANG_FILES=	.devhelper/check_requirements.sh .devhelper/check_updates.sh	\
		astest/asrun01b.88 check_ci.sh check_docs.sh configure		\
		data/create_install_script data/create_install_script		\
		data/ddt_wrapper.tmpl data/execute_codeaster.tmpl		\
		data/gdb_wrapper data/post_build_win.sh data/post_install	\
		data/run_aster_extract data/run_aster_for_ctest data/run_aster	\
		data/run_ctest data/run_sbatch waf.engine waf_variant waf.main
USE_BINUTILS=	yes
USE_QT=		linguisttools:build

CFLAGS+=	-I${LOCALBASE}/include/hdf5-110
FCFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-lkvm -lexecinfo -lz

HAS_CONFIGURE=	yes
CONFIGURE_SHELL=bash
# Parmetis is not packageable
CONFIGURE_ARGS=	--disable-parmetis	\
		--prefix=${PREFIX}	\
		--hdf5-libs=hdf5-110	\
		--enable-mumps		\
		--without-repo		\
		--enable-i18n
#CONFIGURE_ARGS+=	--verbose
CONFIGURE_ENV=	LINKFLAGS=-pthread
MAKE_ENV=	LINKFLAGS=-pthread	\
		ASTER_CONFIG=${OPSYS:tl}-${ARCH}
MAKE_ARGS=	OPTS="--destdir=${STAGEDIR}"

OPTIONS_RADIO=		BUILD
OPTIONS_RADIO_BUILD=	DEBUG PARA STD
OPTIONS_DEFAULT=	PARA
OPTIONS_SUB=		yes
PARA_DESC=		Parallel build with MPI
STD_DESC=		Standard build

DEBUG_LIB_DEPENDS=	libHYPRE.so:science/hypre	\
			libcblas.so:math/cblas		\
		        libcmumps.so.5:math/mumps	\
			libscalapack.so:math/scalapack	\
			libsuperlu.so:math/superlu
DEBUG_RUN_DEPENDS=	${MPI4PY}
DEBUG_USES=		mpi
DEBUG_CFLAGS=		-I${MPI_HOME}/include -I${LOCALBASE}/include/superlu
DEBUG_LDFLAGS=		-L${MPI_HOME}/lib
DEBUG_VARS=		CC=${MPICC} CXX=${MPICXX}	\
			HOME_MPI=${MPI_HOME}	\
			CONFIGURE_CMD="FC=${MPIFC} ./${CONFIGURE_SCRIPT}"	\
			CONFIGURE_LOG=build/mpiebug/config.log	\
			ASTER_BUILD=debug	\
			WITH_DEBUG=yes
DEBUG_CONFIGURE_ENV=	ASTER_BUILD=debug	\
			FC=${MPIFC}	\
			PATH="${MPI_HOME}/bin:${PATH}"
DEBUG_MAKE_ENV=		ASTER_BUILD=debug	\
			PATH="${MPI_HOME}/bin:${PATH}"

PARA_LIB_DEPENDS=	libHYPRE.so:science/hypre	\
			libcblas.so:math/cblas		\
		        libcmumps.so.5:math/mumps	\
			libscalapack.so:math/scalapack	\
			libsuperlu.so:math/superlu
PARA_RUN_DEPENDS=	${MPI4PY}
PARA_USES=		mpi
PARA_CFLAGS=		-I${MPI_HOME}/include -I${LOCALBASE}/include/superlu
PARA_LDFLAGS=		-L${MPI_HOME}/lib
PARA_VARS=		CC=${MPICC} CXX=${MPICXX}	\
			HOME_MPI=${MPI_HOME}	\
			CONFIGURE_CMD="FC=${MPIFC} ./${CONFIGURE_SCRIPT}"	\
			CONFIGURE_LOG=build/mpi/config.log	\
			ASTER_BUILD=mpi
PARA_CONFIGURE_ENV=	ASTER_BUILD=mpi	\
			FC=${MPIFC}	\
			PATH="${MPI_HOME}/bin:${PATH}"
PARA_MAKE_ENV=		ASTER_BUILD=mpi	\
			PATH="${MPI_HOME}/bin:${PATH}"

STD_LIB_DEPENDS=	libmpiseq.so.5:math/mumps
STD_CONFIGURE_ENV=	ASTER_BUILD=std
STD_CONFIGURE_LOG=	build/std/config.log
STD_MAKE_ENV=		ASTER_BUILD=std
STD_VARS=		ASTER_BUILD=std

BINARY_ALIAS=	bash=${LOCALBASE}/bin/bash	\
		getopt=${LOCALBASE}/bin/getopt	\
		git=true			\
		lrelease=${LRELEASE}		\
		make=${GMAKE}			\
		pylupdate4=${LOCALBASE}/bin/pylupdate5 \
		python3=${PYTHON_CMD}		\
		python=${PYTHON_CMD}		\
		sed=${LOCALBASE}/bin/gsed

VER=		${PORTVERSION:R}
VE=		${VER:R}
WRKSRC=		${WRKDIR}/src-${PORTVERSION}

MAKEFILE=	makefile
ALL_TARGET=	build
TEST_TARGET=	test
#TEST_ARGS?=	adlv100a	# MPI needed
TEST_ARGS?=	asrun01a	# Mode STD with MUMPS needed
ASTER_LIBDIR=	${PREFIX}/lib/aster

SUB_FILES=	pkg-message
SUB_LIST=	tools_dir=${tools_dir}

.include "${.CURDIR}/../../french/aster/bsd.aster.mk"
.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MPARA} && exists(${LOCALBASE}/bin/h5dump-110) && !exists(${LOCALBASE}/bin/h5pcc-110)
BROKEN=	to enable MPI hdf5-110 must be built with parallel enabled
.elif ${PORT_OPTIONS:MSTD} && exists(${LOCALBASE}/include/mumps_seq/mpi.h)
BROKEN=	to enable MPI MUMPS must be built with MPI
.else
.  if ${PORT_OPTIONS:MPARA} && exists(${LOCALBASE}/include/med.h)
MED_HAVE_MPI!=	${GREP} -o MED_HAVE_MPI ${LOCALBASE}/include/med.h
.    if ${MED_HAVE_MPI} != "MED_HAVE_MPI"
BROKEN=	to enable MPI MED must be recompiled against a parallel hdf5-110
.    endif
.  endif
.endif
.if ${PORT_OPTIONS:MSTD} && exists(${LOCALBASE}/include/med.h) && !exists(${LOCALBASE}/include/mumps_seq/mpi.h)
BROKEN=	in sequential mode MUMPS must be built without MPI
.endif

.if ${ARCH} == "i386"
FLAGARCH=	-DP_LINUX -DLINUX
.else
FLAGARCH=	-DLINUX64
.endif

BASH2FIX=	makefile run_aster/run.py

ExportPATH?=	/tmp/maillages

pre-configure:
	${LN} -sf ${LOCALBASE}/aster/dev/codeaster/devtools ${WRKDIR}
	${REINPLACE_CMD} -e 's|%%opsys-arch%%|${OPSYS:tl}-${ARCH}|'	\
		${WRKSRC}/waf.main
.for f in ${BASH2FIX}
	${REINPLACE_CMD} -e 's|/bin/bash|${LOCALBASE}/bin/bash|'	\
		${WRKSRC}/${f}
.endfor

post-configure:
	${ECHO_CMD} 'ASTER_BUILD=${ASTER_BUILD}' > ${WRKSRC}/env.d/${OPSYS:tl}-${ARCH}.sh
	${ECHO_CMD} 'MAKE=${GMAKE}' >> ${WRKSRC}/env.d/${OPSYS:tl}-${ARCH}.sh
	${ECHO_CMD} 'PYTHON=${PYTHON_CMD}' >> ${WRKSRC}/env.d/${OPSYS:tl}-${ARCH}.sh
	# The validation repository is not available
	${REINPLACE_CMD} -e 's|src/astest|src-${PORTVERSION}/astest|'	\
		-e 's|export ].*|export ]; then \\|' ${WRKSRC}/makefile

do-install:
	(cd ${INSTALL_WRKSRC} &&	\
	${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${FAKEROOT}	\
		ASTER_LIBDIR=${STAGEDIR}${ASTER_LIBDIR}	\
		LD_LIBRARY_PATH=${STAGEDIR}${ASTER_LIBDIR}	\
		PYTHONPATH=${PYTHON_SITELIBDIR}:${STAGEDIR}${ASTER_LIBDIR}	\
		./waf_${ASTER_BUILD} install --destdir=${STAGEDIR})

post-install:
	${FIND} ${STAGEDIR}${PREFIX}/lib/${PORTNAME} -name "*.pyc" -delete
	${PYTHON_CMD} -m compileall -d ${PREFIX}/lib/${PORTNAME} \
		${STAGEDIR}${PREFIX}/lib/${PORTNAME}
	${PYTHON_CMD} -O -m compileall -d ${PREFIX}/lib/${PORTNAME} \
		${STAGEDIR}${PREFIX}/lib/${PORTNAME}
	${RM} -rf  ${STAGEDIR}${PREFIX}/tests ${STAGEDIR}${DATADIR}/tests
	(cd ${WRKSRC} && ${COPYTREE_SHARE} astest ${STAGEDIR}${DATADIR})
	(cd ${STAGEDIR}${DATADIR} &&	\
		${LN} -sf astest ${STAGEDIR}${DATADIR}/tests)

.if defined(MAINTAINER_MODE)
regression-test:	install
	@${ECHO_MSG} "Note: homard must be installed to run some steps succesfully."
	${MKDIR} ${ExportPATH}
	${CP} ${inst_dir}/${VE}/astout.export /tmp/
	(cd ${inst_dir}/${VE} &&	\
	${LOCALBASE}/aster/bin/as_run --list --all --vers=${VE}	\
		--filter='"I" not in testlist' -o /tmp/list_seq )
	(cd /tmp &&	\
	${LOCALBASE}/aster/bin/as_run astout.export) || ${TRUE}
	@${ECHO_MSG} "Check /tmp/resu_test/NOOK"
.endif

.include <bsd.port.post.mk>
