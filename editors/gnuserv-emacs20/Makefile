# New ports collection makefile for:   gnuserv-emacs20
# Date created:        10 February 2001
# Whom:                ilya
#
# $FreeBSD$
#

# This is a slave port.
PORTCLASS=	slave

MASTERDIR=	${.CURDIR}/../gnuserv

# emacs port setup
USE_EMACS=	yes
EMACS_PORT_NAME=	emacs20
CONFIGURE_ARGS+=	--x-includes=${X11BASE}/includes \
			--x-libraries=${X11BASE}/lib

.include "${MASTERDIR}/Makefile"
