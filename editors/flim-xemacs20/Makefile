# New ports collection makefile for:	flim for xemacs20
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
EMACS_PORT=	xemacs20
EMACS_VER=	20.4
EMACS_LIBDIR=		lib/${EMACS_NAME}
# xemacs-20.4 has no version specific site-lisp directories.
EMACS_LIBDIR_WITH_VER=	${EMACS_LIBDIR}

# use pkg/* files in ${.CURDIR}
PKGDIR=		${.CURDIR}/pkg

.include <${MASTERDIR}/Makefile>
