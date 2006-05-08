# New ports collection makefile for:	dcraw
# Date created: 			14 February 2004
# Whom:					Arjan van Leeuwen <avleeuwen@piwebs.com>
#
# $FreeBSD$
#

PORTNAME=	dcraw
PORTVERSION=	8.15
CATEGORIES=	graphics
MASTER_SITES=	http://bsd1.csme.ru/myports/ \
		http://bsd2.csme.ru/myports/ \
		http://bsd3.csme.ru/myports/ \
		http://www.piwebs.com/distfiles/${PORTNAME}/

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Decoder for RAW files from digital cameras

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		lcms.1:${PORTSDIR}/graphics/lcms

USE_BZIP2=	yes

MAN1=		dcraw.1
PLIST_FILES=	bin/dcraw

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${PREFIX}/man/man1

.include <bsd.port.mk>
