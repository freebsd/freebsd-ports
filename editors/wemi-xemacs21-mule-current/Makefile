# New ports collection makefile for:	wemi-current for xemacs21-mule
# Date created:		25 July 1999
# Whom:			Shigeyuki FUKUSHIMA <shige@FreeBSD.org>
#
# $FreeBSD$
#

MAINTAINER=	shige@FreeBSD.org

# This is a slave port.
PORTCLASS=	slave

MASTERDIR=	${.CURDIR}/../../editors/wemi-emacs-current

# emacs port setup
EMACS_PORT_NAME=	xemacs21-mule
EMACS_PACKAGESDIR=	${EMACS_LIBDIR}/site-packages
# packages-subdirectories which this port requires
EMACS_PACKAGES_SUBDIRS= info lisp man pkginfo

SCRIPTS_ENV=	EMACS_PACKAGESDIR=${EMACS_PACKAGESDIR}
PLIST_SUB=	EMACS_PACKAGESDIR=${EMACS_PACKAGESDIR}

# how to make and install
ALL_TARGET=	package
INSTALL_TARGET=	install-package

# whether building info files by emacs or makeinfo
BUILD_INFO_BY_EMACS=	YES
# texinfo packages
BUILD_DEPENDS+= ${LOCALBASE}/${EMACS_PACKAGESDIR}/../xemacs-packages/lisp/texinfo/texinfmt.el:${PORTSDIR}/editors/xemacs-packages

# use pkg-* files in ${.CURDIR}
PKGDIR=		${.CURDIR}

# package info manifest
MANIFEST=	MANIFEST.semi

# xemacs package
XEMACS_PKGNAME=		semi
XEMACS_PKGNAME_ALT=	wemi
XEMACS_PKGVER=		1.18
#XEMACS_PKGVER!=	grep version ${MASTERDIR}/files/_pkg.el | \
#		sed 's/.*:version \([0-9.]*\).*/\1/'
XEMACS_PKG_TARBALL=	${XEMACS_PKGNAME_ALT}-${XEMACS_PKGVER}-pkg.tar.gz
XEMACS_PKG_CONTENTS=	pkginfo/${MANIFEST} lisp/${XEMACS_PKGNAME} \
			info/mime-ui-en.info info/mime-ui-ja.info \
			man/${XEMACS_PKGNAME}

# package documents
WEMIDOCDIR=	${EMACS_PACKAGESDIR}/lisp/semi

xemacs-package: install
	@${RM} -f ${.CURDIR}/${XEMACS_PKG_TARBALL}
	@(cd ${LOCALBASE}/${EMACS_PACKAGESDIR} ;\
	  ${TAR} -zcf ${.CURDIR}/${XEMACS_PKG_TARBALL} ${XEMACS_PKG_CONTENTS} ;\
	)

.include <${MASTERDIR}/Makefile>
