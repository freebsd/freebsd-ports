# New ports collection makefile for: gdbm
# Version required:	1.7.3
# Date created:		8 Apr 1996
# Whom:			Brent J. Nordquist <bjn@visi.com>
#
# $Id: Makefile,v 1.5 1998/02/15 17:00:57 steve Exp $
#

DISTNAME=          gdbm-1.7.3
CATEGORIES=        databases
MASTER_SITES=      ${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	gdbm

MAINTAINER=        bjn@visi.com

GNU_CONFIGURE=     yes
MAKE_FLAGS=        CFLAGS="${CFLAGS}" LDFLAGS=-s -f
MAN3=		   gdbm.3

post-install:
	@if [ ! -f ${PREFIX}/info/dir ]; then \
	  ${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	 fi
	@install-info ${PREFIX}/info/gdbm.info ${PREFIX}/info/dir

.include <bsd.port.mk>
