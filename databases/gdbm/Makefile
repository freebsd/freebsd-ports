# New ports collection makefile for: gdbm
# Version required:	1.7.3
# Date created:		8 Apr 1996
# Whom:			Brent J. Nordquist <nordquist@platinum.com>
#
# $Id: Makefile,v 1.1.1.1 1996/04/12 06:44:15 asami Exp $
#

DISTNAME=          gdbm-1.7.3
CATEGORIES=        databases
MASTER_SITES=      ftp://gatekeeper.dec.com/pub/GNU/ \
                   ftp://prep.ai.mit.edu/pub/gnu/

MAINTAINER=        nordquist@platinum.com

GNU_CONFIGURE=     yes
MAKE_FLAGS=        CFLAGS="${CFLAGS}" LDFLAGS=-s -f
MAN3=		   gdbm.3

.include <bsd.port.mk>
