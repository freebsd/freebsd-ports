# New ports collection makefile for:	GNU make
# Version required:     3.75
# Date created:		11 September 1994
# Whom:			jkh
#
# $Id: Makefile,v 1.15 1997/06/12 12:31:00 max Exp $
#

DISTNAME=       make-3.75
PKGNAME=        gmake-3.75
CATEGORIES=	devel
MASTER_SITES=   ${MASTER_SITE_GNU}

GNU_CONFIGURE=	yes
MAN1=		gmake.1

# joerg@freebsd.org says our getloadavg() no longer requires setgid kmem
post-install:
	/bin/chmod g-s ${PREFIX}/bin/gmake
	/usr/bin/chgrp ${BINGRP} ${PREFIX}/bin/gmake
	@if [ ! -f ${PREFIX}/info/dir ]; then \
	  ${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	 fi
	@install-info ${PREFIX}/info/make.info ${PREFIX}/info/dir

.include <bsd.port.mk>
