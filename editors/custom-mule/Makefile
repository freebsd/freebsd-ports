# New ports collection makefile for:	custom for mule
# Date created:		27 December 1998
# Whom:			shige
#
# $FreeBSD$
#

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Custom Library for mule

# This is a slave port.
PORTCLASS=	slave

MASTERDIR=	${.CURDIR}/../../editors/custom-emacs

# emacs port setup
EMACS_PORT_NAME=	mule

# pkg/* files but PLIST are used in ${.CURDIR}
PKGDIR=		${.CURDIR}
PATCHDIR=	${.CURDIR}/files
PLIST=		${MASTERDIR}/pkg-plist

.include <${MASTERDIR}/Makefile>
