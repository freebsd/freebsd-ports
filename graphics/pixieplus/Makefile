# New ports collection makefile for:	pixieplus
# Date created: 			3 March 2003
# Whom:					Arjan van Leeuwen <avleeuwen@piwebs.com>
#
# $FreeBSD$
#

PORTNAME=	pixieplus
PORTVERSION=	0.5.4.1
PORTREVISION=	7
CATEGORIES=	graphics kde
MASTER_SITES=	http://people.fruitsalad.org/avleeuwen/distfiles/${PORTNAME}/

MAINTAINER=	avleeuwen@piwebs.com
COMMENT=	A free, fast, and feature packed image browser and viewer for KDE

LIB_DEPENDS=	Magick.10:${PORTSDIR}/graphics/ImageMagick \
		ungif.5:${PORTSDIR}/graphics/libungif

USE_AUTOTOOLS=	libtool:15
USE_GMAKE=	yes
USE_KDELIBS_VER=3
INSTALLS_SHLIB=	yes
USE_BZIP2=	yes

.include <bsd.port.pre.mk>

post-patch:
	@${CP} ${FILESDIR}/blob_private.h ${WRKSRC}/app/
	@${CP} ${FILESDIR}/exception_private.h ${WRKSRC}/app/
	@${CP} ${FILESDIR}/image_private.h ${WRKSRC}/app/

.include <bsd.port.post.mk>
