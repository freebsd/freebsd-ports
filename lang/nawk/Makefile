# ex:ts=8
# New ports collection makefile for:  nawk
# Version required:    99.04.16
# Date created:        29 April 1998
# Whom:                Josh Gilliam <josh@quick.net>
#
# $FreeBSD$
#

DISTNAME=	awk
PKGNAME=	nawk-99.06.20
CATEGORIES=	lang
MASTER_SITES=	http://cm.bell-labs.com/who/bwk/

MAINTAINER=	obrien@FreeBSD.org

NO_WRKSUBDIR=	yes
MAKEFILE=	makefile
ALL_TARGET=	a.out
MAN1=		nawk.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/a.out ${PREFIX}/bin/nawk
	${INSTALL_MAN} ${WRKSRC}/awk.1 ${PREFIX}/man/man1/nawk.1

.include <bsd.port.mk>
