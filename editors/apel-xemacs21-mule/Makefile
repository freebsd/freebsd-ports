# New ports collection makefile for:	apel for xemacs21-mule
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
EMACS_PORT=	xemacs21-mule
EMACS_VER=	21.1.9
EMACS_CMD=	${PREFIX}/bin/${EMACS_PORT}
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

# xemacs package
XEMACS_PKGNAME=	apel
XEMACS_PKGVER=	1.16
XEMACS_PKG_TARBALL=	${XEMACS_PKGNAME}-${XEMACS_PKGVER}-pkg.tar.gz
XEMACS_PKG_CONTENTS=	pkginfo/${MANIFEST} lisp/${XEMACS_PKGNAME}

# package documents
APELDOCDIR=	${EMACS_PACKAGESDIR}/lisp/${XEMACS_PKGNAME}

.if defined(PARALLEL_PACKAGE_BUILD)
FORBIDDEN=	hang
.endif

xemacs-package: install
	@${RM} -f ${.CURDIR}/${XEMACS_PKG_TARBALL}
	@(cd ${PREFIX}/${EMACS_PACKAGESDIR} ;\
	  ${TAR} -zcf ${.CURDIR}/${XEMACS_PKG_TARBALL} ${XEMACS_PKG_CONTENTS} ;\
	)

.include <${MASTERDIR}/Makefile>
