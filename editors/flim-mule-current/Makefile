# New ports collection makefile for:	flim for mule
# Version required:	1.12.5
# Date created:		9 May 1999
# Whom:			Shigeyuki FUKUSHIMA <shige@FreeBSD.ORG>
#
# $FreeBSD$
#

MAINTAINER=	shige@FreeBSD.ORG

# This is a slave port.
PORTCLASS=	slave

MASTERDIR=	${.CURDIR}/../../editors/flim-emacs-current

# emacs port setup
EMACS_NAME=	mule
EMACS_PORT=	mule
EMACS_VER=	19.34
EMACS_LIBDIR=		share/${EMACS_NAME}
EMACS_LIBDIR_WITH_VER=	${EMACS_LIBDIR}/${EMACS_VER}

HAVE_COMMON_PORT=	YES
REQUIRE_SETUPEL=	YES

# use pkg/* files in ${.CURDIR}
PKGDIR=		${.CURDIR}/pkg

.include <${MASTERDIR}/Makefile>
