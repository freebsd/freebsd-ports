# New ports collection makefile for:	psgml for xemacs-mule
# Version required:	1.1.6
# Date created:		26 May 1999
# Whom:			kuriyama
#
# $FreeBSD$
#

MAINTAINER=	kuriyama@FreeBSD.ORG

# This is a slave port.
PORTCLASS=	slave

MASTERDIR=	${.CURDIR}/../psgml-emacs

# emacs port setup
EMACS_NAME=	xemacs
EMACS_PORT=	xemacs-mule
EMACS_VER=	20.4
EMACS_LIBDIR=	lib/xemacs-20.4

# pkg/* files are used in ${.CURDIR}
PKGDIR=		${.CURDIR}/pkg

HAVE_COMMON_PORT=	YES
REQUIRE_SETUPEL=	YES

.include <${MASTERDIR}/Makefile>
