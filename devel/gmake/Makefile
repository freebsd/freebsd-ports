# New ports collection makefile for:	GNU make
# Version required:     3.77.7
# Date created:		11 September 1994
# Whom:			jkh
#
# $Id: Makefile,v 1.20 1999/01/27 07:41:07 fenner Exp $
#

DISTNAME=       make-3.77
PKGNAME=        gmake-3.77
CATEGORIES=	devel
MASTER_SITES=   ${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	make

MAINTAINER=	jseger@freebsd.org

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-prefix=g
MAN1=		gmake.1

# joerg@freebsd.org says our getloadavg() no longer requires setgid kmem
pre-install:
	@if [ ! -f ${PREFIX}/info/dir ]; then \
	  ${MKDIR} ${PREFIX}/info; \
	  ${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	 fi

post-install:
	chmod g-s ${PREFIX}/bin/gmake
	chgrp ${BINGRP} ${PREFIX}/bin/gmake

.include <bsd.port.mk>
