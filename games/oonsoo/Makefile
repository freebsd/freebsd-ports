# New ports collection makefile for:  oonsoo 
# Version required:	1.1
# Date created:		23rd June, 1997
# Whom:			Joel Sutton <sutton@aardvark.apana.org.au>
#
# $Id: Makefile,v 1.2 1997/06/30 14:35:04 max Exp $
#

DISTNAME=	oonsoo-1.1
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.eos.ncsu.edu/pub/bsvc/rohan/
EXTRACT_SUFX=	.tar.z

MAINTAINER=	sutton@aardvark.apana.org.au

BROKEN_ELF=	build

pre-patch:
	@${CP} ${WRKSRC}/Makefile.Linux ${WRKSRC}/Makefile

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/oonsoo ${PREFIX}/bin/

.include <bsd.port.mk>
