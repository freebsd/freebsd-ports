# New ports collection makefile for:	fnlib
# Version required:	0.2
# Date created:		23 June 1997
# Whom:			brett@peloton.physics.montana.edu
#
# $Id $
#

DISTNAME=	fnlib_DR-0.2
PKGNAME=	fnlib-0.2
CATEGORIES=	graphics
MASTER_SITES=	ftp://www.rasterman.com/pub/enlightenment/libs/fnlib/

MAINTAINER=	ports@freebsd.org

LIB_DEPENDS=	Imlib\\.1\\.6:${PORTSDIR}/graphics/imlib

USE_X11=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/fnlib

post-install:
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
