# New ports collection makefile for:	semi-1.13.x for mule
# Date created:		9 May 1999
# Whom:			Shigeyuki FUKUSHIMA <shige@FreeBSD.org>
#
# $FreeBSD$
#

MAINTAINER=	shige@FreeBSD.org

# This is a slave port.
PORTCLASS=	slave

MASTERDIR=	${.CURDIR}/../../editors/semi113-emacs

# emacs port setup
EMACS_PORT_NAME=	mule

# whether emacs requires *-setupel.el
REQUIRE_SETUPEL=	YES

# use pkg-* files in ${.CURDIR}
PKGDIR=		${.CURDIR}

.include <${MASTERDIR}/Makefile>
