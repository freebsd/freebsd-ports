# New ports collection makefile for:	flim for xemacs21-mule
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
EMACS_PORT=	xemacs21-mule
EMACS_VER=	21.1.9
EMACS_CMD=	${PREFIX}/bin/${EMACS_PORT}
EMACS_PACKAGESDIR=	lib/${EMACS_NAME}/site-packages
# packages-subdirectories which this port requires
EMACS_PACKAGES_SUBDIRS=	info lisp man pkginfo

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
BUILD_DEPENDS+=	${PREFIX}/${EMACS_PACKAGESDIR}/../xemacs-packages/lisp/texinfo/texinfo.el:${PORTSDIR}/editors/xemacs-sumo-packages

# use pkg/* files in ${.CURDIR}
PKGDIR=		${.CURDIR}/pkg

# package info manifest
MANIFEST=	MANIFEST.flim

# xemacs package
XEMACS_PKGNAME=	flim
XEMACS_PKGVER=	1.12
#XEMACS_PKGVER!=	grep version ${.CURDIR}/../flim-emacs/files/_pkg.el | \
#		sed 's/.*:version \([0-9.]*\).*/\1/'
XEMACS_PKG_TARBALL=	${XEMACS_PKGNAME}-${XEMACS_PKGVER}-pkg.tar.gz
XEMACS_PKG_CONTENTS=	pkginfo/${MANIFEST} lisp/${XEMACS_PKGNAME} \
			info/mime-en.info info/mime-ja.info \
			man/${XEMACS_PKGNAME}

# package documents
FLIMDOCDIR=	${EMACS_PACKAGESDIR}/lisp/flim

xemacs-package: install
	@${RM} -f ${.CURDIR}/${XEMACS_PKG_TARBALL}
	@(cd ${PREFIX}/${EMACS_PACKAGESDIR} ;\
	  ${TAR} -zcf ${.CURDIR}/${XEMACS_PKG_TARBALL} ${XEMACS_PKG_CONTENTS} ;\
	)

.include <${MASTERDIR}/Makefile>
