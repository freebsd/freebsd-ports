# New ports collection makefile for:	flim for xemacs-mule
# Version required:	1.9.2
# Date created:		25 July 1999
# Whom:			Shigeyuki FUKUSHIMA <shige@FreeBSD.org>
#
# $FreeBSD$
#

MAINTAINER=	shige@FreeBSD.org

# This is a slave port.
PORTCLASS=	slave

MASTERDIR=	${.CURDIR}/../../editors/flim-emacs

# emacs port setup
EMACS_NAME=	xemacs
EMACS_PORT=	xemacs-mule
EMACS_VER=	21.1.6
EMACS_PACKAGESDIR=	lib/${EMACS_NAME}/${EMACS_NAME}-packages

# how to make and install
ALL_TARGET=	package
INSTALL_TARGET=	install-package

# RUN_DEPENDS port name's suffix is '-common'.
HAS_COMMON_PORT=	YES

# whether emacs has mule feature
HAS_MULE=		YES

# whether building info files by emacs or makeinfo
BUILD_INFO_BY_EMACS=	YES
# texinfo packages
BUILD_DEPENDS+=	${PREFIX}/${EMACS_PACKAGESDIR}/lisp/texinfo/texinfo.el:${PORTSDIR}/editors/xemacs-sumo-packages

# use pkg/* files in ${.CURDIR}
PKGDIR=		${.CURDIR}/pkg

# package info manifest
MANIFEST=	MANIFEST.flim
# package documents
FLIMDOCDIR=	${EMACS_PACKAGESDIR}/lisp/flim

.include <${MASTERDIR}/Makefile>
