# New ports collection makefile for:	psgml for mule
# Version required:	1.1.6
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

HAVE_COMMON_PORT=	YES
REQUIRE_SETUPEL=	YES

# pkg/* files are used in ${.CURDIR}
PKGDIR=		${.CURDIR}/pkg

.include <${MASTERDIR}/Makefile>
