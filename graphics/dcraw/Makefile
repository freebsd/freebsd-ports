# New ports collection makefile for:	dcraw
# Date created: 			14 February 2004
# Whom:					Arjan van Leeuwen <avleeuwen@piwebs.com>
#
# $FreeBSD$
#

PORTNAME=	dcraw
PORTVERSION=	1.289
CATEGORIES=	graphics
MASTER_SITES=	http://www.piwebs.com/distfiles/${PORTNAME}/

MAINTAINER=	avleeuwen@piwebs.com
COMMENT=	Decoder for RAW files from digital cameras

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg

USE_BZIP2=	yes

MAN1=		dcraw.1
PLIST_FILES=	bin/dcraw

.include <bsd.port.pre.mk>

do-install::
	${INSTALL_PROGRAM} ${WRKSRC}/dcraw ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/dcraw.1 ${PREFIX}/man/man1

.include <bsd.port.post.mk>
