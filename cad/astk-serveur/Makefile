# New ports collection makefile for:	ASTK
# Date created:		Thu Jul 09 2003
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	astk
PORTVERSION=	1.0.21
PORTREVISION=	1
CATEGORIES=	cad tk84
MASTER_SITES=	http://www.code-aster.org/FICHIERS/
.if !defined(CLIENT_SEUL)
PKGNAMESUFFIX=	-serveur
.else
PKGNAMESUFFIX=	-client
.endif
DISTNAME=	aster-src-${ASTER_VER}
EXTRACT_SUFX=	.tar

MAINTAINER=	ports@FreeBSD.org
COMMENT?=	Graphical interface for Code_Aster (server side)

#-----------------------------------------------------------------------
# You may define these options:
#
# - WITH_ZSH or WITH_BASH or WITH_KSH: select a shell among
#			zsh (default), bash or ksh;
# - WITH_ED: select an editor accepting '-display' (e.g. gvim, nedit);
# - WITH_PBS: PBS (batch scheduler) support is experimental.
#
#-----------------------------------------------------------------------

.include <bsd.port.pre.mk>

# There exists a "logical" RUN_DEPENDS towards french/aster and french/eficas
# for the server part, but it is not set to avoid circular dependences.
RUN_DEPENDS=	${LOCALBASE}/lib/Tktable${TKTAB_VER}:${PORTSDIR}/x11-toolkits/tktable	\
		${SHELL_INSTALL_ASTER}:${PORTSDIR}/shells/${SHIADEP}
.if defined(WITH_PBS) && !defined(CLIENT_SEUL)
RUN_DEPENDS+=	${LOCALBASE}bin/pbs_tclsh:misc/pbs
.endif

EXTRACT_CMD=	${TAR}
EXTRACT_BEFORE_ARGS=	-xf
EXTRACT_AFTER_ARGS=	# empty
NO_BUILD=	yes
USE_REINPLACE=	yes
REINPLACE_ARGS=	-i ""

EXTDIR=		${WRKDIR}/aster-${ASTER_VER}.src
.if !defined(CLIENT_SEUL)
WRKSRC=		${EXTDIR}/ASTK_SERV
PATCHDIR=	${MASTERDIR}/files
PLIST_SUB=	SERV="" CLIENT="@comment " vaster=${vaster}
.else
WRKSRC=		${EXTDIR}/ASTK_CLIENT
PATCHDIR=	${MASTERDIR}/files.client
PLIST_SUB=	SERV="@comment " CLIENT="" vaster=""
PKGMESSAGE=	${PKGDIR}/pkg-message.client
.endif

SLAVEDIRS=	cad/astk-client

TK_VER?=	8.4
TCL_VER?=	${TK_VER}

TKTAB_VER?=	2.8
ASTER_VER=	7.2.0-2
vaster=		STA${ASTER_VER}

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
.if exists(${X11BASE}/bin/nedit)
WITH_ED=	nedit
RUN_DEPENDS+=	${X11BASE}/bin/nedit:${PORTSDIR}/editors/nedit
.else
WITH_ED=	gvim
RUN_DEPENDS+=	${LOCALBASE}/bin/gvim:${PORTSDIR}/editors/vim
.endif
.endif

inst_dir?=	${PREFIX}/ASTK
aster_dir=	${LOCALBASE}/aster/${vaster}
S_SCRIPTS=	bin/as_actu bin/as_del bin/as_edit bin/as_exec bin/as_info	\
		bin/as_serv bin/as_tail bin/tool_stanley lib/sub_script
C_SCRIPTS=	bin/astk bin/asjob bin/bsf
tools_dir=	${aster_dir}/outils
conf_dir=	${WRKSRC}/lib/ASTK/astkrc
SERVER_NAME!=	${UNAME} -n
unames!=	${UNAME} -s
unamesm!=	${UNAME} -sm
v_ifdef=	${unames:U}
SHELL_INSTALL_ASTER=	${LOCALBASE}/bin/${SHIA}
gzip!=		dirname `${WHICH} ${GZIP_CMD}`

.if defined(LANG) && ${LANG:Mfr*} != ""
ASTK_LANG=	FR
.else
ASTK_LANG=	ENG
.endif

post-extract:
	@(cd ${EXTDIR} && \
	${TAR} xfz ${EXTDIR}/astk.tar.gz)
.if !defined(CLIENT_SEUL)
	@(cd ${EXTDIR} && \
	${TAR} xf ASTK_SERV.tar)
.else
	@(cd ${EXTDIR} && \
	${TAR} xf ASTK_CLIENT.tar)
.endif

post-patch:
.if !defined(CLIENT_SEUL)
.for scripts in ${S_SCRIPTS}
	@${REINPLACE_CMD} -e "s#SHELL_EXECUTION#${SHELL_INSTALL_ASTER}#g"	\
	-e "s#HOME_ASTK#${inst_dir}#"						\
	-e "s#HOME_TKTABLE#${LOCALBASE}/lib/Tktable${TKTAB_VER}#"		\
	-e "s#HOME_TCL_TK#${LOCALBASE}#"					\
	-e "s#TCLSH_BIN#tclsh${TCL_VER}#"					\
	-e "s#WISH_BIN#wish${TK_VER}#" ${WRKSRC}/${scripts}
.endfor
	@${REINPLACE_CMD} -e "s#IFDEF#${v_ifdef}#g"				\
	-e "s#/aster#${aster_dir}#g"						\
	-e "s#EDITOR#${WITH_ED}#g"						\
	-e "s#TCL_TK_VERSION#${TK_VER}#g"					\
	-e "s#HOME_PYTHON#${python_dir}#g"					\
	-e "s#/bin/sh#${SHELL_INSTALL_ASTER}#g"					\
	-e "s#NODE#${SERVER_NAME}#"						\
	-e "s#%%vaster%%#${vaster}#"						\
	-e "s#LOCALBASE#${LOCALBASE}#"						\
	-e "s|#%%v_ifdef%%|${v_ifdef}|" ${WRKSRC}/conf/config
	@${RM} ${WRKSRC}/conf/config.orig
	@${CP} ${WRKSRC}/conf/config.NEW7 ${WRKSRC}/conf/config.${vaster}
	@${REINPLACE_CMD} -e "s#/aster#${aster_dir}#"				\
	-e "s#/NEW7##"								\
	-e "s#ans debug binairies#and debug binaries#"				\
		${WRKSRC}/conf/config.${vaster}
.if defined(WITH_PBS)
	@${REINPLACE_CMD} -e "s|batch : non|batch : oui|"			\
	-e "s|^batch_nom|#batch_nom|"						\
	-e "s|^batch_ini|#batch_ini|"						\
	-e "s|^batch_sub|#batch_sub|"						\
	-e "s|^batch_jid|#batch_jid|"						\
	-e "s|^batch_job|#batch_job|"						\
	-e "s|^batch_kil|#batch_kil|"						\
	-e "s|#batch_nom : PBS|batch_nom : PBS|"				\
	-e "s|#batch_sub : /local/openpbs-2.3.16/bin/qsub|batch_sub : ${LOCALBASE}/bin/qsub|" \
	-e "s|#batch_jid : PBS_JOBID|batch_jid : PBS_JOBID|"			\
	-e "s|#batch_job : /local/openpbs-2.3.16/bin/qstat|batch_job : ${LOCALBASE}/bin/qstat" \
	-e "s|#batch_kil : /local/openpbs-2.3.16/bin/qdel|batch_kil : ${LOCALBASE}/bin/qdel"
		${WRKSRC}/conf/config
.endif
.else
# CLIENT_SEUL
.for scripts in ${C_SCRIPTS}
	@${REINPLACE_CMD} -e "s#SHELL_EXECUTION#${SHELL_INSTALL_ASTER}#g"	\
	-e "s#HOME_ASTK#${inst_dir}#"						\
	-e "s#HOME_TKTABLE#${LOCALBASE}/lib/Tktable${TKTAB_VER}#"		\
	-e "s#HOME_TCL_TK#${LOCALBASE}#"					\
	-e "s#TCLSH_BIN#tclsh${TCL_VER}#"					\
	-e "s#WISH_BIN#wish${TK_VER}#" ${WRKSRC}/${scripts}
.endfor
	@${REINPLACE_CMD} -e "s#HOME_ASTK#${inst_dir}#g"			\
		-e "s#TOOLS_DIR#${tools_dir}#" ${conf_dir}/outils
	@${REINPLACE_CMD} -e "s#HOME_ASTK#${inst_dir}#"				\
		-e "s#HOME_XTERM#${X11BASE}/bin#"				\
		-e "s#FULL_SERVER_NAME#${SERVER_NAME}#"				\
		-e "s#SERVER_NAME#${SERVER_NAME}#"				\
		-e "s#EDITOR#${WITH_ED}#" ${conf_dir}/config_serveurs
	@${REINPLACE_CMD} -e "s#HOME_XTERM#${X11BASE}/bin#"			\
		-e "s#VVV#${vaster}#"						\
		-e "s#langue : ENG#langue : ${ASTK_LANG}#"			\
		-e "s#EDITOR#${WITH_ED}#" ${conf_dir}/prefs
	@${REINPLACE_CMD} -e "s#%%LOCALBASE%%#${LOCALBASE}#g"			\
		${WRKSRC}/share/tkselecteur.tcl
	@${REINPLACE_CMD} -e "s#%%unamesm%%#${unamesm}#"			\
		${WRKSRC}/lib/ASTK/init.tcl
	@${RM} ${WRKSRC}/lib/ASTK/init.tcl.orig
	@${RM} ${WRKSRC}/share/tkselecteur.tcl.orig
	@${RM} ${WRKSRC}/lib/ASTK/astkrc/outils.orig
.endif

do-install:
	${MKDIR} ${inst_dir}
	${CP} -R ${WRKSRC} ${inst_dir}

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE} | ${SED} -e "s#%%inst_dir%%#${inst_dir}#"		\
			-e "s#%%tools_dir%%#${tools_dir}#"			\
			-e "s#%%ASTER_VER%%#${vaster}#"
	@${ECHO_MSG}

.include <bsd.port.post.mk>
