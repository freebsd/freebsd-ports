# New ports collection makefile for:	apel for xemacs-mule
# Version required:	9.20
# Date created:		13 June 1999
# Whom:			Shigeyuki FUKUSHIMA <shige@FreeBSD.ORG>
#
# $FreeBSD$
#

MAINTAINER=	shige@FreeBSD.ORG

# This is a slave port.
PORTCLASS=	slave

MASTERDIR=	${.CURDIR}/../../editors/apel-emacs

# emacs port setup
EMACS_NAME=	xemacs
EMACS_PORT=	xemacs-mule
EMACS_VER=	20.4
EMACS_LIBDIR=		lib/${EMACS_NAME}-${EMACS_VER}
EMACS_LIBDIR_WITH_VER=	lib/${EMACS_NAME}-${EMACS_VER}

# RUN_DEPENDS port name's suffix is '-common'.
HAVE_COMMON_PORT=	YES

# use pkg/* files in ${.CURDIR}
PKGDIR=		${.CURDIR}/pkg

.include <${MASTERDIR}/Makefile>
