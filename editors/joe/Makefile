# New ports collection makefile for:	joe
# Version required:	2.8
# Date created:		01 Jul 1995
# Whom:			torstenb@FreeBSD.ORG
#
# $Id: Makefile,v 1.1.1.1 1995/07/05 15:08:49 torstenb Exp $
#

DISTNAME=	joe2.8
PKGNAME=	joe-2.8
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.std.com/src/editors/
EXTRACT_SUFX=	.tar.Z

WRKSRC=		${WRKDIR}/joe
ALL_TARGET=	joe

post-install:
.if !defined(NOMANCOMPRESS)
	gzip -9nf ${PREFIX}/man/man1/joe.1
.endif

.include <bsd.port.mk>
