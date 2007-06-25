# New ports collection makefile for:	dcraw
# Date created: 			14 February 2004
# Whom:					Arjan van Leeuwen <avleeuwen@piwebs.com>
#
# $FreeBSD$
#

PORTNAME=	dcraw
PORTVERSION=	8.76
CATEGORIES=	graphics
MASTER_SITES=	CENKES

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Decoder for RAW files from digital cameras

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		lcms.1:${PORTSDIR}/graphics/lcms

USE_BZIP2=	yes

MAN1=		dcraw.1
PLIST_FILES=	bin/dcraw

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${PREFIX}/man/man1/

.include <bsd.port.mk>
