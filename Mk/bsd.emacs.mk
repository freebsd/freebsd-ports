#
#	$FreeBSD: /tmp/pcvs/ports/Mk/bsd.emacs.mk,v 1.1 2000-05-06 10:45:34 asami Exp $
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


# Emacs-19.x
.if (${EMACS_PORT_NAME} == "emacs19")
EMACS_NAME=		emacs
EMACS_VER=		19.34
EMACS_MAJOR_VER=	19
EMACS_LIBDIR?=		share/${EMACS_NAME}
EMACS_LIBDIR_WITH_VER?=	share/${EMACS_NAME}/${EMACS_VER}

# Emacs-20.x
.elif (${EMACS_PORT_NAME} == "emacs20")
EMACS_NAME=		emacs
EMACS_VER=		20.6
EMACS_MAJOR_VER=	20
EMACS_LIBDIR?=		share/${EMACS_NAME}
EMACS_LIBDIR_WITH_VER?=	share/${EMACS_NAME}/${EMACS_VER}

# Mule-19.x
.elif (${EMACS_PORT_NAME} == "mule19")
EMACS_NAME=		mule
EMACS_VER=		19.34
EMACS_MAJOR_VER=	19
EMACS_LIBDIR?=		share/${EMACS_NAME}
EMACS_LIBDIR_WITH_VER?=	share/${EMACS_NAME}/${EMACS_VER}

# XEmacs-19.x
.elif (${EMACS_PORT_NAME} == "xemacs19")
EMACS_NAME=		xemacs
EMACS_VER=		19.16
EMACS_MAJOR_VER=	19
EMACS_LIBDIR?=		lib/${EMACS_NAME}
EMACS_LIBDIR_WITH_VER?=	lib/${EMACS_NAME}-${EMACS_VER}

# XEmacs-20.x
.elif (${EMACS_PORT_NAME} == "xemacs20")
EMACS_NAME=		xemacs
EMACS_VER=		20.4
EMACS_MAJOR_VER=	20
EMACS_LIBDIR?=		lib/${EMACS_NAME}
EMACS_LIBDIR_WITH_VER?=	lib/${EMACS_NAME}-${EMACS_VER}

# XEmacs-21.x
.elif (${EMACS_PORT_NAME} == "xemacs21")
EMACS_NAME=		xemacs
EMACS_VER=		21.1.9
EMACS_MAJOR_VER=	21
EMACS_LIBDIR?=		lib/${EMACS_NAME}
EMACS_LIBDIR_WITH_VER?=	lib/${EMACS_NAME}-${EMACS_VER}

# XEmacs-21.x with Mule
.elif (${EMACS_PORT_NAME} == "xemacs21-mule")
EMACS_NAME=		xemacs
EMACS_VER=		21.1.9
EMACS_MAJOR_VER=	21
EMACS_LIBDIR?=		lib/${EMACS_NAME}
EMACS_LIBDIR_WITH_VER?=	lib/${EMACS_NAME}-${EMACS_VER}
.else
.BEGIN:
	@${ECHO} "Error: Bad value of EMACS_PORT_NAME: ${EMACS_PORT_NAME}."
	@${ECHO} "Valid values are:"
	@${ECHO} "	Emacs  family: emacs19 mule19 emacs20"
	@${ECHO} "	XEmacs family: xemacs19 xemacs20 xemacs21 xemacs21-mule"
	@${FALSE}
.endif


#
# Common Definitions
#

# emacsen command-line filename
EMACS_CMD?=			${PREFIX}/bin/${EMACS_NAME}-${EMACS_VER}

# emacsen libdir without ${PREFIX}
EMACS_SITE_LISPDIR?=		${EMACS_LIBDIR}/site-lisp
EMACS_VERSION_SITE_LISPDIR?=	${EMACS_LIBDIR_WITH_VER}/site-lisp
