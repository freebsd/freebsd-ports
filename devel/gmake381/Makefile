# New ports collection makefile for:	GNU make
# Version required:     3.78.1
# Date created:		11 September 1994
# Whom:			jkh
#
# $FreeBSD$
#

DISTNAME=       make-3.78.1
PKGNAME=        g${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=   ${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	make

MAINTAINER=	jseger@FreeBSD.org

Y2K=		http://www.gnu.org/software/year2000.html

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-prefix=g
MAN1=		gmake.1

# joerg@freebsd.org says our getloadavg() no longer requires setgid kmem

post-install:
	${CHMOD} g-s ${PREFIX}/bin/gmake
	chgrp ${BINGRP} ${PREFIX}/bin/gmake

.include <bsd.port.mk>
