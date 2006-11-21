# New ports collection makefile for:    camera
# Date created:         11 Sep 2006
# Whom:                 gurkan@linuks.mine.nu
#
# $FreeBSD$
#

PORTNAME=	camera
PORTVERSION=	0.8
CATEGORIES=	graphics
MASTER_SITES=	http://home.gna.org/gsimageapps/ \
		http://io.debian.net/~tar/ports/distfiles/
DISTNAME=	Camera-${PORTVERSION}

MAINTAINER=	gurkan@linuks.mine.nu
COMMENT=	GNUstep application for digital still cameras

LIB_DEPENDS+=	gphoto2_port:${PORTSDIR}/graphics/libgphoto2

WRKSRC=		${WRKDIR}/Camera
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
MAKEFILE=	GNUmakefile

.include <bsd.port.mk>
