# New ports collection makefile for:	gnats
# Version required:     3.2
# Date created:		28 October 1995
# Whom:			pst
#
# $Id: Makefile,v 1.2 1995/11/02 08:07:29 asami Exp $
#

DISTNAME=       gnats-3.2
CATEGORIES+=	databases devel
MASTER_SITES=   ftp://prep.ai.mit.edu/pub/gnu/ \
		ftp://ftp.uu.net/systems/gnu/

# we've got some .elc and info files to compile (yuck)
BUILD_DEPENDS=	emacs:${PORTSDIR}/editors/emacs

GNU_CONFIGURE=	yes

CONFIGURE_ARGS= --prefix=${PREFIX} --with-full-gnats

# this stops the configuration program from pulling installation
# information in from the standard freebsd send-pr program
CONFIGURE_ENV=  SEND_PR=/usr/bin/false

# the gnats distribution comes with a lot of baggage we don't want to install
# just install gnats
INSTALL_TARGET=	install-gnats install-send-pr

.include <bsd.port.mk>
