# Created by: gurkan@phys.ethz.ch
# $FreeBSD$

PORTNAME=	camera
PORTVERSION=	0.8
PORTREVISION=	10
CATEGORIES=	graphics gnustep
MASTER_SITES=	http://download.gna.org/gsimageapps/
DISTNAME=	Camera-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNUstep application for digital still cameras

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/Documentation/COPYING

LIB_DEPENDS=	libgphoto2_port.so:graphics/libgphoto2

USES=		tar:bzip2 gnustep
USE_GNUSTEP=	back build

WRKSRC=		${WRKDIR}/Camera

post-patch:
	${REINPLACE_CMD} 's|^GNUSTEP_INSTALLATION_DIR|#GNUSTEP_INSTALLATION_DIR|' \
		${WRKSRC}/GNUmakefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/System/Applications/Camera.app/Camera

.include <bsd.port.mk>
