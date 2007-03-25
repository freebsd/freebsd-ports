# New ports collection makefile for:	aster
# Date created:		Thu Jun 26 2003
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	aster
DISTVERSION=	9.0.0-2
PORTREVISION=	1
CATEGORIES=	french cad python
MASTER_SITES=	http://www.code-aster.org/FICHIERS/
DISTNAME=	${PORTNAME}-full-src-${DISTVERSION}.noarch

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Code_Aster finite element method solver

#-----------------------------------------------------------------------
# You may define these options:
#
# - F77: don't use the default fortran compiler;
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
		${PYNUMERIC}
LIB_DEPENDS+=	tcl${SHORT_TCL_VER}:${PORTSDIR}/lang/tcl${SHORT_TCL_VER}	\
		tk${SHORT_TK_VER}:${PORTSDIR}/x11-toolkits/tk${SHORT_TK_VER}	\
		hdf5.0:${PORTSDIR}/science/hdf5					\
		med.2:${PORTSDIR}/french/med
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/Gnuplot:${PORTSDIR}/math/py-gnuplot	\
		${LOCALBASE}/bin/onmetis.exe:${PORTSDIR}/math/metis-edf		\
		${LOCALBASE}/aster/ASTK/ASTK_SERV:${PORTSDIR}/cad/astk-serveur

USE_BISON=	yes
USE_PYTHON=	yes
HAS_CONFIGURE=	yes
REINPLACE_ARGS=	-i ""

WRKSRC=		${WRKDIR}/${PORTNAME}-full-src-${PORTVERSION:R}
PLIST_SUB=	ASTERDIR=${PORTNAME}/${vaster} TOOLDIR=${PORTNAME}/${vaster}/outils
PKGMESSAGE=	${WRKDIR}/pkg-message
.if defined(WITHOUT_ASTK_CLI)
PKGMESSIN=	pkg-message.sans-astk.in
.else
PKGMESSIN=	pkg-message.in
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
FLAGARCH=	-DP_LINUX -DLINUX
FFLAGARCH=
.else
FLAGARCH=	-DLINUX64
FFLAGARCH=	-fdefault-integer-8 -fdefault-real-8
.endif

.if ${OSVERSION} < 600022
BROKEN=	Does not compile on this version, and cannot be patched easily.
.endif
#.if ${ARCH} != "i386"
#BROKEN=	Seg. fault on ${ARCH} during compilation of elements.
#.endif

.if exists(${LOCALBASE}/lib/libatlas_r.so) && !defined(WITH_BLAS)
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
RUN_DEPENDS+=	${X11BASE}/bin/xmgrace:${PORTSDIR}/math/grace
PLIST_SUB+=	GRACE=""
.else
PLIST_SUB+=	GRACE="@comment "
.endif
.if !defined(WITHOUT_MACR_RECAL)
RUN_DEPENDS+=	${PYNUMERIC}
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
MUMPSLIB=	-L${LOCALBASE}/lib -ldmumps -lzmumps -lpord -lscalapack -lblacs -lblacsc -lblacs -L${LOCALBASE}/mpich2/lib -lmpich
. endif
BUILD_DEPENDS+=	${LOCALBASE}/lib/libcmumps.a:${PORTSDIR}/math/${MUMPS_PORT}
.endif

.if defined(WITH_MPI)
BUILD_DEPENDS+=	${HOME_MPI}/include/mpif.h:${PORTSDIR}/net/mpich2
HOME_MPI=	${LOCALBASE}/mpich2
.endif

WANT_FORTRAN=	yes #dummy but future use
BUILD_DEPENDS+=	gfortran42:${PORTSDIR}/lang/gcc42
FC=		gfortran42
F77=		gfortran42
FORTRANLIBDIR=	`${DIRNAME} \`gfortran42 -print-libgcc-file-name\``
FORTRANLIBDIR2=	`${DIRNAME} \`gfortran42 -print-libgcc-file-name\``/../../../

TK_VER?=	8.4
SHORT_TK_VER=	${TK_VER:S/.//}

TCL_VER?=	${TK_VER}
SHORT_TCL_VER=	${TCL_VER:S/.//}

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
.if ${SHIA} == "bash"
SHIADEP=	bash2
.else
SHIADEP=	${SHIA}
.endif

.if !defined(WITH_ED)
. if exists(${X11BASE}/bin/nedit)
WITH_ED=	nedit
RUN_DEPENDS+=	${X11BASE}/bin/nedit:${PORTSDIR}/editors/nedit
. elif exists(${LOCALBASE}/bin/gvim)
WITH_ED=	gvim
RUN_DEPENDS+=	${LOCALBASE}/bin/gvim:${PORTSDIR}/editors/vim
. elif exists(${LOCALBASE}/bin/emacs)
WITH_ED=	emacs
RUN_DEPENDS+=	${LOCALBASE}/bin/emacs:${PORTSDIR}/editors/emacs
. elif exists(${LOCALBASE}/bin/xemacs)
WITH_ED=	xemacs
RUN_DEPENDS+=	${LOCALBASE}/bin/xemacs:${PORTSDIR}/editors/xemacs
. else
WITH_ED=	xedit
RUN_DEPENDS+=	${X11BASE}/bin/xedit:${X_CLIENTS_PORT}
. endif
.endif

vaster=		STA${PORTVERSION:R:R}
INST_DAT=	LICENSE.TERMS astest cata_ele.pickled catalo catapy	\
		elements etude materiau
INST_PY=	bibpyt commande
DAT2FIX=	astout.export config.txt forma01a.export
inst_dir=	${PREFIX}/${PORTNAME}/${vaster}
tools_dir=	${inst_dir}/outils
v_ifdef=	${OPSYS:U}
SHELL_INSTALL_ASTER=	${LOCALBASE}/bin/${SHIA}
tcl_dir=	${LOCALBASE}
hdf_dir=	${LOCALBASE}
.if defined(WITH_ATLAS)
lib_blas=	ptf77blas
lib_atlas=	atlas_r
.else
lib_blas=	blas
lib_atlas=	# empty
.endif
LASTKDIR?=	${PORTNAME}/ASTK/ASTK_CLIENT
ASTKDIR=	${LOCALBASE}/${LASTKDIR}

${WRKSRC}/instdir/${vaster}/elements:	build

pre-configure:
	${REINPLACE_CMD} -e 's|PREFER_SHARED_LIBS=False|PREFER_SHARED_LIBS=True|' ${WRKSRC}/setup.cfg
	${REINPLACE_CMD} -e 's|/opt/aster|${WRKSRC}/instdir|'		\
		-e 's|/usr/bin/gcc|${CC}|;s|/usr/bin/g77|${F77}|'	\
		${WRKSRC}/setup.cfg
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
	${ECHO_CMD} "_install_gibi = False"			>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "_install_grace = False"			>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "XMGRACE = 'xmgrace'"			>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "_install_homard = False"			>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "_install_eficas = False"			>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "_install_astk = False"			>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "_install_astk_serv = False"		>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "_install_metis = False"			>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "_install_crpcrs = False"			>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "_install_aster_Linux = False"		>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "_install_scotch  = False"			>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "HOME_SCOTCH = '${LOCALBASE}'"		>> ${WRKSRC}/setup.cfg
.if defined(WITH_MUMPS)
	${ECHO_CMD} "HOME_MUMPS = '${LOCALBASE}'"		>> ${WRKSRC}/setup.cfg
. if ${MUMPS_PORT} == "mumps-mpich"
	# else libmpiseq.a used instead of libmpich, default is OK
	${ECHO_CMD} "MUMPSLIB = '${MUMPSLIB}'"			>> ${WRKSRC}/setup.cfg
. endif
.endif
	${ECHO_CMD} "F90='${LOCALBASE}/bin/${FC}'"		>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "SYSLIB='-Xlinker -export-dynamic ${PTHREAD_LIBS} -lutil -lm -lz -L${FORTRANLIBDIR} -L${FORTRANLIBDIR2} -lgfortranbegin  -lgfortran'"	\
		>> ${WRKSRC}/setup.cfg

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
	${ECHO_CMD} "LAPACKLIB='${LOCALBASE}/lib/liblapack.a'"	>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "GZIP='/usr/bin/gzip'"			>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "SHELL_EXECUTION='${SHELL_INSTALL_ASTER}'"	>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "EDITOR='${WITH_ED}'"			>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "LDFLAGS='-v ${LDFLAGS}'"			>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "FFLAGS='-c ${FFLAGS} ${FLAGARCH} ${FFLAGARCH}'"	>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "FFLAGS_DBG='-c -g -O ${FLAGARCH} ${FFLAGARCH}'"	>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "F90FLAGS='-c ${FFLAGS} ${FLAGARCH} ${FFLAGARCH} -I${LOCALBASE}/include -I${HOME_MPI}/include'"	\
		>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "F90FLAGS_DBG='-c -g -O ${FLAGARCH} ${FFLAGARCH} -I${LOCALBASE}/include -I${HOME_MPI}/include'"	\
		>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "CFLAGS='-c ${CFLAGS} ${PTHREAD_CFLAGS} ${FLAGARCH} -I${LOCALBASE}/include'"	\
		>> ${WRKSRC}/setup.cfg
	${ECHO_CMD} "CFLAGS_DBG='-c -g -O -pipe ${PTHREAD_CFLAGS} ${FLAGARCH} -I${LOCALBASE}/include'"	\
		>> ${WRKSRC}/setup.cfg
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}

do-configure:
	(cd ${CONFIGURE_WRKSRC} && ${PYTHON_CMD} setup.pyo test		\
		| tee ${CONFIGURE_LOG})
	@${ECHO_MSG} "---------------- Debug ------------------"
	${CAT} ${CONFIGURE_WRKSRC}/setup.log
	@${ECHO_MSG} "------------ Fin debug ------------------"

pre-build:
	${MKDIR} ${WRKSRC}/instdir/ASTK/ASTK_SERV/conf ${WRKSRC}/instdir/outils
	${SED} -e 's|${LOCALBASE}/aster|${WRKSRC}/instdir|'		\
		< ${LOCALBASE}/aster/ASTK/ASTK_SERV/conf/config		\
		> ${WRKSRC}/instdir/ASTK/ASTK_SERV/conf/config
	${CP} ${LOCALBASE}/aster/ASTK/ASTK_SERV/conf/aster_profile.sh	\
		${WRKSRC}/instdir/ASTK/ASTK_SERV/conf
	${LN} -sf ${LOCALBASE}/aster/ASTK/ASTK_SERV/bin			\
		${WRKSRC}/instdir/ASTK/ASTK_SERV
	${LN} -sf ${LOCALBASE}/aster/ASTK/ASTK_SERV/lib			\
		${WRKSRC}/instdir/ASTK/ASTK_SERV

do-build:
	(cd ${BUILD_WRKSRC} && ${PYTHON_CMD} setup.pyo install		\
		| tee ${BUILD_WRKSRC}/build.log)

pre-install:
	${CHMOD} go-x ${WRKSRC}/instdir/${vaster}/materiau/A42_REF_A.NOMI

do-install:	${WRKSRC}/instdir/${vaster}/elements
	${MKDIR} ${tools_dir} ${inst_dir}
	${INSTALL_PROGRAM} ${WRKSRC}/instdir/${vaster}/asteru ${inst_dir}
	${INSTALL_SCRIPT} ${WRKSRC}/instdir/${vaster}/asterd ${inst_dir} # Don't strip!
	${INSTALL_SCRIPT} ${WRKSRC}/instdir/${vaster}/profile.sh ${inst_dir}
	${ECHO_CMD} "HDF5_DISABLE_VERSION_CHECK=1" >> ${inst_dir}/profile.sh
.for FILE in ${DAT2FIX}
	${SED} -e 's|${WRKSRC}/instdir/${vaster}|${inst_dir}|g'		\
		-e 's|${WRKSRC}/instdir|${inst_dir}|g'			\
		-e 's|${WRKSRC}/instdir/outils|${tools_dir}|g'		\
		-e 's|P mode astout|P mode interactif|'			\
		-e 's|P mode forma01a|P mode interactif|'		\
	< ${WRKSRC}/instdir/${vaster}/${FILE} > ${inst_dir}/${FILE}
.endfor
.for FILE in ${INST_DAT} ${INST_PY}
	${CP} -R ${WRKSRC}/instdir/${vaster}/${FILE} ${inst_dir}
.endfor
	${REINPLACE_CMD} -e 's|cat ./fort.15 ./ficode|cat ./ficode|'	\
		${inst_dir}/bibpyt/Execution/E_SUPERV.py
.for FILE in ${INST_PY}
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${inst_dir}/${FILE}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${inst_dir}/${FILE}
.endfor

post-install:
	@${TOUCH} ${inst_dir}/etude/forma01a.17
	${LN} -fs ${LOCALBASE}/bin/kmetis ${tools_dir}/
	${LN} -fs ${LOCALBASE}/bin/onmetis ${tools_dir}/
	${LN} -fs ${LOCALBASE}/bin/pmetis ${tools_dir}/
	${LN} -fs ${LOCALBASE}/bin/gnuplot ${tools_dir}/
.if !defined(WITHOUT_ASTK) && !defined(WITHOUT_ASTK_CLI)
	${LN} -fs ${ASTKDIR}/bin/astk ${tools_dir}/
	${LN} -fs ${ASTKDIR}/bin/bsf ${tools_dir}/
.endif
.if !defined(WITHOUT_EFICAS)
	${LN} -fs ${LOCALBASE}/bin/eficas ${tools_dir}/
.endif
.if !defined(WITHOUT_GMSH)
	${LN} -fs ${LOCALBASE}/bin/gmsh ${tools_dir}/
.endif
.if !defined(WITHOUT_GRACE)
	${LN} -fs ${X11BASE}/bin/gracebat ${tools_dir}/
	${LN} -fs ${X11BASE}/bin/xmgrace ${tools_dir}/
.endif
	@${ECHO_MSG}
	@${SED} -e "s#%%tools_dir%%#${tools_dir}#"	\
		${FILESDIR}/${PKGMESSIN} > ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.if defined(MAINTAINER_MODE)
regression-test:	install
	(cd ${inst_dir};	\
	${LOCALBASE}/aster/ASTK/ASTK_SERV/bin/as_run forma01a.export)
	@${ECHO_CMD} Note: homard must be installed to run some steps succesfully.
	(cd ${inst_dir};	\
	HDF5_DISABLE_VERSION_CHECK=1	\
	${LOCALBASE}/aster/ASTK/ASTK_SERV/bin/as_run astout.export)
	@${ECHO_CMD} Check ${inst_dir}/astest/*.erre
.endif

.include <bsd.port.post.mk>
