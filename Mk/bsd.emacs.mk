#
#	$FreeBSD: /tmp/pcvs/ports/Mk/bsd.emacs.mk,v 1.13 2001-02-05 07:51:50 shige Exp $
#
#	bsd.emacs.mk - 19990829 Shigeyuki Fukushima.
#

Emacs_Include=			bsd.emacs.mk
Emacs_Include_MAINTAINER=	shige@FreeBSD.org

#
# This file for ports which depend on emacs family.
# Define EMACS_PORT_NAME variable before bsd.port.[pre.]mk
# and it will automatically include this file.
#
# This file exports the following common variables:
#
# EMACS_NAME:
#		emacsen's command-line basename.
#		ex.) "emacs" when emacsen is a emacs-20.6.
#
# EMACS_VER:
#		emacsen's version.
#		ex.) "20.6" when emacsen is a emacs-20.6.
#
# EMACS_MAJOR_VER:
#		emacsen's major version.
#		ex.) "20" when emacsen is a emacs-20.6.
#
# EMACS_LIBDIR:
#		emacsen's library directory name without ${PREFIX}.
#		ex.) "share/emacs" when emacsen is a emacs-20.6.
#
# EMACS_LIBDIR_WITH_VER:
#		emacsen's version specific library directory name 
#		without ${PREFIX}.
#		ex.) "share/emacs/20.6" when emacsen is a emacs-20.6.
#
# EMACS_CMD:
#		emacsen's command-line filename. (full path)
#		ex.) "/usr/local/bin/emacs-20.6" when emacsen is a 
#		     emacs-20.6 and ${PREFIX} is "/usr/local".
#
# EMACS_SITE_LISPDIR:
#		emacsen's site-lisp directory name without ${PREFIX}.
#		ex.) "share/emacs/site-lisp" when emacsen is a emacs-20.6.
#
# EMACS_VERSION_SITE_LISPDIR:
#		emacsen's version specific site-lisp directory name
#		without	${PREFIX}.
#		ex.) "share/emacs/20.6/site-lisp" when emacsen is a
#		emacs-20.6.
#
# EMACS_NO_BUILD_DEPENDS:
#		If set "YES" to this variable, port does not 
#		build-depend on EMACS_PORT_NAME's emacsen.
#
# EMACS_NO_RUN_DEPENDS:
#		If set "YES" to this variable, port does not 
#		run-depend on EMACS_PORT_NAME's emacsen.
#


# Emacs-19.x
.if (${EMACS_PORT_NAME} == "emacs")
EMACS_NAME=		emacs
EMACS_VER=		19.34
EMACS_MAJOR_VER=	19
EMACS_LIBDIR?=		share/${EMACS_NAME}
EMACS_LIBDIR_WITH_VER?=	share/${EMACS_NAME}/${EMACS_VER}
EMACS_PORTSDIR=		${PORTSDIR}/editors/emacs
EMACS_COMMON_PORT=	NO
EMACS_HAS_MULE=		NO

# Emacs-20.x
.elif (${EMACS_PORT_NAME} == "emacs20")
EMACS_NAME=		emacs
EMACS_VER=		20.7
EMACS_MAJOR_VER=	20
EMACS_LIBDIR?=		share/${EMACS_NAME}
EMACS_LIBDIR_WITH_VER?=	share/${EMACS_NAME}/${EMACS_VER}
EMACS_PORTSDIR=		${PORTSDIR}/editors/emacs20
EMACS_COMMON_PORT=	NO
EMACS_HAS_MULE=		YES

# Mule-19.x
.elif (${EMACS_PORT_NAME} == "mule")
EMACS_NAME=		mule
EMACS_VER=		19.34
EMACS_MAJOR_VER=	19
EMACS_LIBDIR?=		share/${EMACS_NAME}
EMACS_LIBDIR_WITH_VER?=	share/${EMACS_NAME}/${EMACS_VER}
EMACS_PORTSDIR=		${PORTSDIR}/editors/mule
EMACS_COMMON_PORT=	YES
EMACS_HAS_MULE=		YES

# XEmacs-19.x
.elif (${EMACS_PORT_NAME} == "xemacs")
EMACS_NAME=		xemacs
EMACS_VER=		19.16
EMACS_MAJOR_VER=	19
EMACS_LIBDIR?=		lib/${EMACS_NAME}
EMACS_LIBDIR_WITH_VER?=	lib/${EMACS_NAME}-${EMACS_VER}
EMACS_PORTSDIR=		${PORTSDIR}/editors/xemacs
EMACS_COMMON_PORT=	NO
EMACS_HAS_MULE=		NO
# subdirectory of emacs core elisp files
EMACS_CORE_SUBDIR=	prim

# XEmacs-20.x
.elif (${EMACS_PORT_NAME} == "xemacs20")
EMACS_NAME=		xemacs
EMACS_VER=		20.4
EMACS_MAJOR_VER=	20
EMACS_LIBDIR?=		lib/${EMACS_NAME}
EMACS_LIBDIR_WITH_VER?=	lib/${EMACS_NAME}-${EMACS_VER}
EMACS_PORTSDIR=		${PORTSDIR}/editors/xemacs20
EMACS_COMMON_PORT=	NO
EMACS_HAS_MULE=		NO
# subdirectory of emacs core elisp files
EMACS_CORE_SUBDIR=	prim

# XEmacs-21.x
.elif (${EMACS_PORT_NAME} == "xemacs21")
EMACS_NAME=		xemacs
EMACS_VER=		21.1.14
EMACS_MAJOR_VER=	21
EMACS_LIBDIR?=		lib/${EMACS_NAME}
EMACS_LIBDIR_WITH_VER?=	lib/${EMACS_NAME}-${EMACS_VER}
EMACS_PORTSDIR=		${PORTSDIR}/editors/xemacs21
EMACS_COMMON_PORT=	NO
EMACS_HAS_MULE=		NO

# XEmacs-21.x with Mule
.elif (${EMACS_PORT_NAME} == "xemacs21-mule")
EMACS_NAME=		xemacs
EMACS_VER=		21.1.14
EMACS_MAJOR_VER=	21
EMACS_LIBDIR?=		lib/${EMACS_NAME}
EMACS_LIBDIR_WITH_VER?=	lib/${EMACS_NAME}-${EMACS_VER}
EMACS_PORTSDIR=		${PORTSDIR}/editors/xemacs21-mule
EMACS_COMMON_PORT=	YES
EMACS_HAS_MULE=		YES

.else
.BEGIN:
	@${ECHO} "Error: Bad value of EMACS_PORT_NAME: ${EMACS_PORT_NAME}."
	@${ECHO} "Valid values are:"
	@${ECHO} "	Emacs  family: emacs mule emacs20"
	@${ECHO} "	XEmacs family: xemacs xemacs20 xemacs21 xemacs21-mule"
	@${FALSE}
.endif


#
# Common Definitions
#

# emacsen command-line filename
EMACS_CMD?=			${LOCALBASE}/bin/${EMACS_NAME}-${EMACS_VER}
# emacsen core elisp filename
EMACS_CORE_DIR=			${EMACS_LIBDIR_WITH_VER}/lisp/${EMACS_CORE_SUBDIR}
EMACS_COREEL=			${LOCALBASE}/${EMACS_CORE_DIR}/startup.el

# emacsen libdir without ${LOCALBASE}
EMACS_SITE_LISPDIR?=		${EMACS_LIBDIR}/site-lisp
EMACS_VERSION_SITE_LISPDIR?=	${EMACS_LIBDIR_WITH_VER}/site-lisp

# build&run-dependency
EMACS_NO_BUILD_DEPENDS?=	NO
EMACS_NO_RUN_DEPENDS?=		NO
.if (${EMACS_NO_BUILD_DEPENDS} == "NO")
BUILD_DEPENDS+=		${EMACS_CMD}:${EMACS_PORTSDIR}
.endif
.if (${EMACS_NO_RUN_DEPENDS} == "NO")
.if defined(EMACS_COMMON_PORT) && (${EMACS_COMMON_PORT} == "YES")
RUN_DEPENDS+=	${EMACS_COREEL}:${EMACS_PORTSDIR}-common
.else
RUN_DEPENDS+=	${EMACS_CMD}:${EMACS_PORTSDIR}
.endif
.endif

# environments for build
MAKE_ARGS+=	EMACS=${EMACS_CMD} XEMACS=${EMACS_CMD}
SCRIPTS_ENV+=	EMACS_LIBDIR=${EMACS_LIBDIR} \
		EMACS_VER=${EMACS_VER} \
		EMACS_LIBDIR_WITH_VER=${EMACS_LIBDIR_WITH_VER}
# pkg/PLIST substrings
PLIST_SUB+=	EMACS_LIBDIR=${EMACS_LIBDIR} \
		EMACS_VER=${EMACS_VER} \
		EMACS_LIBDIR_WITH_VER=${EMACS_LIBDIR_WITH_VER}
