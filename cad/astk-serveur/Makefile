# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	astk
DISTVERSION=	1.13.8-2
CATEGORIES=	cad
.if !defined(CLIENT_SEUL)
PKGNAMESUFFIX=	-serveur
.else
PKGNAMESUFFIX=	-client
.endif

MAINTAINER=	thierry@FreeBSD.org
COMMENT?=	Graphical interface for Code_Aster (server side)

LICENSE=	GPLv2

#-----------------------------------------------------------------------
# You may define these options:
#
# - WITH_ZSH or WITH_BASH or WITH_KSH: select a shell among
#			zsh (default), bash or ksh;
# - WITH_ED: select an editor accepting '-display' (e.g. gvim, nedit);
# - WITH_PBS: PBS (batch scheduler) support is experimental.
#
#-----------------------------------------------------------------------

# There exists a "logical" RUN_DEPENDS towards french/aster and french/eficas
# for the server part, but it is not set to avoid circular dependences.

RUN_DEPENDS+=	${SHELL_INSTALL_ASTER}:shells/${SHIADEP}

.if !defined(CLIENT_SEUL)
USES+=		gettext python tk:build
.else
USES+=		tk
.endif
NO_BUILD=	yes
REINPLACE_ARGS=	-i ""

EXTRACT_WRKSRC=	${WRKDIR}/aster-${DISTVERSIONPREFIX}${ASTER_DISTVERSION:S/-/./:R}/SRC

NO_ARCH=	yes
SUB_FILES=	pkg-message
SUB_LIST=	inst_dir=${inst_dir} tools_dir=${tools_dir}
PKGMESSAGE=	${WRKDIR}/pkg-message
LINSTDIR=	aster/ASTK
inst_dir=	${PREFIX}/${LINSTDIR}
aster_dir=	${LOCALBASE}/aster/${vaster}
S_SCRIPTS=	bin/as_run bin/parallel_cp asrun/installation.py	\
		share/codeaster/asrun/data/mpirun_template
S_PYLIBS=	share/codeaster/asrun/examples/alamain.py		\
		unittest/datafiles/config_serveurs unittest/010_misc.py	\
		unittest/015_package.py unittest/run_test.py
C_SCRIPTS=	bin/astk bin/bsf
tools_dir=	${LOCALBASE}/aster/outils
conf_dir=	${WRKSRC}/etc/astkrc

.include <bsd.port.pre.mk>

WRKCONF=	${WRKDIR}/${PORTNAME}-${PORTVERSION:R}/configuration
.if !defined(CLIENT_SEUL)
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}/ASTK_SERV
PATCHDIR=	${MASTERDIR}/files
PLIST_SUB=	ASTKDIR=${LINSTDIR}/ASTK_SERV SERV="" CLIENT="@comment "\
		vaster=${vaster}
PATCH2RM=	bin/as_run bin/parallel_cp etc/asrun etc/profile.sh	\
		asrun/config.py asrun/installation.py asrun/system.py	\
		asrun/common/sysutils.py asrun/system_command.py
. if exists(${LOCALBASE}/sbin/pbs_server)
WITH_PBS=	yes
. endif
. if exists(${LOCALBASE}/bin/mpirun)
WITH_MPI=	yes
. endif
. if defined(WITH_MPI)
RUN_DEPENDS+=	${HOME_MPI}/bin/mpirun:net/mpich2
HOME_MPI=	${LOCALBASE}
PLIST_SUB+=	MPI=""
. else
PLIST_SUB+=	MPI="@comment "
. endif
. if defined(WITH_PBS)
RUN_DEPENDS+=	qsub:sysutils/torque
. endif
.else
RUN_DEPENDS+=	xterm:x11/xterm						\
		${LOCALBASE}/lib/${TKPNG}/pkgIndex.tcl:graphics/tkpng
TKPNG_VER=	0.9
TKPNG=		tkpng${TKPNG_VER}
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}/ASTK_CLIENT
PATCHDIR=	${MASTERDIR}/files.client
PLIST_SUB=	ASTKDIR=${LINSTDIR}/ASTK_CLIENT SERV="@comment " CLIENT="" vaster=""	\
		BWidget_DIR=${LINSTDIR}/ASTK_CLIENT/lib/BWidget-${BWidget_VER}
PATCH2RM=	bin/astk bin/bsf etc/astkrc/outils lib/init.tcl lib/tkselecteur.tcl
.endif
FILESDIR=	${PATCHDIR}

SLAVEDIRS=	cad/astk-client

BWidget_VER=	1.7.0

vaster=		STA${ASTER_VER:R}
ETCDIR=		${PREFIX}/aster/etc/codeaster

GIBI=		gibi2003

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
BASH2RC=	asrun/calcul.py share/codeaster/asrun/data/mpirun_template
BASH2RC2=	lib/tkselecteur.tcl
BASH2RC3=	deprecated_outils.sh extract_info.py deprecated_client.sh	\
		deprecated_server.sh

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
. elif exists(${LOCALBASE}/bin/kwrite)
WITH_ED=	kwrite
RUN_DEPENDS+=	${LOCALBASE}/bin/kwrite:editors/kate
. elif exists(${LOCALBASE}/bin/xedit)
WITH_ED=	xedit
RUN_DEPENDS+=	${LOCALBASE}/bin/xedit:x11/xedit
. else
WITH_ED=	vi
. endif
.endif

unamesm=	${OPSYS} ${ARCH}
v_ifdef=	${OPSYS:tu}
SHELL_INSTALL_ASTER=	${LOCALBASE}/bin/${SHIA}

.if !defined(PACKAGE_BUILDING)
SERVER_NAME!=	${UNAME} -n
HOST_NAME!=	/bin/hostname -s
DOMAIN_NAME=	${SERVER_NAME:S|${HOST_NAME}.||}
.else
SERVER_NAME=	put.your.fdqn
HOST_NAME=	this-hostname
DOMAIN_NAME=	your.domain-name
.endif

.if defined(LANG) && ${LANG:Mfr*} != ""
ASTK_LANG=	FR
.else
ASTK_LANG=	ENG
.endif

pre-configure:
	${RM} ${PATCH2RM:C|^|${WRKSRC}/|:C|$|.orig|}

do-configure:
.if !defined(CLIENT_SEUL)
. for scripts in ${S_SCRIPTS}
	${REINPLACE_CMD} -e "s|?SHELL_EXECUTION?|${SHELL_INSTALL_ASTER}|"	\
		-e "s|?ASTER_ROOT?|${PREFIX}/aster|" ${WRKSRC}/${scripts}
. endfor
	${REINPLACE_CMD} -e "s|?ASTER_VERSION?|${vaster}|"			\
		 -e 's|#?vers : VVV?|vers : ${vaster}|'				\
		${WRKSRC}/etc/aster
	${REINPLACE_CMD} -e 's|?DEBUGGER_COMMAND_POST?|gdb -batch --command=@D @E @C|'\
		-e 's|?DEBUGGER_COMMAND?|gdb --dbx --command=@D @E @C|'		\
		${WRKSRC}/etc/asrun
. if defined(WITH_MPI)
	${REINPLACE_CMD} -e "s|?MPIRUN?|${HOME_MPI}/bin/mpirun|"		\
		-e "s|?ASTER_CONFDIR?|${PREFIX}/aster|"				\
		${WRKSRC}/etc/asrun
. endif
. for sc in asrun aster
	${REINPLACE_CMD} -e "s|?IFDEF?|${v_ifdef}|"				\
		-e "s|?EDITOR?|${WITH_ED}|"					\
		-e "s|?TERMINAL?|${LOCALBASE}/bin/xterm|"			\
		-e "s|?NODE?|${HOST_NAME}|"					\
		-e "s|LOCALBASE|${LOCALBASE}|"					\
		${WRKSRC}/etc/${sc}
. endfor
	${REINPLACE_CMD} -e "s|?ASTER_ROOT?|${LOCALBASE}/aster|"		\
		-e 's|?HOME_PYTHON?|${PYTHONBASE}|'				\
		-e 's|?ASRUN_SITE_PKG?|${PREFIX}/${LINSTDIR}/ASTK_SERV|'	\
		-e 's|?PYTHON_EXE?|${PYTHON_CMD}|'				\
		-e 's|?HOME_MED?|${LOCALBASE}|'					\
		-e 's|?HOME_HDF?|${LOCALBASE}|'					\
		-e "s|?WISH_EXE?|${WISH}|"					\
		${WRKSRC}/etc/profile.sh
. for libs in ${S_PYLIBS}
	${REINPLACE_CMD} -e "s|/opt/aster/NEW9|${aster_dir}|"			\
		 -e "s|/opt/aster/NEW10|${aster_dir}|"				\
		-e "s|/opt/aster/ASTK|${inst_dir}|"				\
		-e "s|/opt/aster/etc|${LOCALBASE}/aster/etc|"			\
		-e "s|/usr/bin/editor|${WITH_ED}|"				\
		-e "s|/usr/bin/nedit2|${WITH_ED}|"				\
		-e "s|/usr/bin/nedit|${WITH_ED}|"				\
		-e "s|/usr/bin/xterm|${LOCALBASE}/bin/xterm|"			\
		-e "s|/opt/aster|${aster_dir}|" ${WRKSRC}/${libs}
. endfor
. if defined(WITH_PBS)
.   for cf in etc/asrun unittest/datafiles/config_serveurs
	${REINPLACE_CMD} -e "s|batch : non|batch : oui|"			\
		${WRKSRC}/${cf}
.   endfor
. endif
. if defined(MAKE_JOBS_NUMBER) && ! defined(PACKAGE_BUILDING)
	${REINPLACE_CMD}	\
		-e "s|%%MAKE_JOBS_NUMBER%%|self.Shell('${ECHO_CMD} ${MAKE_JOBS_NUMBER}', mach, user)|" \
		${WRKSRC}/asrun/system.py
. else
	${REINPLACE_CMD} -e 's|%%MAKE_JOBS_NUMBER%%|1|'	${WRKSRC}/asrun/system.py
. endif
	${REINPLACE_CMD} -e 's|bash|${SHIA}|' ${WRKSRC}/asrun/system_command.py
. for sh in ${BASH2RC}
	${REINPLACE_CMD} -e 's|/bin/bash|${SHELL_INSTALL_ASTER}|' ${WRKSRC}/${sh}
. endfor
	${REINPLACE_CMD} -e 's|/usr/bin/|${LOCALBASE}/bin/|;s|LINUX|FREEBSD|'	\
		${WRKSRC}/asrun/core/configuration.py
.else
# CLIENT_SEUL
. for scripts in ${C_SCRIPTS}
	${REINPLACE_CMD} -e "s|?SHELL_EXECUTION?|${SHELL_INSTALL_ASTER}|"	\
		-e "s|?ASTER_ROOT?|${PREFIX}/aster|"				\
		-e "s|wish|${WISH}|;s|%%inst_dir%%|${inst_dir}|"		\
		${WRKSRC}/${scripts}
. endfor
	${REINPLACE_CMD} -e "s|?vaster?|${vaster}|"				\
		-e "s|?TOOLS_DIR?|${tools_dir}|" ${conf_dir}/outils
	${REINPLACE_CMD} -e "s#?HOME_ASTK?#${inst_dir}#"			\
		-e "s#?TERMINAL?#${LOCALBASE}/bin/xterm#"			\
		-e "s#?FULL_SERVER_NAME?#${SERVER_NAME}#"			\
		-e "s#?SERVER_NAME?#${HOST_NAME}#"				\
		-e "s#?ASTER_ROOT?#${PREFIX}/aster#"				\
		-e "s#?EDITOR?#${WITH_ED}#" ${conf_dir}/config_serveurs
	${REINPLACE_CMD} -e "s#?TERMINAL?#${LOCALBASE}/bin/xterm#"		\
		-e "s#?ASTER_VERSION?#${ASTER_VER}#"				\
		-e "s#langue : ENG#langue : ${ASTK_LANG}#"			\
		-e "s#?DOMAIN_NAME?#${DOMAIN_NAME}#"				\
		-e "s#?EDITOR?#${WITH_ED}#" ${conf_dir}/prefs
	${REINPLACE_CMD} -e "s|%%LOCALBASE%%|${LOCALBASE}|g"			\
		${WRKSRC}/lib/tkselecteur.tcl
	${REINPLACE_CMD} -e "s|%%unamesm%%|${unamesm}|"				\
		${WRKSRC}/lib/init.tcl
. for sh in ${BASH2RC2}
	${REINPLACE_CMD} -e 's|/bin/bash|${SHELL_INSTALL_ASTER}|' ${WRKSRC}/${sh}
. endfor
.endif
.for sh in ${BASH2RC3}
	${REINPLACE_CMD} -e 's|/bin/bash|${SHELL_INSTALL_ASTER}|' ${WRKCONF}/${sh}
.endfor

do-install:
	${MKDIR} ${STAGEDIR}${inst_dir}
	${CP} -R ${WRKSRC} ${STAGEDIR}${inst_dir}
.if !defined(CLIENT_SEUL)
	${MKDIR} ${STAGEDIR}${inst_dir}/ASTK_SERV/etc/codeaster/astkrc	\
		${STAGEDIR}/${ETCDIR}
	${TOUCH} ${STAGEDIR}${inst_dir}/ASTK_SERV/etc/codeaster/astkrc/.keep_me
	${CP} -R ${WRKSRC}/etc/* ${STAGEDIR}${ETCDIR}
	(cd ${STAGEDIR}${PREFIX} \
		 && ${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		 -d ${PREFIX} -f aster)
	(cd ${STAGEDIR}${PREFIX} \
		 && ${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		 -d ${PREFIX} -f aster)
	${MV} ${STAGEDIR}${ETCDIR}/profile.sh ${STAGEDIR}${ETCDIR}/profile_astk.sh
. if defined(WITH_MPI)
	${ECHO_CMD} "localhost" > ${STAGEDIR}${PREFIX}/aster/aster-mpihosts
. endif
.endif

.include "${.CURDIR}/../../french/aster/bsd.aster.mk"
.include <bsd.port.post.mk>
