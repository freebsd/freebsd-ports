# New ports collection makefile for:	mpeg_lib
# Version required:	1.1
# Date created:		16 November 1994
# Whom:			torstenb
#
# $Id: Makefile,v 1.3 1995/04/09 07:09:35 asami Exp $
#

DISTNAME=	mpeg_lib-1.1
CATEGORIES+=	graphics
MASTER_SITES=	ftp://ftp.mni.mcgill.ca/pub/mpeg/

WRKSRC=		${WRKDIR}/mpeg_lib

pre-install:
	@mkdir -p ${PREFIX}/bin ${PREFIX}/lib ${PREFIX}/include
	@mkdir -p ${PREFIX}/man/man1 ${PREFIX}/man/man3

post-install:
	ldconfig -m ${PREFIX}/lib

.include <bsd.port.mk>
