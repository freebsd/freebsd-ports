# New ports collection makefile for:	apel for xemacs-mule
# Version required:	9.22
# Date created:		13 June 1999
# Whom:			Shigeyuki FUKUSHIMA <shige@FreeBSD.org>
#
# $FreeBSD$
#

MAINTAINER=	shige@FreeBSD.org

# This is a slave port.
PORTCLASS=	slave

MASTERDIR=	${.CURDIR}/../../editors/apel-emacs

# emacs port setup
EMACS_NAME=	xemacs
EMACS_PORT=	xemacs-mule
EMACS_VER=	21.1.8
EMACS_LIBDIR=	lib/${EMACS_NAME}
EMACS_PACKAGESDIR=	${EMACS_LIBDIR}/site-packages
# packages-subdirectories which this port requires
EMACS_PACKAGES_SUBDIRS=	lisp pkginfo

# how to install
ALL_TARGET=	package
INSTALL_TARGET=	install-package

# RUN_DEPENDS port name's suffix is '-common'.
HAVE_COMMON_PORT=	YES

# use pkg/* files in ${.CURDIR}
PKGDIR=		${.CURDIR}/pkg

# package info manifest
MANIFEST=	MANIFEST.apel
# package documents
APELDOCDIR=	${EMACS_PACKAGESDIR}/lisp/apel

.if defined(PARALLEL_PACKAGE_BUILD)
FORBIDDEN=	hang
.endif

.include <${MASTERDIR}/Makefile>
