# New ports collection makefile for:	wemi for xemacs-mule
# Version required:	1.8.6
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
EMACS_VER=	20.4
EMACS_LIBDIR=		lib/${EMACS_NAME}-${EMACS_VER}
# xemacs-mule-20.4 has no version specific site-lisp directories.
EMACS_LIBDIR_WITH_VER=	${EMACS_LIBDIR}

# RUN_DEPENDS port name's suffix is '-common'.
HAVE_COMMON_PORT=	YES

# use pkg/* files in ${.CURDIR}
PKGDIR=		${.CURDIR}/pkg

.include <${MASTERDIR}/Makefile>
