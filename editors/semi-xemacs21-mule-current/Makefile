# New ports collection makefile for:	semi-current for xemacs-mule
# Version required:	1.13.3
# Date created:		25 July 1999
# Whom:			Shigeyuki FUKUSHIMA <shige@FreeBSD.org>
#
# $FreeBSD$
#

MAINTAINER=	shige@FreeBSD.org

# This is a slave port.
PORTCLASS=	slave

MASTERDIR=	${.CURDIR}/../../editors/semi-emacs-current

# emacs port setup
EMACS_NAME=	xemacs
EMACS_PORT=	xemacs-mule
EMACS_VER=	21.1.6
EMACS_PACKAGESDIR=	lib/${EMACS_NAME}/${EMACS_NAME}-packages

# how to make and install
ALL_TARGET=	package
INSTALL_TARGET=	install-package

# RUN_DEPENDS port name's suffix is '-common'.
HAVE_COMMON_PORT=	YES

# use pkg/* files in ${.CURDIR}
PKGDIR=		${.CURDIR}/pkg

# package info manifest
MANIFEST=	MANIFEST.semi
# package documents
SEMIDOCDIR=	${EMACS_PACKAGESDIR}/lisp/semi

.include <${MASTERDIR}/Makefile>
