# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=		aster
DISTVERSION=		${ASTER_DISTVERSION}
PORTREVISION=	2
CATEGORIES=		french cad

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Code_Aster finite element method solver

#-----------------------------------------------------------------------
NO_STAGE=	yes
# You may define these options:
#
# - FFLAGS: fortan compiler's flags (-O2 by default);
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

BUILD_DEPENDS+=	${LOCALBASE}/aster/ASTK/ASTK_SERV:${PORTSDIR}/cad/astk-serveur	\
		${SHELL_INSTALL_ASTER}:${PORTSDIR}/shells/${SHIADEP}		\
		${PYNUMPY}
LIB_DEPENDS+=	hdf5.7:${PORTSDIR}/science/hdf5-18				\
		med.5:${PORTSDIR}/french/med
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/Gnuplot:${PORTSDIR}/math/py-gnuplot	\
		${LOCALBASE}/bin/onmetis.exe:${PORTSDIR}/math/metis-edf		\
		${SHELL_INSTALL_ASTER}:${PORTSDIR}/shells/${SHIADEP}		\
		${LOCALBASE}/aster/ASTK/ASTK_SERV:${PORTSDIR}/cad/astk-serveur

LICENSE=	GPLv2

USES=		bison fortran tk
USE_PYTHON=	2	# >2.5 and <3.0
HAS_CONFIGURE=	yes
REINPLACE_ARGS=	-i ""

WRKSRC=		${WRKDIR}/${PORTNAME}-full-src-${PORTVERSION:R}
PLIST_SUB=	ASTERDIR=${PORTNAME}/${vaster} TOOLDIR=${PORTNAME}/outils
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
FFLAGARCH=
.else
FLAGARCH=	-DLINUX64
FFLAGARCH=	-fdefault-integer-8 -fdefault-real-8
.endif

.if ${ARCH} == "amd64"
# python 2.7 causes process runaway
PYTHON_VERSION=	2.6
.endif
# Avoid renaming .f into .F
#F90FLAGS=	-x f77-cpp-input ${FFLAGS}

.if exists(${LOCALBASE}/lib/libatlas.so) && !defined(WITH_BLAS)
WITH_ATLAS=	yes
.endif
.if defined(WITH_ATLAS)
LIB_DEPENDS+=	atlas.2:${PORTSDIR}/math/atlas
.else
LIB_DEPENDS+=	blas.2:${PORTSDIR}/math/blas
LIB_DEPENDS+=	lapack.4:${PORTSDIR}/math/lapack
.endif

.if !defined(WITHOUT_ASTK_CLI)
RUN_DEPENDS+=	${ASTKDIR}:${PORTSDIR}/cad/astk-client
PLIST_SUB+=	ASTK_CLIENT=""  ASTKDIR=${ASTKDIR}
.else
PLIST_SUB+=	ASTK_CLIENT="@comment " ASTKDIR=""
.endif
.if !defined(WITHOUT_EFICAS)
RUN_DEPENDS+=	${LOCALBASE}/apps/eficas:${PORTSDIR}/french/eficas
PLIST_SUB+=	EFICAS=""
.else
PLIST_SUB+=	EFICAS="@comment "
.endif
.if !defined(WITHOUT_GMSH)
RUN_DEPENDS+=	${LOCALBASE}/bin/gmsh:${PORTSDIR}/cad/gmsh
PLIST_SUB+=	GMSH=""
.else
PLIST_SUB+=	GMSH="@comment "
.endif
.if !defined(WITHOUT_GRACE)
RUN_DEPENDS+=	xmgrace:${PORTSDIR}/math/grace
PLIST_SUB+=	GRACE=""
.else
PLIST_SUB+=	GRACE="@comment "
.endif
.if !defined(WITHOUT_MACR_RECAL)
RUN_DEPENDS+=	${PYNUMPY}
.endif
.if !defined(WITHOUT_SCOTCH)
BUILD_DEPENDS+=	${LOCALBASE}/lib/libscotch.a:${PORTSDIR}/cad/scotch
.endif

.if exists(${LOCALBASE}/lib/libcmumps.a)
WITH_MUMPS=	yes
.endif
.if defined(WITH_MUMPS)
WITH_MPI=	yes	# For the FETI solver
. if exists(${LOCALBASE}/lib/libmpiseq.a)
MUMPS_PORT=	mumps
. else
BUILD_DEPENDS+=	${LOCALBASE}/lib/libblacs.a:${PORTSDIR}/math/blacs	\
		${LOCALBASE}/lib/libscalapack.a:${PORTSDIR}/math/scalapack
MUMPS_PORT=	mumps-mpich
MUMPSLIB=	-L${LOCALBASE}/lib -ldmumps -lzmumps -lmumps_common -lpord -lscalapack -lblacs -lblacsc -lblacs -L${LOCALBASE}/lib -lmpich -lmpl
. endif
BUILD_DEPENDS+=	${LOCALBASE}/lib/libcmumps.a:${PORTSDIR}/math/${MUMPS_PORT}
.endif

.if defined(WITH_MPI)
LIB_DEPENDS+=	mpich.2:${PORTSDIR}/net/mpich2
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
RUN_DEPENDS+=	${LOCALBASE}/bin/nedit:${PORTSDIR}/editors/nedit
. elif exists(${LOCALBASE}/bin/gvim)
WITH_ED=	gvim
RUN_DEPENDS+=	${LOCALBASE}/bin/gvim:${PORTSDIR}/editors/vim
. elif exists(${LOCALBASE}/bin/emacs)
WITH_ED=	emacs
RUN_DEPENDS+=	${LOCALBASE}/bin/emacs:${PORTSDIR}/editors/emacs
. elif exists(${LOCALBASE}/bin/xemacs)
WITH_ED=	xemacs
RUN_DEPENDS+=	${LOCALBASE}/bin/xemacs:${PORTSDIR}/editors/xemacs
. elif exists(${LOCALBASE}/bin/gedit)
WITH_ED=	gedit
RUN_DEPENDS+=	${LOCALBASE}/bin/gedit:${PORTSDIR}/editors/gedit
. elif exists(${LOCALBASE}/bin/xedit)
WITH_ED=	xedit
RUN_DEPENDS+=	${LOCALBASE}/bin/xedit:${PORTSDIR}/x11/xedit
. else
WITH_ED=	vi
. endif
.endif

vaster=		STA${PORTVERSION:R:R}
INST_DAT=	LICENSE.TERMS astest cata_ele.pickled catalo catapy	\
		elements materiau
INST_PY=	bibpyt commande
INST_SH=	as_run parallel_cp
DAT2FIX=	astout.export config.txt forma01a.export
inst_dir=	${PREFIX}/${PORTNAME}/${vaster}
tools_dir=	${PREFIX}/${PORTNAME}/outils
v_ifdef=	${OPSYS:U}
SHELL_INSTALL_ASTER=	${LOCALBASE}/bin/${SHIA}
tcl_dir=	${LOCALBASE}
hdf_dir=	${LOCALBASE}
.if defined(WITH_ATLAS)
lib_blas=	ptf77blas
lib_atlas=	atlas
.else
lib_blas=	blas
lib_atlas=	# empty
.endif

LASTKDIR?=	${PORTNAME}/ASTK/ASTK_CLIENT
ASTKDIR=	${LOCALBASE}/${LASTKDIR}

BASH2RC=	products_data.py

${WRKSRC}/instdir/${vaster}/elements:	build

pre-everything::
.if defined(WITH_MPI)
	@${ECHO_MSG} "To build Code_Aster with MPI enabled, you need to run \`mpd &'"
.endif

pre-configure:
	${REINPLACE_CMD} -e 's|PREFER_SHARED_LIBS=False|PREFER_SHARED_LIBS=True|' ${WRKSRC}/setup.cfg
	${REINPLACE_CMD} -e 's|/opt/aster|${WRKSRC}/instdir|'		\
		${WRKSRC}/setup.cfg
	${REINPLACE_CMD} -e 's|?ASTER_ROOT?|${WRKSRC}/instdir|'		\
		${WRKSRC}/products.py
	${REINPLACE_CMD} -e "s|'gfortran'|'${FC}'|g" ${WRKSRC}/check_compilers.py
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
.if defined(WITH_MUMPS)
	${ECHO_CMD} "HOME_MUMPS = '${LOCALBASE}'"		>> ${WRKSRC}/setup.cfg
. if ${MUMPS_PORT} == "mumps-mpich"
	# else libmpiseq.a used instead of libmpich, default is OK
	${ECHO_CMD} "MUMPSLIB = '${MUMPSLIB}'"			>> ${WRKSRC}/setup.cfg
. endif
.endif
	${ECHO_CMD} "CC='${CC}'"				>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "CXX='${CXX}'"				>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "CXXLIB = '${LDFLAGS} -lstdc++ -lsupc++'"	\
		>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "LD='${FC}'"				>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "F90='${LOCALBASE}/bin/${FC}'"		>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "OTHERLIB='-Xlinker -export-dynamic ${PTHREAD_LIBS} -lutil -lm -lz -lgfortran ${PTHREAD_LIBS} -lz'"	\
		>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "SYSLIB='${PTHREAD_LIBS} -lz'"		>> ${WRKSRC}/setup.cfg
.if defined(WITH_MPI)
	${ECHO_CMD} "HOME_MPI = '${HOME_MPI}'"			>> ${WRKSRC}/setup.cfg
.else
	${ECHO_CMD} "HOME_MPI = ''"				>> ${WRKSRC}/setup.cfg
.endif
	${ECHO_CMD} "HOME_ZMAT = ''"				>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "HOME_HDF='${hdf_dir}'"			>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "HOME_MED='${LOCALBASE}'"			>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "HOME_TCL_TK='${tcl_dir}'"			>> ${WRKSRC}/setup.cfg
.if defined(WITH_ATLAS)
	${ECHO_CMD} "ATLASLIB='${lib_atlas}'"			>> ${WRKSRC}/setup.cfg
.endif
	${ECHO_CMD} "BLASLIB='${lib_blas}'"			>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "LAPACKLIB='lapack'"			>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "GZIP='/usr/bin/gzip'"			>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "SHELL_EXECUTION='${SHELL_INSTALL_ASTER}'"	>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "TERMINAL='xterm'"				>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "EDITOR='${WITH_ED}'"			>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "LDFLAGS='-v ${LDFLAGS}'"			>> ${WRKSRC}/setup.cfg
	# -O2 causes failure in compilation of the elements -see GCC Bug 51267
	${ECHO_CMD} "FFLAGS='-c ${FFLAGS:C|O2|O0|} -fno-tree-dse ${FLAGARCH} ${FFLAGARCH}'"	>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "FFLAGS_DBG='-c -g -O -fno-tree-dse ${FLAGARCH} ${FFLAGARCH}'"	>> ${WRKSRC}/setup.cfg
.if defined(WITH_MPI)
	${ECHO_CMD} "F90FLAGS='-c ${FFLAGS:C|O2|O0|} -fno-tree-dse ${FLAGARCH} ${FFLAGARCH} -I${LOCALBASE}/include -I${HOME_MPI}/include'"	\
		>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "F90FLAGS_DBG='-c -g -O -fno-tree-dse ${FLAGARCH} ${FFLAGARCH} -I${LOCALBASE}/include -I${HOME_MPI}/include'"	\
		>> ${WRKSRC}/setup.cfg
	# -O2 causes failure in compilation of the elements -see GCC Bug 51267
	${ECHO_CMD} "CFLAGS='-c ${CFLAGS:C|O2|O0|} -fno-tree-dse ${PTHREAD_CFLAGS} ${FLAGARCH} -I${LOCALBASE}/include -I${HOME_MPI}/include'"	\
		>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "CFLAGS_DBG='-c -g -O -pipe -fno-tree-dse ${PTHREAD_CFLAGS} ${FLAGARCH} -I${LOCALBASE}/include -I${HOME_MPI}/include'"	\
		>> ${WRKSRC}/setup.cfg
.else
	${ECHO_CMD} "F90FLAGS='-c ${FFLAGS:C|O2|O0|} -fno-tree-dse ${FLAGARCH} ${FFLAGARCH} -I${LOCALBASE}/include'"	\
		>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "F90FLAGS_DBG='-c -g -O -fno-tree-dse ${FLAGARCH} ${FFLAGARCH} -I${LOCALBASE}/include'"	\
		>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "CFLAGS='-c ${CFLAGS:C|O2|O0|} -fno-tree-dse ${PTHREAD_CFLAGS} ${FLAGARCH} -I${LOCALBASE}/include'"	\
		>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "CFLAGS_DBG='-c -g -O -pipe -fno-tree-dse ${PTHREAD_CFLAGS} ${FLAGARCH} -I${LOCALBASE}/include'"	\
		>> ${WRKSRC}/setup.cfg
.endif
.for is in ${INTERACTIVE_SCRIPTS}
	${REINPLACE_CMD} -e '/should_continue()/d'		\
		${WRKSRC}/${is}
.endfor
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}

do-configure:
	(cd ${CONFIGURE_WRKSRC} && ${PYTHON_CMD} setup.pyo ${DEBUG_FLAGS} test	\
		| tee ${CONFIGURE_LOG})
	@${ECHO_MSG} "---------------- Debug ------------------"
	${CAT} ${CONFIGURE_WRKSRC}/setup.log
	@${ECHO_MSG} "------------ Fin debug ------------------"

post-configure:
	${MKDIR} ${WRKSRC}/instdir/etc/
	${CP} -R ${LOCALBASE}/aster/etc/codeaster ${WRKSRC}/instdir/etc/
	${ECHO_CMD} "#?vers : VVV?" >> ${WRKSRC}/instdir/etc/codeaster/aster
	${CP} -R ${LOCALBASE}/aster/ASTK/ASTK_SERV/bin		\
		${LOCALBASE}/aster/ASTK/ASTK_SERV/asrun		\
		${LOCALBASE}/aster/ASTK/ASTK_SERV/share		\
		${WRKSRC}/instdir/
	${REINPLACE_CMD} -e 's|${LOCALBASE}/aster|${WRKSRC}/instdir|'	\
		${WRKSRC}/instdir/bin/as_run
.for sf in etc/codeaster/profile.sh asrun/installation.py
	${REINPLACE_CMD} -e 's|${LOCALBASE}/aster/ASTK/ASTK_SERV|${WRKSRC}/instdir|g'	\
		-e 's|${LOCALBASE}/aster|${WRKSRC}/instdir|g'	\
		${WRKSRC}/instdir/${sf}
.endfor

do-build:
	(cd ${BUILD_WRKSRC} &&	\
	${PYTHON_CMD} setup.pyo ${DEBUG_FLAGS} install aster	\
		| tee ${BUILD_WRKSRC}/build.log)
	${CHMOD} go-x ${WRKSRC}/instdir/${vaster}/materiau/A42_REF_A.NOMI

do-install:
	${MKDIR} ${tools_dir} ${inst_dir} ${PREFIX}/${PORTNAME}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/instdir/${vaster}/asteru ${inst_dir}
	#${INSTALL_SCRIPT} ${WRKSRC}/instdir/${vaster}/asterd ${inst_dir} # Don't strip!
	${INSTALL_SCRIPT} ${WRKSRC}/instdir/${vaster}/profile.sh ${inst_dir}
	${ECHO_CMD} "" >> ${inst_dir}/profile.sh
	${ECHO_CMD} "HDF5_DISABLE_VERSION_CHECK=1" >> ${inst_dir}/profile.sh
.for FILE in ${DAT2FIX}
	${SED} -e 's|${WRKSRC}/instdir/${vaster}|${inst_dir}|g'		\
		-e 's|${WRKSRC}/instdir/outils|${tools_dir}|g'		\
		-e 's|${WRKSRC}/instdir|${inst_dir}|g'			\
		-e 's|^F list|@F list|'					\
		-e 's|^#F list|F list|'					\
		-e 's|^@F list|#F list|'				\
		-e 's|P mode astout|P mode interactif|'			\
		-e 's|P mode forma01a|P mode interactif|'		\
		-e 's|R resu_test ${inst_dir}|R resu_test /tmp|'	\
	< ${WRKSRC}/instdir/${vaster}/${FILE} > ${inst_dir}/${FILE}
.endfor
	${LN} -sf ${inst_dir}/config.txt ${PREFIX}/${PORTNAME}/
.for FILE in ${INST_DAT} ${INST_PY}
	${CP} -R ${WRKSRC}/instdir/${vaster}/${FILE} ${inst_dir}
.endfor
.for FILE in ${INST_SH}
	${SED} -e 's|${WRKSRC}/instdir|${PREFIX}/${PORTNAME}|'	\
	< ${WRKSRC}/instdir/bin/${FILE} > ${PREFIX}/${PORTNAME}/bin/${FILE}
	${CHMOD} a+x ${PREFIX}/${PORTNAME}/bin/${FILE}
.endfor
	${REINPLACE_CMD} -e 's|cat ./fort.15 ./ficode|cat ./ficode|'	\
		${inst_dir}/bibpyt/Execution/E_SUPERV.py
.for FILE in ${INST_PY}
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${inst_dir}/${FILE}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${inst_dir}/${FILE}
.endfor

post-install:
	${LN} -fs ${LOCALBASE}/bin/kmetis ${tools_dir}/
	${LN} -fs ${LOCALBASE}/bin/onmetis ${tools_dir}/
	${LN} -fs ${LOCALBASE}/bin/pmetis ${tools_dir}/
	${LN} -fs ${LOCALBASE}/bin/gnuplot ${tools_dir}/
.if !defined(WITHOUT_ASTK_CLI)
	${LN} -fs ${ASTKDIR}/bin/astk ${tools_dir}/
	${LN} -fs ${ASTKDIR}/bin/bsf ${tools_dir}/
.endif
.if !defined(WITHOUT_EFICAS)
	${LN} -fs ${LOCALBASE}/bin/eficas ${tools_dir}/
. if exists(${LOCALBASE}/bin/qtEficas)
	${LN} -fs ${LOCALBASE}/bin/qtEficas ${tools_dir}/
. endif
.endif
.if !defined(WITHOUT_GMSH)
	${LN} -fs ${LOCALBASE}/bin/gmsh ${tools_dir}/
.endif
.if !defined(WITHOUT_GRACE)
	${LN} -fs ${LOCALBASE}/bin/gracebat ${tools_dir}/
	${LN} -fs ${LOCALBASE}/bin/xmgrace ${tools_dir}/
.endif
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.if defined(MAINTAINER_MODE)
regression-test:	install
	@${ECHO_MSG} "Note: homard must be installed to run some steps succesfully."
	(cd ${inst_dir};	\
	${LOCALBASE}/aster/ASTK/ASTK_SERV/bin/as_run astout.export) || ${TRUE}
	@${ECHO_MSG} "Check /tmp/resu_test/*.erre"
.endif

.include <bsd.port.post.mk>
