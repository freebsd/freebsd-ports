# New ports collection makefile for:	wemi for emacs20
# Version required:	1.8.6
# Date created:		23 September 1998
# Whom:			Shigeyuki FUKUSHIMA <shige@FreeBSD.ORG>
#
# $Id: Makefile,v 1.8 1999/04/19 16:44:51 sada Exp $
#

MAINTAINER=	shige@FreeBSD.ORG

# This is a slave port.
PORTCLASS=	slave

MASTERDIR=	${.CURDIR}/../../editors/wemi-emacs

# emacs port setup
EMACS_NAME=	emacs
EMACS_PORT=	emacs20
EMACS_VER=	20.3
EMACS_LIBDIR=	share/${EMACS_NAME}

# use pkg/* files in ${.CURDIR}
PKGDIR=		${.CURDIR}/pkg

.include <${MASTERDIR}/Makefile>
