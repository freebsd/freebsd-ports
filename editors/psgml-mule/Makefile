# New ports collection makefile for:	psgml for mule
# Version required:	1.2.0
# Date created:		23 January 1999
# Whom:			shige
#
# $FreeBSD$
#

MAINTAINER=	shige@FreeBSD.org

# This is a slave port.
PORTCLASS=	slave

MASTERDIR=	${.CURDIR}/../../editors/psgml-emacs

# emacs port setup
EMACS_NAME=	mule
EMACS_PORT=	mule
EMACS_VER=	19.34
EMACS_LIBDIR=	share/${EMACS_NAME}

# whether emacs has a *-common port
HAS_COMMON_PORT=	YES

# pkg/* files are used in ${.CURDIR}
PKGDIR=		${.CURDIR}/pkg

.include <${MASTERDIR}/Makefile>
