# New ports collection makefile for:    camera
# Date created:         11 Sep 2006
# Whom:                 gurkan@linuks.mine.nu
#
# $FreeBSD$
#

PORTNAME=	camera
PORTVERSION=	0.8
CATEGORIES=	graphics gnustep
MASTER_SITES=	http://home.gna.org/gsimageapps/ \
		${MASTER_SITE_GNUSTEP_CH}
DISTNAME=	Camera-${PORTVERSION}

MAINTAINER=	gurkan@linuks.mine.nu
COMMENT=	GNUstep application for digital still cameras

LIB_DEPENDS+=	gphoto2_port:${PORTSDIR}/graphics/libgphoto2

USE_BZIP2=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes

WRKSRC=		${WRKDIR}/Camera

.include <bsd.port.mk>
