# New ports collection makefile for:    PNG images library
# Version required:     0.89c
# Date created:         5 Dec 1995
# Whom:                 ache
#
# $Id: Makefile,v 1.6 1996/07/17 20:07:25 ache Exp $
#

DISTNAME=       libpng-0.89c
PKGNAME=        png-0.89c
CATEGORIES+=    graphics
MASTER_SITES=   ftp://ftp.uu.net/graphics/png/src/

MAINTAINER=     ache@FreeBSD.org

MAKEFILE=       makefile

post-install:
	/sbin/ldconfig -m ${PREFIX}/lib

.include <bsd.port.mk>
