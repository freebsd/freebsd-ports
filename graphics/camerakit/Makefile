# $FreeBSD$

PORTNAME=	camerakit
PORTVERSION=	0.0.1
PORTREVISION=	5
CATEGORIES=	graphics gnustep
MASTER_SITES=	http://download.gna.org/gsimageapps/
DISTNAME=	CameraKit-20041011

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Framework that allows to access digital cameras

LIB_DEPENDS=	libgphoto2.so:${PORTSDIR}/graphics/libgphoto2

USES=		tar:bzip2 gnustep
USE_GNUSTEP=	build back
USE_LDCONFIG=	${GNUSTEP_LOCAL_LIBRARIES}

WRKSRC=		${WRKDIR}/CameraKit

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/Local/Library/Frameworks/CameraKit.framework/Versions/0/libCameraKit.so

.include <bsd.port.mk>
