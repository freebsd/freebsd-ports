# New ports collection makefile for:	fnlib
# Version required:	0.3
# Date created:		23 June 1997
# Whom:			brett@peloton.physics.montana.edu
#
# $Id: Makefile,v 1.2 1998/07/04 23:43:34 vanilla Exp $
#

DISTNAME=	fnlib_DR-0.3
PKGNAME=	fnlib-0.3
CATEGORIES=	graphics
MASTER_SITES=	ftp://www.rasterman.com/pub/enlightenment/enlightenment/ \
		ftp://ftp.enlightenment.org/pub/enlightenment/enlightenment/ \
		ftp://ftp.labs.redhat.com/pub/imlib/TAR/

MAINTAINER=	vanilla@FreeBSD.ORG

LIB_DEPENDS=	Imlib\\.1\\.7:${PORTSDIR}/graphics/imlib

USE_X11=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/fnlib

post-install:
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
