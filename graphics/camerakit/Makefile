# $FreeBSD$

PORTNAME=	camerakit
PORTVERSION=	0.0.1
PORTREVISION=	3
CATEGORIES=	graphics gnustep
MASTER_SITES=	http://download.gna.org/gsimageapps/
DISTNAME=	CameraKit-20041011

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Framework that allows to access digital cameras

LIB_DEPENDS=	libgphoto2.so:${PORTSDIR}/graphics/libgphoto2

USES=	tar:bzip2
USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_LDCONFIG=	${GNUSTEP_LOCAL_LIBRARIES}

WRKSRC=		${WRKDIR}/CameraKit

.include <bsd.port.mk>
