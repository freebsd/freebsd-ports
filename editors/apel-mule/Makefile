# New ports collection makefile for:	apel for mule
# Version required:	9.18
# Date created:		23 September 1998
# Whom:			Shigeyuki FUKUSHIMA <shige@FreeBSD.ORG>
#
# $Id: Makefile,v 1.2 1999/03/01 09:37:20 shige Exp $
#

MAINTAINER=	shige@FreeBSD.ORG

# This is a slave port.
PORTCLASS=	slave

MASTERDIR=	${.CURDIR}/../../editors/apel-emacs

# emacs port setup
EMACS_NAME=	mule
EMACS_PORT=	mule
EMACS_VER=	19.34
EMACS_LIBDIR=	share/${EMACS_NAME}

# RUN_DEPENDS port name's suffix is '-common'.
HAVE_COMMON_PORT=	YES
# emacs requires *-setup.el
REQUIRE_SETUPEL=	YES

# use pkg/* files in ${.CURDIR}
PKGDIR=		${.CURDIR}/pkg

.include <${MASTERDIR}/Makefile>
