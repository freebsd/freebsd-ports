# New ports collection makefile for:	mpeg_lib
# Version required:	1.1
# Date created:		16 November 1994
# Whom:			torstenb
#
# $Id: Makefile,v 1.6 1997/07/17 15:12:43 max Exp $
#

DISTNAME=	mpeg_lib-1.2.1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.mni.mcgill.ca/pub/mpeg/

WRKSRC=		${WRKDIR}/mpeg_lib

GNU_CONFIGURE= yup

pre-install:
	@mkdir -p ${PREFIX}/bin ${PREFIX}/lib ${PREFIX}/include

post-install:
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
