# New ports collection makefile for:	fnlib
# Date created:		23 June 1997
# Whom:			brett@peloton.physics.montana.edu
#
# $FreeBSD$
#

PORTNAME=	fnlib
PORTVERSION=	0.5
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	enlightenment

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fonts and font libraries necessary for Enlightenment

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	imlib
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
