# New ports collection makefile for:	xv
# Version required:	3.10a
# Date created:		30 October 1994
# Whom:			smace
#
# $Id: Makefile,v 1.10 1995/12/20 10:49:09 asami Exp $
#

DISTNAME=	xv-3.10a
CATEGORIES+=	graphics x11
MASTER_SITES=	ftp://ftp.cis.upenn.edu/pub/xv/

LIB_DEPENDS=    jpeg\\.6\\.:${PORTSDIR}/graphics/jpeg \
		tiff\\.3\\.:${PORTSDIR}/graphics/tiff

USE_IMAKE=	yes

post-install:
	mkdir -p ${PREFIX}/share/doc/xv
	cp ${WRKSRC}/README ${PREFIX}/share/doc/xv
.if !defined(NOPORTDOCS)
	cp ${WRKSRC}/docs/xvdocs.ps ${PREFIX}/share/doc/xv
.endif

.include <bsd.port.mk>
