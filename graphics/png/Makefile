# New ports collection makefile for:    PNG images library
# Version required:     1*
# Date created:         5 Dec 1995
# Whom:                 ache
#
# $Id: Makefile,v 1.12 1998/03/28 13:48:18 ache Exp $
#

DISTNAME=       libpng-1.0.2
PKGNAME=        png-1.0.2
CATEGORIES=     graphics
MASTER_SITES=   ftp://ftp.uu.net/graphics/png/src/

MAINTAINER=     ache@FreeBSD.org

MAN3=           libpng.3 libpngpf.3
MAN5=           png.5

do-configure:
	cd ${WRKSRC} && cp scripts/makefile.std Makefile

post-install:
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
