# New ports collection makefile for:	chbg
# Date created:		10 Dec 1999
# Whom:			Peter Jones <p@dancris.com>
#
# $FreeBSD$
#

PORTNAME=	chbg
PORTVERSION=	0.8.1
CATEGORIES=	graphics
MASTER_SITES=	http://www.idata.sk/~ondrej/sw/
DISTNAME=	${PORTNAME}-0.8pl1
EXTRACT_SUFX=	.tgz

MAINTAINER=	p@dancris.com

USE_GMAKE=	yes
USE_IMLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
