# New ports collection makefile for:    PNG images library
# Version required:     0.89c
# Date created:         5 Dec 1995
# Whom:                 ache
#
# $Id: Makefile,v 1.7 1996/08/19 10:30:59 asami Exp $
#

DISTNAME=       libpng-0.89c
PKGNAME=        png-0.89c
CATEGORIES=     graphics
MASTER_SITES=   ftp://ftp.uu.net/graphics/png/src/

MAINTAINER=     ache@FreeBSD.org

MAKEFILE=       makefile

post-install:
	/sbin/ldconfig -m ${PREFIX}/lib

.include <bsd.port.mk>
