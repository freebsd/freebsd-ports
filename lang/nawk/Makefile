# New ports collection makefile for:  nawk
# Version required:    98.10.20
# Date created:        29 April 1998
# Whom:                Josh Gilliam <josh@quick.net>
#
# $Id: Makefile,v 1.2 1998/11/10 02:05:09 steve Exp $
#

DISTNAME=	awk
PKGNAME=	nawk-98.10.20
CATEGORIES=	lang
MASTER_SITES=	http://cm.bell-labs.com/who/bwk/
EXTRACT_SUFX=	tar.gz

MAINTAINER=	josh@quick.net

NO_WRKSUBDIR=	yes
MAKEFILE=	makefile
ALL_TARGET=	a.out
MAN1=		nawk.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/a.out ${PREFIX}/bin/nawk
	${INSTALL_MAN} ${WRKSRC}/awk.1 ${PREFIX}/man/man1/nawk.1

.include <bsd.port.mk>
