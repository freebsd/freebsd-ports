# New ports collection makefile for:	GNU make
# Version required:     3.76.1
# Date created:		11 September 1994
# Whom:			jkh
#
# $Id: Makefile,v 1.17 1997/10/15 17:14:52 max Exp $
#

DISTNAME=       make-3.76.1
PKGNAME=        gmake-3.76.1
CATEGORIES=	devel
MASTER_SITES=   ${MASTER_SITE_GNU}

MAINTAINER=	jseger@freebsd.org

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-transform-name='s/^/g/'
MAN1=		gmake.1

# joerg@freebsd.org says our getloadavg() no longer requires setgid kmem
post-install:
	chmod g-s ${PREFIX}/bin/gmake
	chgrp ${BINGRP} ${PREFIX}/bin/gmake
	${INSTALL_MAN} ${WRKSRC}/make.man ${PREFIX}/man/man1/gmake.1
	@if [ ! -f ${PREFIX}/info/dir ]; then \
	  ${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	 fi
	@install-info ${PREFIX}/info/make.info ${PREFIX}/info/dir

.include <bsd.port.mk>
