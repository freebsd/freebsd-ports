# New ports collection makefile for: gd
# Version required:     1.7.3
# Date created:         27 Mar 1998
# Whom:                 jeff@cetlink.net
#
# $FreeBSD$
#

DISTNAME=       gd-1.7.3
CATEGORIES=	graphics
MASTER_SITES=   http://www.boutell.com/gd/http/ \
		ftp://ftp.boutell.com/pub/boutell/gd/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	png.3:${PORTSDIR}/graphics/png

pre-install:
	${MKDIR} ${PREFIX}/include/gd

.include <bsd.port.mk>
