# New ports collection makefile for: gdbm
# Version required:	1.7.3
# Date created:		8 Apr 1996
# Whom:			Brent J. Nordquist <nordquist@platinum.com>
#
# $Id$
#

DISTNAME=          gdbm-1.7.3
CATEGORIES+=       databases
MASTER_SITES=      ftp://gatekeeper.dec.com/pub/GNU/ \
                   ftp://prep.ai.mit.edu/pub/gnu/

MAINTAINER=        nordquist@platinum.com

GNU_CONFIGURE=     yes

MAKE_FLAGS=        CFLAGS="${CFLAGS}" LDFLAGS=-s -f

post-install:
.if !defined(NOMANCOMPRESS)
	gzip -9nf ${PREFIX}/man/man3/gdbm.3
.endif

.include <bsd.port.mk>
