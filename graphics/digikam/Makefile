# New ports collection makefile for:	digikam
# Date created: 			3 February 2003
# Whom:					Arjan van Leeuwen <avleeuwen@piwebs.com>
#
# $FreeBSD$
#

PORTNAME=	digikam
PORTVERSION=	0.5.1
PORTREVISION=	1
CATEGORIES=	graphics kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	avleeuwen@piwebs.com
COMMENT=	A KDE frontend to gphoto2 for communicating with your digicam

LIB_DEPENDS=	gphoto2.2:${PORTSDIR}/graphics/libgphoto2
BUILD_DEPENDS=	xml2pot:${PORTSDIR}/devel/kdesdk3

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_KDELIBS_VER=3

.include <bsd.port.mk>
