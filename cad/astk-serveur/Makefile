# New ports collection makefile for:	ASTK
# Date created:		Thu Jul 09 2003
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	astk
PORTVERSION=	1.2.2
CATEGORIES=	cad
MASTER_SITES=	http://www.code-aster.org/FICHIERS/
.if !defined(CLIENT_SEUL)
PKGNAMESUFFIX=	-serveur
.else
PKGNAMESUFFIX=	-client
.endif
DISTNAME=	aster-full-src-${ASTER_VER}-5

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

# There exists a "logical" RUN_DEPENDS towards french/aster and french/eficas
# for the server part, but it is not set to avoid circular dependences.
RUN_DEPENDS+=	${SHELL_INSTALL_ASTER}:${PORTSDIR}/shells/${SHIADEP}
.if defined(WITH_PBS) && !defined(CLIENT_SEUL)
RUN_DEPENDS+=	${LOCALBASE}bin/pbs_tclsh:${PORTSDIR}/misc/pbs
.endif

USE_PYTHON=	yes
NO_BUILD=	yes
USE_REINPLACE=	yes
REINPLACE_ARGS=	-i ""

EXTDIR=		${WRKDIR}/aster-src-${ASTER_VER}/SRC
PKGMESSAGE=	${WRKDIR}/pkg-message
LINSTDIR=	aster/ASTK
inst_dir=	${PREFIX}/${LINSTDIR}
aster_dir=	${LOCALBASE}/aster/${vaster}
S_SCRIPTS=	bin/as_actu bin/as_del bin/as_edit bin/as_exec bin/as_info	\
		bin/as_serv bin/as_tail bin/tool_stanley lib/sub_script
S_PYLIBS=	as_config.py as_system.py
C_SCRIPTS=	bin/astk bin/bsf
tools_dir=	${LOCALBASE}/aster/outils
conf_dir=	${WRKSRC}/lib/ASTK/astkrc

.include <bsd.port.pre.mk>

.if !defined(CLIENT_SEUL)
WRKSRC=		${EXTDIR}/astk-${PORTVERSION}/ASTK_SERV
PATCHDIR=	${MASTERDIR}/files
PLIST_SUB=	ASTKDIR=${LINSTDIR}/ASTK_SERV SERV="" CLIENT="@comment "		\
		vaster=${vaster}
.else
RUN_DEPENDS+=	xterm:${X_CLIENTS_PORT}	\
		wish${TK_VER}:${PORTSDIR}/x11-toolkits/tk${SHORT_TK_VER}
WRKSRC=		${EXTDIR}/astk-${PORTVERSION}/ASTK_CLIENT
PATCHDIR=	${MASTERDIR}/files.client
PLIST_SUB=	ASTKDIR=${LINSTDIR}/ASTK_CLIENT SERV="@comment " CLIENT="" vaster=""	\
		BWidget_DIR=${LINSTDIR}/ASTK_CLIENT/share/BWidget-${BWidget_VER}
.endif
FILESDIR=	${PATCHDIR}

SLAVEDIRS=	cad/astk-client

TK_VER?=	8.4
TCL_VER?=	${TK_VER}
SHORT_TK_VER=	${TK_VER:S/.//}
BWidget_VER=	1.7.0

ASTER_VER=	7.4.0
vaster=		STA${ASTER_VER:S/.0//}

GIBI=		gibi2000

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
WITH_ED=	gvim${WRKSRC}/bin/as_exec.orig
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

unamesm=	${OPSYS} ${ARCH}
v_ifdef=	${OPSYS:U}
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

post-extract:
	@(cd ${EXTDIR} && \
	${TAR} xfz ${EXTDIR}/astk-${PORTVERSION}-1.noarch.tar.gz)

post-patch:
.if !defined(CLIENT_SEUL)
	@${RM} ${WRKSRC}/conf/config.orig ${WRKSRC}/bin/as_exec.orig			\
		${WRKSRC}/bin/as_serv.orig ${WRKSRC}/lib/as_config.py.orig
.else
	@${RM} ${WRKSRC}/lib/ASTK/init.tcl.orig	${WRKSRC}/lib/ASTK/astkrc/outils.orig	\
		${WRKSRC}/share/tkselecteur.tcl.orig
.endif

do-configure:
.if !defined(CLIENT_SEUL)
. if ${SHIA} == "zsh"
	@${REINPLACE_CMD} -e 's|#set -o SH_WORD_SPLIT|set -o SH_WORD_SPLIT|'	\
		${WRKSRC}/bin/as_serv
. endif
	@${REINPLACE_CMD} -e 's#?PYTHON_EXE?#${PYTHON_CMD}#'			\
		-e 's#?MAXCMDLEN?#16384#' ${WRKSRC}/bin/as_run
. for scripts in ${S_SCRIPTS}
	@${REINPLACE_CMD} -e "s#?SHELL_EXECUTION?#${SHELL_INSTALL_ASTER}#"	\
	-e "s#?HOME_ASTK?#${inst_dir}#" ${WRKSRC}/${scripts}
. endfor
	@${REINPLACE_CMD} -e "s#?IFDEF?#${v_ifdef}#g"				\
	-e "s#?ASTER_ROOT?#${LOCALBASE}/aster#g"				\
	-e "s#?EDITOR?#${WITH_ED}#g"						\
	-e "s#?NODE?#${HOST_NAME}#"						\
	-e "s#?ASTER_VERSION?#${ASTER_VER}#"					\
	-e "s#?vaster?#${vaster}#"						\
	-e "s#LOCALBASE#${LOCALBASE}#"						\
	-e "s#%%v_ifdef%%#${v_ifdef}#" ${WRKSRC}/conf/config
.for libs in ${S_PYLIBS}
	@${REINPLACE_CMD} -e "s#/opt/aster/NEW7#${aster_dir}#" ${WRKSRC}/lib/${libs}
. endfor
. if defined(WITH_PBS)
	@${REINPLACE_CMD} -e "s|batch : non|batch : oui|"			\
		${WRKSRC}/conf/config
. endif
	@${REINPLACE_CMD} -e 's|?HOME_PYTHON?|${PYTHONBASE}|'			\
		-e 's|?ASTER_ROOT?|${aster_dir}|'				\
		-e 's|?HOME_MED?|${LOCALBASE}|'					\
		-e 's|?HOME_HDF?|${LOCALBASE}|' ${WRKSRC}/conf/aster_profile.sh
.else
# CLIENT_SEUL
. for scripts in ${C_SCRIPTS}
	@${REINPLACE_CMD} -e "s#?SHELL_EXECUTION?#${SHELL_INSTALL_ASTER}#"	\
	-e "s#?HOME_ASTK?#${inst_dir}#"						\
	-e "s#?WISH_EXE?#wish${TK_VER}#" ${WRKSRC}/${scripts}
. endfor
	@${REINPLACE_CMD} -e "s#?HOME_ASTK?#${inst_dir}#"			\
		-e "s#GIBI#${GIBI}#"						\
		-e "s#?vaster?#${vaster}#"					\
		-e "s#?TOOLS_DIR?#${tools_dir}#" ${conf_dir}/outils
	@${REINPLACE_CMD} -e "s#?HOME_ASTK?#${inst_dir}#"			\
		-e "s#?XTERM?#${X11BASE}/bin/xterm#"				\
		-e "s#?FULL_SERVER_NAME?#${SERVER_NAME}#"			\
		-e "s#?SERVER_NAME?#${HOST_NAME}#"				\
		-e "s#?EDITOR?#${WITH_ED}#" ${conf_dir}/config_serveurs
	@${REINPLACE_CMD} -e "s#?XTERM?#${X11BASE}/bin/xterm#"			\
		-e "s#?ASTER_VERSION?#${ASTER_VER}#"				\
		-e "s#langue : ENG#langue : ${ASTK_LANG}#"			\
		-e "s#?DOMAIN_NAME?#${DOMAIN_NAME}#"				\
		-e "s#?EDITOR?#${WITH_ED}#" ${conf_dir}/prefs
	@${REINPLACE_CMD} -e "s#%%LOCALBASE%%#${LOCALBASE}#g"			\
		${WRKSRC}/share/tkselecteur.tcl
	@${REINPLACE_CMD} -e "s#%%unamesm%%#${unamesm}#"			\
		${WRKSRC}/lib/ASTK/init.tcl
.endif

do-install:
	${MKDIR} ${inst_dir}
	${CP} -R ${WRKSRC} ${inst_dir}
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${inst_dir}/ASTK_SERV/lib
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${inst_dir}/ASTK_SERV/lib

post-install:
	@${ECHO_MSG}
	@${SED} -e "s#%%inst_dir%%#${inst_dir}#;s#%%tools_dir%%#${tools_dir}#"	\
		${FILESDIR}/pkg-message.in > ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.post.mk>
