# New ports collection makefile for:    PNG images library
# Version required:     0.81
# Date created:         5 Dec 1995
# Whom:                 ache
#
# $Id: Makefile,v 1.5 1995/11/26 11:29:09 asami Exp $
#

DISTNAME=       libpng-0.81
PKGNAME=        png-0.81
CATEGORIES+=	devel
MASTER_SITES=   ftp://ftp.uu.net/graphics/png/src/
LIB_DEPENDS=    z\\.0\\.95:${PORTSDIR}/devel/libz
MAKEFILE=       makefile

MAINTAINER=     ache@FreeBSD.org

post-install:
	ldconfig -m ${PREFIX}/lib

.include <bsd.port.mk>
