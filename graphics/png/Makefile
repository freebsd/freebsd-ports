# New ports collection makefile for:    PNG images library
# Version required:     0.88
# Date created:         5 Dec 1995
# Whom:                 ache
#
# $Id: Makefile,v 1.3 1996/01/25 05:48:01 ache Exp $
#

DISTNAME=       libpng-0.88
PKGNAME=        png-0.88
CATEGORIES+=    graphics
MASTER_SITES=   ftp://ftp.uu.net/graphics/png/src/
LIB_DEPENDS=    z\\.1\\.:${PORTSDIR}/devel/libz
MAKEFILE=       makefile

MAINTAINER=     ache@FreeBSD.org

post-install:
	/sbin/ldconfig -m ${PREFIX}/lib

.include <bsd.port.mk>
