# New ports collection makefile for:	dcraw
# Date created: 			14 February 2004
# Whom:					Arjan van Leeuwen <avleeuwen@piwebs.com>
#
# $FreeBSD$
#

PORTNAME=	dcraw
PORTVERSION=	1.166
CATEGORIES=	graphics
MASTER_SITES=	http://people.fruitsalad.org/avleeuwen/distfiles/${PORTNAME}/

MAINTAINER=	avleeuwen@piwebs.com
COMMENT=	Decoder for RAW files from digital cameras

PLIST_FILES=	bin/dcraw

.include <bsd.port.pre.mk>

do-install::
	${INSTALL_PROGRAM} ${WRKSRC}/dcraw ${PREFIX}/bin

.include <bsd.port.post.mk>
