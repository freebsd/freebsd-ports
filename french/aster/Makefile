# New ports collection makefile for:	aster
# Date created:		Thu Jun 26 2003
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	aster
PORTVERSION=	7.2.0
CATEGORIES=	french cad python tk84
MASTER_SITES=	http://www.code-aster.org/FICHIERS/
DISTNAME=	${PORTNAME}-src-${PORTVERSION}-2
EXTRACT_SUFX=	.tar

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Analyse des structures et thermo-mécanique

#-----------------------------------------------------------------------
# You may define these options:
#
# - F77: don't use the default fortran compiler;
# - FFLAGS: fortan compiler's flags (-O2 by default);
# - WITH_ZSH or WITH_BASH or WITH_KSH: select a shell among
#			zsh (default), bash or ksh;
# - WITH_BLAS: don't link with atlas, but with blas;
#			(blas is slower, but lighter)
# - WITHOUT_ASTK: don't use the GUI;
# - WITHOUT_ASTK_CLI: won't use the GUI from this machine;
# - WITHOUT_EFICAS: don't install ASter Command FIle Editor;
# - WITHOUT_GMSH: don't install GMSH (a mesh generator);
# - WITHOUT_GRACE: don't install Grace (used to create 2D graph);
# - WITHOUT_MACR_RECAL: don't install Numerical Python
#			(required by the macro MACR_RECAL);
#
#-----------------------------------------------------------------------

PATCH_DEPENDS=	tclsh${TCL_VER}:${PORTSDIR}/lang/tcl${SHORT_TCL_VER}		\
		wish${TK_VER}:${PORTSDIR}/x11-toolkits/tk${SHORT_TK_VER}
BUILD_DEPENDS=	${opt_hdf}:${PORTSDIR}/graphics/hdf5				\
		${opt_med}:${PORTSDIR}/french/med				\
		${SHELL_INSTALL_ASTER}:${PORTSDIR}/shells/${SHIADEP}
LIB_DEPENDS=	tcl${SHORT_TCL_VER}:${PORTSDIR}/lang/tcl${SHORT_TCL_VER}	\
		tk${SHORT_TK_VER}:${PORTSDIR}/x11-toolkits/tk${SHORT_TK_VER}
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/Gnuplot:${PORTSDIR}/math/py-gnuplot	\
		${LOCALBASE}/bin/onmetis.exe:${PORTSDIR}/math/metis-edf

EXTRACT_CMD=	${TAR}
EXTRACT_BEFORE_ARGS=	-xf
EXTRACT_AFTER_ARGS=	# empty
USE_GCC=	3.2
USE_PYTHON=	yes
USE_REINPLACE=	yes
REINPLACE_ARGS=	-i ""

EXTDIR=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-2.src
WRKSRC=		${EXTDIR}/${vaster}
PLIST_SUB=	ASTERDIR=${PORTNAME}/${vaster}
.if defined(WITHOUT_ASTK) || defined(WITHOUT_ASTK_CLI)
PKGMESSAGE=	${PKGDIR}/pkg-message.sans-astk
.endif

.include <bsd.port.pre.mk>

.if defined(WITH_BLAS)
LIB_DEPENDS+=	blas.1:${PORTSDIR}/math/blas
.else
LIB_DEPENDS+=	f77blas.1:${PORTSDIR}/math/atlas
.endif
.if !defined(WITHOUT_ASTK)
RUN_DEPENDS+=	${LOCALBASE}/ASTK/ASTK_SERV:${PORTSDIR}/cad/astk-serveur
.if !defined(WITHOUT_ASTK_CLI)
RUN_DEPENDS+=	${LOCALBASE}/ASTK/ASTK_CLIENT:${PORTSDIR}/cad/astk-client
PLIST_SUB+=	ASTK_CLIENT=""  ASTKDIR=${ASTKDIR}
.else
PLIST_SUB+=	ASTK_CLIENT="@comment " ASTKDIR=""
.endif
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
TKCONFIG=	${LOCALBASE}/lib/tk${TK_VER}/tkConfig.sh

TCL_VER?=	${TK_VER}
SHORT_TCL_VER=	${TCL_VER:S/.//}
TCLCONFIG=	${LOCALBASE}/lib/tcl${TK_VER}/tclConfig.sh

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

vaster=		STA${PORTVERSION:S/.0//}
MK_FILES=	make_aster make_cata make_etude make_exec make_lib make_test
INST_DAT=	astest bibpyt cata_ele.pickled catalo catapy commande	\
		config.txt elements etude materiau tcl
python_path=	${PYTHON_LIBDIR}:${PYTHON_LIBDIR}/lib-dynload:${PYTHON_SITELIBDIR}:${PYTHON_SITELIBDIR}/Numeric
inst_dir=	${PREFIX}/${PORTNAME}/${vaster}
tools_dir=	${inst_dir}/outils
unames!=	${UNAME} -s
v_ifdef=	${unames:U}
SHELL_INSTALL_ASTER=	${LOCALBASE}/bin/${SHIA}
tcl_dir=	${LOCALBASE}
tcl_bin=	tclsh${TK_VER}
python_dir=	${PYTHONBASE}/bin
hdf_dir=	${LOCALBASE}
opt_hdf=	${hdf_dir}/lib/libhdf5.a
opt_med=	${LOCALBASE}/lib/libmed.a
.if defined(WITH_BLAS)
lib_blas=	-lblas
.else
lib_blas=	-lf77blas -latlas
.endif
home_ar!=	dirname `${WHICH} ${AR}`
gzip!=		dirname `${WHICH} ${GZIP_CMD}`
LASTKDIR?=	ASTK/ASTK_CLIENT
ASTKDIR=	${LOCALBASE}/${LASTKDIR}

post-extract:
	@(cd ${EXTDIR} && \
	${TAR} xfz ${EXTDIR}/${PORTNAME}.tar.gz)

post-patch:
.for mk_file in ${MK_FILES}
	@${REINPLACE_CMD} -e "s#HOME_CODE_ASTER#${WRKSRC}#g"			\
	-e "s#IFDEF#${v_ifdef}#"						\
	-e "s#HOME_XTERM#${X11BASE}/bin#"					\
	-e "s#REP_TOOLS#${tools_dir}#" ${WRKSRC}/tcl/${mk_file}
.endfor
	@${REINPLACE_CMD} -e "s#HOME_CODE_ASTER#${WRKSRC}#g"			\
	-e "s#HOME_TCL_TK#${tcl_dir}#g"						\
	-e "s#TCL_BIN#${tcl_bin}#g"						\
	-e "s#TCL_TK_VERSION#${TK_VER}#g"					\
	-e "s#HOME_PYTHON#${python_dir}#g"					\
	-e "s#/bin/sh#${SHELL_INSTALL_ASTER}#g"					\
	-e "s#%%PYTHONPATH%%#${python_path}#"					\
	${WRKSRC}/tcl/run_aster
	@${CHMOD} 755 ${WRKSRC}/tcl/run_aster
.if !exists(${WRKSRC}/tcl/conf/${v_ifdef}/config.txt)
	@${MKDIR} ${WRKSRC}/tcl/conf/${v_ifdef}
	@${CP} ${FILESDIR}/config.txt ${WRKSRC}/tcl/conf/${v_ifdef}
.endif
	@${GREP} TCL_LIB_SPEC ${TCLCONFIG} |					\
		${SED} -e "s#TCL_LIB_SPEC='##;s#\$${TCL_DBGX}'##"		\
		> ${WRKDIR}/tcl_lib_spec
	@${GREP} TK_LIB_SPEC ${TKCONFIG} |					\
		${SED} -e "s#TK_LIB_SPEC='##;s#'##" > ${WRKDIR}/tk_lib_spec
	@${REINPLACE_CMD} -e "s#OPT_HDF#${opt_hdf}#"				\
	-e "s#HDF_DIR#${hdf_dir}#"						\
	-e "s#OPT_MED#${opt_med}#"						\
	-e "s#OPT_TCL#`${CAT} ${WRKDIR}/tcl_lib_spec`#"				\
	-e "s#OPT_TK#`${CAT} ${WRKDIR}/tk_lib_spec`#"				\
	-e "s#OPT_X11#-L${X11BASE}/lib -lX11#"					\
	-e "s#OPT_BLAS#${lib_blas}#"						\
	-e "s#HOME_AR#${home_ar}#"						\
	-e "s#%%F77%%#${F77}#"							\
	-e "s#%%CC%%#${CC}#"							\
	-e "s#CFLAGS#${CFLAGS} ${PTHREAD_CFLAGS}#"				\
	-e "s#FFLAGS#${FFLAGS}#"						\
	-e "s#HOME_GZIP#${gzip}#"						\
	-e "s#HOME_PYTHON#${PYTHONBASE}#"					\
	-e "s#PYTHON_BIN#${PYTHON_VERSION}#"					\
	-e "s#PYTHON_VERSION#${_PYTHON_VERSION}#g"				\
	-e "s#PTHREAD#${PTHREAD_LIBS}#"						\
		${WRKSRC}/tcl/conf/${v_ifdef}/config.txt
	@${MV} ${WRKSRC}/tcl/conf/${v_ifdef}/config.txt ${WRKSRC}
	@${RM} ${WRKSRC}/tcl/run_aster.orig
	@${RM} -rf ${WRKSRC}/tcl/conf
	@${RM} -rf ${WRKSRC}/bibpyt/Utilitai
	@${REINPLACE_CMD} -e "s#\$$(HOME)#${LOCALBASE}/apps#"			\
		${WRKSRC}/bibpyt/Execution/E_SUPERV.py
	@${REINPLACE_CMD} -e "s#%%inst_dir%%#${inst_dir}#"			\
		${WRKSRC}/bibc/utilitai/asterm.c

do-build:
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}/bibpyt
	${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}/bibpyt
	(cd ${WRKSRC}/tcl&& ${SETENV} PYTHONPATH=${python_path} \
		./run_aster make_aster)

do-install:
.for mk_file in ${MK_FILES} run_aster ../config.txt
	${REINPLACE_CMD} -e "s#${WRKSRC}#${inst_dir}#g" ${WRKSRC}/tcl/${mk_file}
.endfor
	${MKDIR} ${tools_dir}
.for FILE in ${INST_DAT}
	${CP} -R ${WRKSRC}/${FILE} ${inst_dir}
.endfor
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${inst_dir}
	${INSTALL_PROGRAM} ${WRKSRC}/asteru.exe ${inst_dir}
	${INSTALL_SCRIPT} ${WRKSRC}/tcl/run_aster ${inst_dir}/tcl

post-install:
	${LN} -fs ${LOCALBASE}/bin/onmetis ${tools_dir}/
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
	${LN} -fs ${X11BASE}/bin/xmgrace ${tools_dir}/
.endif
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE} | ${SED} -e "s#%%inst_dir%%#${inst_dir}#"
	@${ECHO_MSG}

.if defined(MAINTAINER_MODE)
test:	install
	(cd ${inst_dir}/tcl;	\
	./run_aster make_etude)
	(cd ${inst_dir}/tcl;	\
	./run_aster make_test)
.endif

.include <bsd.port.post.mk>
