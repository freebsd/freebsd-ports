# New ports collection makefile for:	fnlib
# Date created:		23 June 1997
# Whom:			brett@peloton.physics.montana.edu
#
# $FreeBSD$
#

PORTNAME=	fnlib
PORTVERSION=	0.5
CATEGORIES=	graphics
MASTER_SITES=	http://mirror.nucba.ac.jp/mirror/enlightenment/enlightenment/libs/ \
		ftp://ftp.leirianet.pt/pub/X11/enlightenment/enlightenment/libs/ \
		ftp://ftp.dti.ad.jp/pub/X/enlightenment/enlightenment/libs/ \
		ftp://mirror.nucba.ac.jp/mirror/enlightenment/enlightenment/libs/

MAINTAINER=	ade@FreeBSD.org

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_IMLIB=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
