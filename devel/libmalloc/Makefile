# New ports collection makefile for:	Mark Moraes malloc library
# Version required:	1.17alpha
# Date created:		11 January 1995
# Whom:			jkh
#
# $Id: Makefile,v 1.4 1995/06/24 11:37:20 asami Exp $
#

DISTNAME=	malloc
PKGNAME=	malloc-1.17a
CATEGORIES+=	devel
MASTER_SITES=	ftp.cs.toronto.edu:/pub/moraes/

post-install:
	ldconfig -m ${PREFIX}/lib

.include <bsd.port.mk>
