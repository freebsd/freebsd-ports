# New ports collection makefile for:	aalib
# Version required:			1.2
# Date created:				9 Dec 1997
# Whom:					Andrey Zakhvatov
#
# $Id: Makefile,v 1.6 1998/09/22 15:30:37 vanilla Exp $
#

DISTNAME=	aalib-1.2
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.ta.jcu.cz/pub/aa/

MAINTAINER=	andy@icc.surw.chel.su

USE_LIBTOOL=	yes

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
