# New ports collection makefile for:	mpeg_lib
# Version required:	1.1
# Date created:		16 November 1994
# Whom:			torstenb
#
# $Id: Makefile,v 1.1.1.1 1994/11/20 16:00:09 torstenb Exp $
#

DISTNAME=	mpeg_lib-1.1
MASTER_SITES=	ftp://ftp.mni.mcgill.ca/pub/mpeg/
CATEGORIES+=	graphics
WRKSRC=		${WRKDIR}/mpeg_lib

pre-install:
	@mkdir -p ${PREFIX}/bin ${PREFIX}/lib ${PREFIX}/include
	@mkdir -p ${PREFIX}/man/man1 ${PREFIX}/man/man3

.include <bsd.port.mk>
