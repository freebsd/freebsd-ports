# New ports collection makefile for:	apel for xemacs21-mule
# Date created:		13 June 1999
# Whom:			Shigeyuki FUKUSHIMA <shige@FreeBSD.org>
#
# $FreeBSD$
#

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Portable Emacs Library for xemacs21-mule

# This is a slave port.
PORTCLASS=	slave

MASTERDIR=	${.CURDIR}/../../editors/apel

# emacs port setup
EMACS_PORT_NAME=	xemacs21-mule
EMACS_PACKAGESDIR=	${EMACS_LIBDIR}/site-packages
# packages-subdirectories which this port requires
EMACS_PACKAGES_SUBDIRS=	lisp pkginfo

SCRIPTS_ENV=	EMACS_PACKAGESDIR=${EMACS_PACKAGESDIR}
PLIST_SUB=	EMACS_PACKAGESDIR=${EMACS_PACKAGESDIR}

# how to install
ALL_TARGET=	package
INSTALL_TARGET=	install-package

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
IGNORE=	hang
.endif

xemacs-package: install
	@${RM} -f ${.CURDIR}/${XEMACS_PKG_TARBALL}
	@(cd ${LOCALBASE}/${EMACS_PACKAGESDIR} ;\
	  ${TAR} -zcf ${.CURDIR}/${XEMACS_PKG_TARBALL} ${XEMACS_PKG_CONTENTS} ;\
	)

.include "${MASTERDIR}/Makefile"
