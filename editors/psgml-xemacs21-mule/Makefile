# New ports collection makefile for:	psgml for xemacs-mule
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
EMACS_PORT=	xemacs21-mule
EMACS_CMD=	${PREFIX}/bin/${EMACS_PORT}
EMACS_VER=	21.1.10
EMACS_LIBDIR=	lib/xemacs

# pkg/* files are used in ${.CURDIR}
PKGDIR=		${.CURDIR}/pkg

# whether emacs has a *-common port
HAS_COMMON_PORT=	YES

.include <${MASTERDIR}/Makefile>
