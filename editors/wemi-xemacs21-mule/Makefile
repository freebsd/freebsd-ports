# New ports collection makefile for:	wemi for xemacs-mule
# Version required:	1.13.4
# Date created:		25 July 1999
# Whom:			Shigeyuki FUKUSHIMA <shige@FreeBSD.org>
#
# $FreeBSD$
#

MAINTAINER=	shige@FreeBSD.org

# This is a slave port.
PORTCLASS=	slave

MASTERDIR=	${.CURDIR}/../../editors/wemi-emacs

# emacs port setup
EMACS_NAME=	xemacs
EMACS_PORT=	xemacs-mule
EMACS_VER=	21.1.8
EMACS_PACKAGESDIR=	lib/${EMACS_NAME}/site-packages
# packages-subdirectories which this port requires
EMACS_PACKAGES_SUBDIRS= info lisp man pkginfo

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
BUILD_DEPENDS+= ${PREFIX}/${EMACS_PACKAGESDIR}/../xemacs-packages/lisp/texinfo/texinfo.el:${PORTSDIR}/editors/xemacs-sumo-packages

# use pkg/* files in ${.CURDIR}
PKGDIR=		${.CURDIR}/pkg

# package info manifest
MANIFEST=	MANIFEST.semi
# package documents
WEMIDOCDIR=	${EMACS_PACKAGESDIR}/lisp/semi

.include <${MASTERDIR}/Makefile>
