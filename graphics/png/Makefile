# New ports collection makefile for:    PNG images library
# Version required:     0.99e
# Date created:         5 Dec 1995
# Whom:                 ache
#
# $Id: Makefile,v 1.10 1997/07/17 15:12:44 max Exp $
#

DISTNAME=       libpng-0.99e
PKGNAME=        png-0.99e
CATEGORIES=     graphics
MASTER_SITES=   ftp://ftp.uu.net/graphics/png/src/

MAINTAINER=     ache@FreeBSD.org

MAKEFILE=       makefile.std
MAN3=           libpng.3 libpngpf.3
MAN5=           png.5

post-install:
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
