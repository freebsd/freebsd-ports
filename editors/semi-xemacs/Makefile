# New ports collection makefile for:	semi for xemacs
# Version required:	1.8.6
# Date created:		25 July 1999
# Whom:			Shigeyuki FUKUSHIMA <shige@FreeBSD.ORG>
#
# $FreeBSD$
#

MAINTAINER=	shige@FreeBSD.ORG

# This is a slave port.
PORTCLASS=	slave

MASTERDIR=	${.CURDIR}/../../editors/semi-emacs

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
