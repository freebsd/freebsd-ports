# New ports collection makefile for:	apel for mule
# Version required:	9.x
# Date created:		23 September 1998
# Whom:			Shigeyuki FUKUSHIMA <shige@kuis.kyoto-u.ac.jp>
#
# $Id$
#

MAINTAINER=	shige@kuis.kyoto-u.ac.jp

# This is a slave port.
PORTCLASS=	slave

MASTERDIR=	${.CURDIR}/../../editors/apel-emacs

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
