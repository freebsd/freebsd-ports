# New ports collection makefile for:    PNG images library
# Version required:     0.88
# Date created:         5 Dec 1995
# Whom:                 ache
#
# $Id: Makefile,v 1.4 1996/02/19 22:17:28 ache Exp $
#

DISTNAME=       libpng-0.88
PKGNAME=        png-0.88
CATEGORIES+=    graphics
MASTER_SITES=   ftp://ftp.uu.net/graphics/png/src/

MAINTAINER=     ache@FreeBSD.org

LIB_DEPENDS=    z\\.1\\.:${PORTSDIR}/devel/libz

MAKEFILE=       makefile

post-install:
	/sbin/ldconfig -m ${PREFIX}/lib

.include <bsd.port.mk>
