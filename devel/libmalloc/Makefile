# New ports collection makefile for:	Mark Moraes malloc library
# Version required:	1.17alpha
# Date created:		11 January 1995
# Whom:			jkh
#
# $Id: Makefile,v 1.6 1996/04/12 08:25:58 asami Exp $
#

DISTNAME=	malloc
PKGNAME=	malloc-1.17a
CATEGORIES=	devel
MASTER_SITES=	ftp.cs.toronto.edu:/pub/moraes/

BROKEN=		yes

post-install:
	ldconfig -m ${PREFIX}/lib

.include <bsd.port.mk>
