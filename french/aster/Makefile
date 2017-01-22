# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	aster
DISTVERSION=	${ASTER_DISTVERSION}
PORTREVISION=	2
CATEGORIES=	french cad
CATEGORIES=	french cad

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Code_Aster finite element method solver

LICENSE=	GPLv2

#-----------------------------------------------------------------------
# You may define these options:
#
# - WITH_ZSH or WITH_BASH or WITH_KSH: select a shell among
#			zsh (default), bash or ksh;
# - WITH_ED: select an editor accepting '-display' (e.g. gvim, nedit);
# - WITH_ATLAS: replace blas;
# - WITH_BLAS: don't link with atlas, even if present, but with blas;
#			(blas might be slower, but is lighter)
# - WITHOUT_ASTK_CLI: won't use the GUI from this machine;
# - WITHOUT_EFICAS: don't install ASter Command FIle Editor;
# - WITHOUT_GMSH: don't install GMSH (a mesh generator);
# - WITHOUT_GRACE: don't install Grace (used to create 2D graph);
# - WITHOUT_MACR_RECAL: don't install Numerical Python
#			(required by the macro MACR_RECAL);
# - WITHOUT_SCOTCH: don't install Scotch.
# - WITH_MUMPS: install the interface between Code_Aster and MUMPS (experimental)
#
#-----------------------------------------------------------------------

BUILD_DEPENDS+=	astk-serveur>0:cad/astk-serveur	\
		${SHELL_INSTALL_ASTER}:shells/${SHIADEP}	\
		${LOCALBASE}/lib/libscotch.a:cad/scotch		\
		python:lang/python				\
		${PYNUMPY}
LIB_DEPENDS+=	libhdf5-18.so:science/hdf5-18			\
		libmed.so:french/med				\
		libmetis.so.0:math/metis-edf			\
		libAsterInterface.so:science/tfel
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}gnuplot>0:math/py-gnuplot\
		${LOCALBASE}/bin/onmetis:math/metis-edf		\
		${SHELL_INSTALL_ASTER}:shells/${SHIADEP}	\
		astk-serveur>0:cad/astk-serveur

BROKEN_FreeBSD_12=	does not build (sed: ${STAGEDIR}${inst_dir}/${VE}/aster.conf: No such file or directory)

USES=		bison fortran gettext python:2 tk
USE_BINUTILS=	yes

.if defined(WITH_ATLAS)
USES+=		blaslapack:atlas
.else
USES+=		blaslapack:netlib
.endif

HAS_CONFIGURE=	yes
MAKE_ENV=	INCLUDES="${LOCALBASE}/include/hdf5-18 ${LOCALBASE}/include ${LOCALBASE}/include/metis"
REINPLACE_ARGS=	-i ""

VER=		${PORTVERSION:R}
VE=		${VER:R}
WRKSRC=		${WRKDIR}/${PORTNAME}-full-src-${VER}

PLIST_SUB=	VE=${VE}
.if defined(WITHOUT_ASTK_CLI)
SUB_FILES=	pkg-message.sans-astk
.else
SUB_FILES=	pkg-message
.endif
SUB_LIST=	tools_dir=${tools_dir}

INTERACTIVE_SCRIPTS=	check_compilers.py setup.py

.include "${.CURDIR}/../../french/aster/bsd.aster.mk"
.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
FLAGARCH=	-DP_LINUX -DLINUX
.else
FLAGARCH=	-DLINUX64
.endif

.if !defined(WITHOUT_ASTK_CLI)
RUN_DEPENDS+=	astk-client>0:cad/astk-client
PLIST_SUB+=	ASTK_CLIENT=""  ASTKDIR=${ASTKDIR}
.else
PLIST_SUB+=	ASTK_CLIENT="@comment " ASTKDIR=""
.endif
.if !defined(WITHOUT_EFICAS)
RUN_DEPENDS+=	fr-eficas>0:french/eficas
PLIST_SUB+=	EFICAS=""
.else
PLIST_SUB+=	EFICAS="@comment "
.endif
.if !defined(WITHOUT_GMSH)
RUN_DEPENDS+=	${LOCALBASE}/bin/gmsh:cad/gmsh
PLIST_SUB+=	GMSH=""
.else
PLIST_SUB+=	GMSH="@comment "
.endif
.if !defined(WITHOUT_GRACE)
RUN_DEPENDS+=	xmgrace:math/grace
PLIST_SUB+=	GRACE=""
.else
PLIST_SUB+=	GRACE="@comment "
.endif
.if !defined(WITHOUT_MACR_RECAL)
RUN_DEPENDS+=	${PYNUMPY}
.endif

.if !defined(WITH_MPI)
MUMPS_PORT=	mumps
.else
BUILD_DEPENDS+=	${LOCALBASE}/lib/libblacs.a:math/blacs	\
		${LOCALBASE}/lib/libscalapack.a:math/scalapack
MUMPS_PORT=	mumps-mpich
MUMPSLIB=	-L${LOCALBASE}/lib -ldmumps -lzmumps -lmumps_common -lpord -lscalapack -lblacs -lblacsc -lblacs -L${LOCALBASE}/lib -lmpich -lmpl
.endif
BUILD_DEPENDS+=	${LOCALBASE}/lib/libcmumps.a:math/${MUMPS_PORT}

.if defined(WITH_MPI)
LIB_DEPENDS+=	libmpich.so:net/mpich2
HOME_MPI=	${LOCALBASE}
.endif

.if defined(WITH_ZSH)
SHIA=		zsh
.elif defined(WITH_BASH)
SHIA=		bash
.elif defined(WITH_KSH)
SHIA=		ksh93
.elif exists(${LOCALBASE}/bin/zsh)
SHIA=		zsh
.elif exists(${LOCALBASE}/bin/bash)
SHIA=		bash
.elif exists(${LOCALBASE}/bin/ksh93)
SHIA=		ksh93
.else
SHIA=		zsh
.endif
SHIADEP=	${SHIA}

.if !defined(WITH_ED)
. if exists(${LOCALBASE}/bin/nedit)
WITH_ED=	nedit
RUN_DEPENDS+=	${LOCALBASE}/bin/nedit:editors/nedit
. elif exists(${LOCALBASE}/bin/gvim)
WITH_ED=	gvim
RUN_DEPENDS+=	${LOCALBASE}/bin/gvim:editors/vim
. elif exists(${LOCALBASE}/bin/emacs)
WITH_ED=	emacs
RUN_DEPENDS+=	${LOCALBASE}/bin/emacs:editors/emacs
. elif exists(${LOCALBASE}/bin/gedit)
WITH_ED=	gedit
RUN_DEPENDS+=	${LOCALBASE}/bin/gedit:editors/gedit
. elif exists(${LOCALBASE}/bin/xedit)
WITH_ED=	xedit
RUN_DEPENDS+=	${LOCALBASE}/bin/xedit:x11/xedit
. else
WITH_ED=	vi
. endif
.endif

INST_DAT=	elements
INST_SH=	as_run parallel_cp
PFX2FIX=	bin/as_run ${VE}/include/aster/asterc_config.h			\
		${VE}/include/aster/asterf_config.h ${VE}/share/aster/profile.sh\
		etc/codeaster/profile.sh etc/codeaster/aster			\
		${VE}/lib/aster/aster_pkginfo.py ${VE}/aster.conf		\
		${VE}/share/aster/CTestTestfile.cmake ${VE}/share/aster/config.txt
inst_dir=	${PREFIX}/${PORTNAME}
tools_dir=	${PREFIX}/${PORTNAME}/outils
tools=		kmetis onmetis pmetis gnuplot
.if !defined(WITHOUT_EFICAS)
tools+=		eficas eficasQt
.endif
.if !defined(WITHOUT_GMSH)
tools+=		gmsh
.endif
.if !defined(WITHOUT_GRACE)
tools+=		gracebat xmgrace
.endif
v_ifdef=	${OPSYS:tu}
SHELL_INSTALL_ASTER=	${LOCALBASE}/bin/${SHIA}
tcl_dir=	${LOCALBASE}
hdf_dir=	${LOCALBASE}
lib_math=	"-L${LOCALBASE}/lib ${BLASLIB} ${LAPACKLIB} ${ATLASLIB}"

LASTKDIR?=	${PORTNAME}/ASTK/ASTK_CLIENT
ASTKDIR=	${LOCALBASE}/${LASTKDIR}

BASH2RC=	products_data.py

pre-everything::
.if defined(WITH_MPI)
	@${ECHO_MSG} "To build Code_Aster with MPI enabled, you need to run \`mpd &'"
.endif

pre-configure:
	${REINPLACE_CMD} -e 's|PREFER_SHARED_LIBS=False|PREFER_SHARED_LIBS=True|'	\
		${WRKSRC}/setup.cfg
	${REINPLACE_CMD} -e 's|/opt/aster|${STAGEDIR}${inst_dir}|'	\
		${WRKSRC}/setup.cfg
	${REINPLACE_CMD} -e 's|?ASTER_ROOT?|${STAGEDIR}${inst_dir}|'	\
		${WRKSRC}/products.py
	${REINPLACE_CMD} -e "s|'gfortran'|'${FC}'|g;s|'gcc'|'${CC}'|g"	\
		-e "s|'g++'|'${CXX}'|g" ${WRKSRC}/check_compilers.py
	${REINPLACE_CMD} -e 's|%%FILESDIR%%|${FILESDIR}|' ${WRKSRC}/as_setup.py
.for sh in ${BASH2RC}
	${REINPLACE_CMD} -e 's|/bin/bash|${SHELL_INSTALL_ASTER}|' ${WRKSRC}/${sh}
.endfor
.if defined(WITH_ATLAS)
	${REINPLACE_CMD} -e "s|cfg\['BLASLIB'\]|cfg['BLASLIB'], cfg['ATLASLIB']|"	\
		${WRKSRC}/products.py
.endif
	${ECHO_CMD} "_install_hdf5 = False"			>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "_install_med = False"			>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "_install_tcl = False"			>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "_install_tk  = False"			>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "_install_Pmw = False"			>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "_install_Numeric = False"			>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "_install_gmsh = False"			>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "_install_gmsh2 = False"			>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "_install_gibi = False"			>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "_install_grace = False"			>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "XMGRACE = 'xmgrace'"			>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "_install_homard = False"			>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "_install_eficas = False"			>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "_install_astk = False"			>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "_install_astk_serv = False"		>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "_install_metis = False"			>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "_install_mumps = False"			>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "_install_omniORB = False"			>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "_install_omniORBpy = False"		>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "_install_pylotage = False"			>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "_install_crpcrs = False"			>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "_install_aster_Linux = False"		>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "_install_scotch  = False"			>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "OPT_ENV = 'verbose=True'"			>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "HOME_SCOTCH = '${LOCALBASE}'"		>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "HOME_METIS = '${LOCALBASE}'"		>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "INCLUDEDIR = ['${LOCALBASE}/include/hdf5-18', '${LOCALBASE}/include', '${LOCALBASE}/include/metis', ]"\
			>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "HOME_MUMPS = '${LOCALBASE}'"		>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "HOME_MFRONT = '${LOCALBASE}'"		>> ${WRKSRC}/setup.cfg
.if ${MUMPS_PORT} == "mumps-mpich"
	${ECHO_CMD} "MUMPSLIB = '${MUMPSLIB}'"			>> ${WRKSRC}/setup.cfg
.endif
	${ECHO_CMD} "CC='${CC}'"				>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "gcc='${CC}'"				>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "CXX='${CXX}'"				>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "LD='${FC}'"				>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "F90='${FC}'"				>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "MATHLIB='${lib_math} ${LDFLAGS} -lgfortran -lm -lkvm'"		\
		>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "OTHERLIB='-Xlinker -export-dynamic -lutil -lpthread -lz'"	\
		>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "SYSLIB='-lpthread -lz'"			>> ${WRKSRC}/setup.cfg
.if defined(WITH_MPI)
	${ECHO_CMD} "HOME_MPI = '${HOME_MPI}'"			>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "MPIRUN = 'mpirun'"				>> ${WRKSRC}/setup.cfg
.else
	${ECHO_CMD} "HOME_MPI = ''"				>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "MPIRUN = ''"				>> ${WRKSRC}/setup.cfg
.endif
	${ECHO_CMD} "HOME_ZMAT = ''"				>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "HOME_HDF='${hdf_dir}'"			>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "HOME_MED='${LOCALBASE}'"			>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "HOME_TCL_TK='${tcl_dir}'"			>> ${WRKSRC}/setup.cfg
.if defined(WITH_ATLAS)
	${ECHO_CMD} "ATLASLIB='${_ATLASLIB}'"			>> ${WRKSRC}/setup.cfg
.endif
	${ECHO_CMD} "BLASLIB='${_BLASLIB}'"			>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "LAPACKLIB='lapack'"			>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "GZIP='/usr/bin/gzip'"			>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "SHELL_EXECUTION='${SHELL_INSTALL_ASTER}'"	>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "TERMINAL='xterm'"				>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "EDITOR='${WITH_ED}'"			>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "LDFLAGS='${LDFLAGS}'"			>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "FFLAGS='-c ${FFLAGS} -fno-tree-dse ${FLAGARCH}'"	\
		>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "FFLAGS_DBG='-c -g ${FFLAGS:C|O2|O0|} -fno-tree-dse ${FLAGARCH}'"	\
		>> ${WRKSRC}/setup.cfg
.if defined(WITH_MPI)
	${ECHO_CMD} "F90FLAGS='-c ${FFLAGS} -fno-tree-dse ${FLAGARCH} -I${HOME_MPI}/include'"	\
		>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "F90FLAGS_DBG='-c -g ${FFLAGS:C|O2|O0|} -fno-tree-dse ${FLAGARCH} -I${HOME_MPI}/include'"	\
		>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "CFLAGS='-c ${CFLAGS} ${FLAGARCH} -I${HOME_MPI}/include'"	\
		>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "CFLAGS_DBG='-c -g -O -pipe ${FLAGARCH} -I${HOME_MPI}/include'"	\
		>> ${WRKSRC}/setup.cfg
.else
	${ECHO_CMD} "F90FLAGS='-c ${FFLAGS} -fno-tree-dse ${FLAGARCH}'"	\
		>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "F90FLAGS_DBG='-c -g ${FFLAGS:C|O2|O0|} -fno-tree-dse ${FLAGARCH}'"	\
		>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "CFLAGS='-c ${CFLAGS} ${FLAGARCH}'"	\
		>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "CFLAGS_DBG='-c -g -O -pipe ${FLAGARCH}'"	\
		>> ${WRKSRC}/setup.cfg
.endif
.for is in ${INTERACTIVE_SCRIPTS}
	${REINPLACE_CMD} -e '/should_continue()/d'		\
		${WRKSRC}/${is}
.endfor
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}

do-configure:
	(cd ${CONFIGURE_WRKSRC}	\
	&& TMPDIR=${WRKDIR} ${PYTHON_CMD} setup.pyo ${DEBUG_FLAGS}	\
		--prefix=${STAGEDIR}${inst_dir} test | tee ${CONFIGURE_LOG})
	@${ECHO_MSG} "---------------- Debug ------------------"
	${CAT} ${CONFIGURE_WRKSRC}/setup.log
	@${ECHO_MSG} "------------ Fin debug ------------------"

post-configure:
	${MKDIR} ${STAGEDIR}${inst_dir}/etc
	${CP} -R ${LOCALBASE}/aster/etc/codeaster ${STAGEDIR}${inst_dir}/etc/
	${ECHO_CMD} "#?vers : VVV?" >> ${STAGEDIR}${inst_dir}/etc/codeaster/aster
	${CP} -R ${LOCALBASE}/aster/ASTK/ASTK_SERV/bin		\
		${LOCALBASE}/aster/ASTK/ASTK_SERV/asrun		\
		${LOCALBASE}/aster/ASTK/ASTK_SERV/share		\
		${STAGEDIR}${inst_dir}
	${REINPLACE_CMD} -e 's|${LOCALBASE}/aster|${STAGEDIR}${inst_dir}|'	\
		${STAGEDIR}${inst_dir}/bin/as_run
	${MV} ${STAGEDIR}${inst_dir}/etc/codeaster/profile_astk.sh	\
		${STAGEDIR}${inst_dir}/etc/codeaster/profile.sh
.for sf in etc/codeaster/profile.sh asrun/installation.py
	${REINPLACE_CMD} -e 's|${LOCALBASE}/aster/ASTK/ASTK_SERV|${STAGEDIR}${inst_dir}|g'	\
		-e 's|${LOCALBASE}/aster|${STAGEDIR}${inst_dir}|g'	\
		${STAGEDIR}${inst_dir}/${sf}
.endfor

do-build:
	(cd ${BUILD_WRKSRC} &&	\
	TMPDIR=${WRKDIR} ${MAKE_ENV} ${PYTHON_CMD} setup.pyo ${DEBUG_FLAGS} install aster	\
		--prefix=${STAGEDIR}${inst_dir} | tee ${BUILD_WRKSRC}/build.log)

do-install:
	# build: already did the installation
	@${DO_NADA}

post-install:
.for f in ${PFX2FIX}
	${REINPLACE_CMD} -e 's|${STAGEDIR}||g' ${STAGEDIR}${inst_dir}/${f}
.endfor
	(cd ${STAGEDIR}${PREFIX} && ${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py	\
		-d ${PREFIX} -f ${inst_dir:S|${PREFIX}/||})
	(cd ${STAGEDIR}${PREFIX} && ${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py	\
		-d ${PREFIX} -f ${inst_dir:S|${PREFIX}/||})
	${CP} -p ${STAGEDIR}${inst_dir}/${VE}/bin/aster					\
		${STAGEDIR}${inst_dir}/${VE}/bin/asterd
	${STRIP_CMD} ${STAGEDIR}${inst_dir}/${VE}/bin/aster
	${SED} -e 's|%%VER%%|${VE}|' < ${FILESDIR}/astout.export	\
		> ${STAGEDIR}${inst_dir}/${VE}/astout.export
	(cd ${STAGEDIR}${inst_dir} &&	\
		${LN} -fs ${VE} ${STAGEDIR}${inst_dir}/STA${VE})
.for conf in config.txt profile.sh
	(cd ${STAGEDIR} && ${LN} -fs ${inst_dir}/${VE}/share/aster/${conf}	\
		${STAGEDIR}${inst_dir}/STA${VE}/${conf})
.endfor
.for outil in ${tools}
	${LN} -fs ${LOCALBASE}/bin/${outil} ${STAGEDIR}${tools_dir}/${outil}
.endfor
.if !defined(WITHOUT_ASTK_CLI)
	${MKDIR} ${STAGEDIR}${PREFIX}/aster/ASTK/ASTK_SERV/etc/codeaster/astkrc
	${LN} -fs ${ASTKDIR}/etc/astkrc/*	\
		${STAGEDIR}${PREFIX}/aster/ASTK/ASTK_SERV/etc/codeaster/astkrc
. for outil in astk bsf
	${LN} -fs ${ASTKDIR}/bin/${outil} ${STAGEDIR}${tools_dir}/${outil}
. endfor
.endif
	${MKDIR} ${WRKDIR}/AvoidConflictWithASTK
.for f in aster.install_${VE} profile.sh
	${MV} ${STAGEDIR}${inst_dir}/etc/codeaster/${f} ${WRKDIR}/AvoidConflictWithASTK/
.endfor
	${RM} -r ${STAGEDIR}${inst_dir}/etc/codeaster/*
.for f in aster.install_${VE} profile.sh
	${MV} ${WRKDIR}/AvoidConflictWithASTK/${f} ${STAGEDIR}${inst_dir}/etc/codeaster/
.endfor

.if defined(MAINTAINER_MODE)
regression-test:	install
	@${ECHO_MSG} "Note: homard must be installed to run some steps succesfully."
	${CP} ${inst_dir}/${VE}/astout.export /tmp/
	(cd ${inst_dir}/${VE} &&	\
	${LOCALBASE}/aster/ASTK/ASTK_SERV/bin/as_run --list --all --vers=${VE}	\
		--filter='"I" not in testlist' -o /tmp/list_seq )
	(cd /tmp &&	\
	${LOCALBASE}/aster/ASTK/ASTK_SERV/bin/as_run astout.export) || ${TRUE}
	@${ECHO_MSG} "Check /tmp/resu_test/NOOK"
.endif

.include <bsd.port.post.mk>
