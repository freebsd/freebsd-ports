# New ports collection makefile for:	apel for xemacs
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
EMACS_PORT=	xemacs
EMACS_VER=	19.16
EMACS_LIBDIR=		lib/${EMACS_NAME}
# xemacs-19.16 has no version specific site-lisp directories.
EMACS_LIBDIR_WITH_VER=	${EMACS_LIBDIR}

# use pkg/* files in ${.CURDIR}
PKGDIR=		${.CURDIR}/pkg

.include <${MASTERDIR}/Makefile>
