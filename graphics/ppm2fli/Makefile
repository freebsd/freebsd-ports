# New ports collection makefile for:	ppm2fli
# Version required:	b1.92
# Date created:		7 Jan 1998
# Whom:			giffunip@asme.org
#
# $Id: Makefile,v 1.1.1.1 1998/02/18 04:21:05 steve Exp $
#

DISTNAME=       ppm2fli_b1.92
PKGNAME=	ppm2fli-b1
CATEGORIES=	graphics
MASTER_SITES=	ftp://crusty.er.usgs.gov/pub/animation/fli/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=     giffunip@asme.org

MAN1=	ppm2fli.1 unflick.1
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ppm2fli ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/unflick ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ppm2fli.man ${PREFIX}/man/man1/ppm2fli.1
	${INSTALL_MAN} ${WRKSRC}/unflick.man ${PREFIX}/man/man1/unflick.1

.include <bsd.port.mk>
