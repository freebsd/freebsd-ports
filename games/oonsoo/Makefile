# New ports collection makefile for:  oonsoo 
# Version required:	1.1
# Date created:		23rd June, 1997
# Whom:			Joel Sutton <sutton@aardvark.apana.org.au>
# FreeBSD Version:	2.2.1-RELEASE
#
# $Id$
#
      
DISTNAME=	oonsoo-1.1
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.eos.ncsu.edu/pub/bsvc/rohan/
EXTRACT_SUFX=	".tar.z"

MAINTAINER=	sutton@aardvark.apana.org.au

pre-patch:
	${CP} ${WRKSRC}/Makefile.Linux ${WRKSRC}/Makefile

# Distribution does not include an install target. So here it is.
#
do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/oonsoo ${PREFIX}/bin/

.include <bsd.port.mk>

