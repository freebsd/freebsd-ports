# New ports collection makefile for:  kawk
# Version required:    98.02.11
# Date created:        29 April 1998
# Whom:                Josh Gilliam <josh@quick.net>
#
# $Id$
#

DISTNAME=	awk
PKGNAME=	kawk-98.02.11
CATEGORIES=	lang
MASTER_SITES=	http://cm.bell-labs.com/who/bwk/

MAINTAINER=	josh@quick.net

NO_WRKSUBDIR=	yes
MAKEFILE=	makefile
ALL_TARGET=	a.out
MAN1=		kawk.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/a.out ${PREFIX}/bin/kawk
	${INSTALL_MAN} ${WRKSRC}/awk.1 ${PREFIX}/man/man1/kawk.1

.include <bsd.port.mk>
