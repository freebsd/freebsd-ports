# New ports collection makefile for:    PNG images library
# Version required:     0.96
# Date created:         5 Dec 1995
# Whom:                 ache
#
# $Id: Makefile,v 1.9 1997/06/24 13:15:47 ache Exp $
#

DISTNAME=       libpng-0.96
PKGNAME=        png-0.96
CATEGORIES=     graphics
MASTER_SITES=   ftp://ftp.uu.net/graphics/png/src/
EXTRACT_SUFX=   .tgz

MAINTAINER=     ache@FreeBSD.org

MAKEFILE=       makefile

post-install:
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
