# New ports collection makefile for:	aster
# Date created:		Thu Jun 26 2003
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	aster
PORTVERSION=	7.4.0
PORTREVISION=	2
CATEGORIES=	french cad python
MASTER_SITES=	http://www.code-aster.org/FICHIERS/
DISTNAME=	${PORTNAME}-full-src-${PORTVERSION}-5

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Analyse des structures et thermo-mécanique

#-----------------------------------------------------------------------
# You may define these options:
#
# - F77: don't use the default fortran compiler;
# - FFLAGS: fortan compiler's flags (-O2 by default);
# - WITH_ZSH or WITH_BASH or WITH_KSH: select a shell among
#			zsh (default), bash or ksh;
# - WITH_ED: select an editor accepting '-display' (e.g. gvim, nedit);
# - WITH_BLAS: don't link with atlas, but with blas;
#			(blas is slower, but lighter)
# - WITHOUT_ASTK_CLI: won't use the GUI from this machine;
# - WITHOUT_EFICAS: don't install ASter Command FIle Editor;
# - WITHOUT_GMSH: don't install GMSH (a mesh generator);
# - WITHOUT_GRACE: don't install Grace (used to create 2D graph);
# - WITHOUT_MACR_RECAL: don't install Numerical Python
#			(required by the macro MACR_RECAL);
#
#-----------------------------------------------------------------------

BUILD_DEPENDS+=	${LOCALBASE}/aster/ASTK/ASTK_SERV:${PORTSDIR}/cad/astk-serveur	\
		${SHELL_INSTALL_ASTER}:${PORTSDIR}/shells/${SHIADEP}		\
		${PYNUMERIC}
LIB_DEPENDS+=	tcl${SHORT_TCL_VER}:${PORTSDIR}/lang/tcl${SHORT_TCL_VER}	\
		tk${SHORT_TK_VER}:${PORTSDIR}/x11-toolkits/tk${SHORT_TK_VER}	\
		hdf5.0:${PORTSDIR}/science/hdf5					\
		med.1:${PORTSDIR}/french/med
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/Gnuplot:${PORTSDIR}/math/py-gnuplot	\
		${LOCALBASE}/bin/onmetis.exe:${PORTSDIR}/math/metis-edf		\
		${LOCALBASE}/aster/ASTK/ASTK_SERV:${PORTSDIR}/cad/astk-serveur

#USE_GCC=	3.4	# Helps on 4.x, but not sufficient.
USE_PYTHON=	yes
HAS_CONFIGURE=	yes
USE_REINPLACE=	yes
REINPLACE_ARGS=	-i ""

WRKSRC=		${WRKDIR}/${PORTNAME}-src-${PORTVERSION}
PLIST_SUB=	ASTERDIR=${PORTNAME}/${vaster} TOOLDIR=${PORTNAME}/outils
PKGMESSAGE=	${WRKDIR}/pkg-message
.if defined(WITHOUT_ASTK_CLI)
PKGMESSIN=	pkg-message.sans-astk.in
.else
PKGMESSIN=	pkg-message.in
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
FLAGARCH=	P_LINUX		# 32 bits
.else
FLAGARCH=	TRU64		# 64 bits
.endif

.if ${OSVERSION} < 500000
BROKEN=	"Does not compile on FreeBSD-4.x, and cannot be patched easily."
.endif

.if defined(WITH_BLAS)
LIB_DEPENDS+=	blas.1:${PORTSDIR}/math/blas
.else
LIB_DEPENDS+=	f77blas.1:${PORTSDIR}/math/atlas
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

.if !${OSVERSION} < 500039
F77?=		f77
.endif
FFLAGS?=	-O2

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

vaster=		STA${PORTVERSION:S/.0//}
INST_DAT=	GPL.txt LICENSE.TERMS astest cata_ele.pickled catalo catapy	\
		elements etude materiau
INST_PY=	bibpyt commande
DAT2FIX=	astout.export config.txt forma01a.export
inst_dir=	${PREFIX}/${PORTNAME}/${vaster}
tools_dir=	${PREFIX}/${PORTNAME}/outils
v_ifdef=	${OPSYS:U}
SHELL_INSTALL_ASTER=	${LOCALBASE}/bin/${SHIA}
tcl_dir=	${LOCALBASE}
hdf_dir=	${LOCALBASE}
.if defined(WITH_BLAS)
lib_blas=	-lblas
.else
lib_blas=	-lf77blas -latlas
.endif
LASTKDIR?=	${PORTNAME}/ASTK/ASTK_CLIENT
ASTKDIR=	${LOCALBASE}/${LASTKDIR}

pre-configure:
	@${REINPLACE_CMD} -e 's|/opt/aster|${WRKSRC}/instdir|'		\
		-e 's|/usr/bin/gcc|${CC}|;s|/usr/bin/g77|${F77}|'	\
		${WRKSRC}/setup.cfg
	@${ECHO_CMD} "_install_hdf5 = False"			>> ${WRKSRC}/setup.cfg
	@${ECHO_CMD} "_install_med = False"			>> ${WRKSRC}/setup.cfg
	@${ECHO_CMD} "_install_tcl = False"			>> ${WRKSRC}/setup.cfg
	@${ECHO_CMD} "_install_tk  = False"			>> ${WRKSRC}/setup.cfg
	@${ECHO_CMD} "_install_Pmw = False"			>> ${WRKSRC}/setup.cfg
	@${ECHO_CMD} "_install_Numeric = False"			>> ${WRKSRC}/setup.cfg
	@${ECHO_CMD} "_install_gmsh = False"			>> ${WRKSRC}/setup.cfg
	@${ECHO_CMD} "_install_gibi = False"			>> ${WRKSRC}/setup.cfg
	@${ECHO_CMD} "_install_homard = False"			>> ${WRKSRC}/setup.cfg
	@${ECHO_CMD} "_install_eficas = False"			>> ${WRKSRC}/setup.cfg
	@${ECHO_CMD} "_install_astk = False"			>> ${WRKSRC}/setup.cfg
	@${ECHO_CMD} "_install_astk_serv = False"		>> ${WRKSRC}/setup.cfg
	@${ECHO_CMD} "_install_metis = False"			>> ${WRKSRC}/setup.cfg
	@${ECHO_CMD} "_install_crpcrs = False"			>> ${WRKSRC}/setup.cfg
	@${ECHO_CMD} "_install_aster_Linux = False"		>> ${WRKSRC}/setup.cfg
	@${ECHO_CMD} "HOME_HDF='${hdf_dir}'"			>> ${WRKSRC}/setup.cfg
	@${ECHO_CMD} "HOME_MED='${LOCALBASE}'"			>> ${WRKSRC}/setup.cfg
	@${ECHO_CMD} "HOME_TCL_TK='${tcl_dir}'"			>> ${WRKSRC}/setup.cfg
	@${ECHO_CMD} "BLASLIB='${lib_blas}'"			>> ${WRKSRC}/setup.cfg
	@${ECHO_CMD} "GZIP='/usr/bin/gzip'"			>> ${WRKSRC}/setup.cfg
	@${ECHO_CMD} "SHELL_EXECUTION='${SHELL_INSTALL_ASTER}'"	>> ${WRKSRC}/setup.cfg
	@${ECHO_CMD} "EDITOR='${WITH_ED}'"			>> ${WRKSRC}/setup.cfg
	@${ECHO_CMD} "LDFLAGS='-v ${LDFLAGS}'"			>> ${WRKSRC}/setup.cfg
	@${ECHO_CMD} "FFLAGS='-c ${FFLAGS} -D${FLAGARCH}'"	>> ${WRKSRC}/setup.cfg
	@${ECHO_CMD} "FFLAGS_DBG='-c -g -O -D${FLAGARCH}'"	>> ${WRKSRC}/setup.cfg
	@${ECHO_CMD} "CFLAGS='-c ${CFLAGS} ${PTHREAD_CFLAGS} -D${FLAGARCH}'"	\
		>> ${WRKSRC}/setup.cfg
	@${ECHO_CMD} "CFLAGS_DBG='-c -g -O -pipe ${PTHREAD_CFLAGS} -D${FLAGARCH}'"	\
		>> ${WRKSRC}/setup.cfg
	@${ECHO_CMD} "SYSLIBS='-Xlinker -export-dynamic ${PTHREAD_LIBS} -lutil -lm -lz -lg2c'"	\
		>> ${WRKSRC}/setup.cfg

do-configure:
	(cd ${CONFIGURE_WRKSRC} && ${PYTHON_CMD} setup.py test		\
		| tee ${CONFIGURE_LOG})

pre-build:
	${MKDIR} ${WRKSRC}/instdir/ASTK/ASTK_SERV/conf
	${SED} -e 's|${LOCALBASE}/aster|${WRKSRC}/instdir|'	\
		< ${LOCALBASE}/aster/ASTK/ASTK_SERV/conf/config		\
		> ${WRKSRC}/instdir/ASTK/ASTK_SERV/conf/config
	${LN} -sf ${LOCALBASE}/aster/ASTK/ASTK_SERV/bin			\
		${WRKSRC}/instdir/ASTK/ASTK_SERV
	${LN} -sf ${LOCALBASE}/aster/ASTK/ASTK_SERV/lib			\
		${WRKSRC}/instdir/ASTK/ASTK_SERV

do-build:
	(cd ${BUILD_WRKSRC} && ${PYTHON_CMD} setup.py install		\
		| tee ${BUILD_WRKSRC}/build.log)

pre-install:
	${CHMOD} go-x ${WRKSRC}/instdir/${vaster}/materiau/A42_REF_A.NOMI

do-install:
	${MKDIR} ${tools_dir} ${inst_dir}
	${INSTALL_PROGRAM} ${WRKSRC}/instdir/${vaster}/asteru ${inst_dir}
	${INSTALL_SCRIPT} ${WRKSRC}/instdir/${vaster}/asterd ${inst_dir} # Don't strip!
.for FILE in ${DAT2FIX}
	${SED} -e 's|${WRKSRC}/instdir/${vaster}|${inst_dir}|g'		\
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
test:	install
	(cd ${inst_dir};	\
	${LOCALBASE}/aster/ASTK/ASTK_SERV/bin/as_run forma01a.export)
	@${ECHO_CMD} Note: homard must be installed to run some steps succesfully.
	(cd ${inst_dir};	\
	${LOCALBASE}/aster/ASTK/ASTK_SERV/bin/as_run astout.export)
.endif

.include <bsd.port.post.mk>
