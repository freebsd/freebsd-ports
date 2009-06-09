# New ports collection makefile for:    camerakit
# Date created:         18 Dec 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	camerakit
PORTVERSION=	0.0.1
PORTREVISION=	2
CATEGORIES=	graphics gnustep
MASTER_SITES=	http://download.gna.org/gsimageapps/
DISTNAME=	CameraKit-20041011

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Framework that allows to access digital cameras

LIB_DEPENDS=	gphoto2.2:${PORTSDIR}/graphics/libgphoto2

USE_BZIP2=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_LDCONFIG=	${GNUSTEP_LOCAL_LIBRARIES}

WRKSRC=		${WRKDIR}/CameraKit
ADDITIONAL_LIB_DIRS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
