# New ports collection makefile for:	psgml for xemacs-mule
# Version required:	1.2.0
# Date created:		26 May 1999
# Whom:			kuriyama
#
# $FreeBSD$
#

MAINTAINER=	kuriyama@FreeBSD.org

# This is a slave port.
PORTCLASS=	slave

MASTERDIR=	${.CURDIR}/../psgml-emacs

# emacs port setup
EMACS_NAME=	xemacs
EMACS_PORT=	xemacs-mule
EMACS_VER=	21.1.8
EMACS_LIBDIR=	lib/xemacs

# pkg/* files are used in ${.CURDIR}
PKGDIR=		${.CURDIR}/pkg

# whether emacs has a *-common port
HAS_COMMON_PORT=	YES

.include <${MASTERDIR}/Makefile>
