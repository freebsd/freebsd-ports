# New ports collection makefile for:    PNG images library
# Version required:     0.89c
# Date created:         5 Dec 1995
# Whom:                 ache
#
# $Id: Makefile,v 1.5 1996/02/20 05:35:35 asami Exp $
#

DISTNAME=       libpng-0.89c
PKGNAME=        png-0.89c
CATEGORIES+=    graphics
MASTER_SITES=   ftp://ftp.uu.net/graphics/png/src/

MAINTAINER=     ache@FreeBSD.org

LIB_DEPENDS=    z\\.1\\.:${PORTSDIR}/devel/libz

MAKEFILE=       makefile

post-install:
	/sbin/ldconfig -m ${PREFIX}/lib

.include <bsd.port.mk>
