# New ports collection makefile for:	apel for emacs20
# Version required:	9.19
# Date created:		22 September 1998
# Whom:			Shigeyuki FUKUSHIMA <shige@FreeBSD.ORG>
#
# $Id: Makefile,v 1.3 1999/05/09 16:14:42 shige Exp $
#

MAINTAINER=	shige@FreeBSD.ORG

# This is a slave port.
PORTCLASS=	slave

MASTERDIR=	${.CURDIR}/../../editors/apel-emacs

# emacs port setup
EMACS_NAME=	emacs
EMACS_PORT=	emacs20
EMACS_VER=	20.3
EMACS_LIBDIR=		share/${EMACS_NAME}
EMACS_LIBDIR_WITH_VER=	${EMACS_LIBDIR}/${EMACS_VER}

# use pkg/* files in ${.CURDIR}
PKGDIR=		${.CURDIR}/pkg

.include <${MASTERDIR}/Makefile>
