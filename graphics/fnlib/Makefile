# New ports collection makefile for:	fnlib
# Version required:	0.4
# Date created:		23 June 1997
# Whom:			brett@peloton.physics.montana.edu
#
# $FreeBSD$
#

DISTNAME=	fnlib-0.4
CATEGORIES=	graphics
MASTER_SITES=	http://mirror.nucba.ac.jp/mirror/enlightenment/enlightenment/ \
		ftp://ftp.leirianet.pt/pub/X11/enlightenment/enlightenment/ \
		ftp://ftp.dti.ad.jp/pub/X/enlightenment/enlightenment/ \
		ftp://mirror.nucba.ac.jp/mirror/enlightenment/enlightenment/

MAINTAINER=	vanilla@FreeBSD.org

LIB_DEPENDS=	Imlib.5:${PORTSDIR}/graphics/imlib

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
