# New ports collection makefile for:	pixieplus
# Date created: 			3 March 2003
# Whom:					Arjan van Leeuwen <avleeuwen@piwebs.com>
#
# $FreeBSD$
#

PORTNAME=	pixieplus
PORTVERSION=	0.5.4
PORTREVISION=	2
CATEGORIES=	graphics kde
MASTER_SITES=	http://people.fruitsalad.org/avleeuwen/distfiles/${PORTNAME}/

MAINTAINER=	avleeuwen@piwebs.com
COMMENT=	A free, fast, and feature packed image browser and viewer for KDE

LIB_DEPENDS=	Magick.6:${PORTSDIR}/graphics/ImageMagick \
		ungif.5:${PORTSDIR}/graphics/libungif

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--program-prefix=''
USE_GMAKE=	yes
USE_KDELIBS_VER=3
INSTALLS_SHLIB=	yes
USE_LIBTOOL=	yes

.include <bsd.port.mk>
