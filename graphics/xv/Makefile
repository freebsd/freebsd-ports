# New ports collection makefile for:	xv
# Version required:	3.10a
# Date created:		30 October 1994
# Whom:			smace
#
# $Id: Makefile,v 1.12 1996/09/22 08:56:34 andreas Exp $
#

DISTNAME=	xv-3.10a
CATEGORIES=     graphics x11
MASTER_SITES=	ftp://ftp.cis.upenn.edu/pub/xv/
PATCH_SITES=    ${MASTER_SITES}
PATCHFILES=     xv-3.10a.JPEG-patch # xv-3.10a.TIFF-patch (for tiff3.4)

LIB_DEPENDS=    jpeg\\.7\\.:${PORTSDIR}/graphics/jpeg \
		tiff\\.3\\.3:${PORTSDIR}/graphics/tiff

USE_IMAKE=	yes

post-install:
	mkdir -p ${PREFIX}/share/doc/xv
	cp ${WRKSRC}/README ${PREFIX}/share/doc/xv
.if !defined(NOPORTDOCS)
	cp ${WRKSRC}/docs/xvdocs.ps ${PREFIX}/share/doc/xv
.endif

.include <bsd.port.mk>
