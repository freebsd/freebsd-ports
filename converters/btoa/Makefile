# New ports collection makefile for: btoa
# Date created:                      4 Apr 1996
# Whom:                              Brent J. Nordquist <bjn@visi.com>
#
# $FreeBSD$
#

PORTNAME=	btoa
PORTVERSION=	5.2.1
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	asami/LOCAL_PORTS
DISTNAME=	btoa-5.2

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	btoa-5.2-patch1.gz

MAINTAINER=	bjn@visi.com

MAKE_FLAGS=	DESTDIR=${PREFIX} -f
MAKEFILE=	Makefile.sun
MAN1=		btoa.1

# Turn off the default from bsd.port.mk (-p0), which screws things up
PATCH_DIST_STRIP=

.include <bsd.port.mk>
