# New ports collection makefile for:	apel for xemacs20
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
EMACS_PORT=	xemacs20
EMACS_VER=	20.4
EMACS_LIBDIR=		lib/${EMACS_NAME}
# xemacs-20.4 has no version specific site-lisp directories.
EMACS_LIBDIR_WITH_VER=	lib/${EMACS_NAME}

# use pkg/* files in ${.CURDIR}
PKGDIR=		${.CURDIR}/pkg

.include <${MASTERDIR}/Makefile>
