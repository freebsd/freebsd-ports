# New ports collection makefile for:    PNG images library
# Version required:     0.81
# Date created:         5 Dec 1995
# Whom:                 ache
#
# $Id: Makefile,v 1.1.1.1 1995/12/05 02:48:17 ache Exp $
#

DISTNAME=       libpng-0.81
PKGNAME=        png-0.81
CATEGORIES+=    graphics
MASTER_SITES=   ftp://ftp.uu.net/graphics/png/src/
LIB_DEPENDS=    z\\.0\\.95:${PORTSDIR}/devel/libz
MAKEFILE=       makefile

MAINTAINER=     ache@FreeBSD.org

post-install:
	ldconfig -m ${PREFIX}/lib

.include <bsd.port.mk>
