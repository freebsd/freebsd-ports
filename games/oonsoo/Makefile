# New ports collection makefile for:  oonsoo 
# Version required:	1.1
# Date created:		23rd June, 1997
# Whom:			Joel Sutton <jsutton@bbcon.com.au>
#
# $FreeBSD$
#

DISTNAME=	oonsoo-1.1
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.eos.ncsu.edu/pub/bsvc/rohan/
EXTRACT_SUFX=	.tar.z

MAINTAINER=	jsutton@bbcon.com.au

USE_XLIB=	yes

pre-patch:
	@${CP} ${WRKSRC}/Makefile.Linux ${WRKSRC}/Makefile

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/oonsoo ${PREFIX}/bin/

.include <bsd.port.mk>
