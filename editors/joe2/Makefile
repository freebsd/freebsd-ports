# New ports collection makefile for:	joe
# Version required:	2.8
# Date created:		01 Jul 1995
# Whom:			torstenb@FreeBSD.ORG
#
# $Id$
#

DISTNAME=	joe2.8
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.std.com/src/editors/
EXTRACT_SUFX=	.tar.Z
WRKSRC=		${WRKDIR}/joe
ALL_TARGET=	joe


# Restrictive copyright (GNU general public licence, Vers. 1)
NO_PACKAGE=	yes

post-install:
	gzip -9nf ${PREFIX}/man/man1/joe.1

.include <bsd.port.mk>
