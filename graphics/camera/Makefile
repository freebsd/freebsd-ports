# Created by: gurkan@phys.ethz.ch
# $FreeBSD$

PORTNAME=	camera
PORTVERSION=	0.8
PORTREVISION=	4
CATEGORIES=	graphics gnustep
MASTER_SITES=	http://download.gna.org/gsimageapps/ \
		${MASTER_SITE_GNUSTEP_CH}
DISTNAME=	Camera-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNUstep application for digital still cameras

LICENSE=	GPLv2

LIB_DEPENDS=	libgphoto2_port.so:${PORTSDIR}/graphics/libgphoto2

USES=	tar:bzip2
USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes

WRKSRC=		${WRKDIR}/Camera

post-patch:
	${REINPLACE_CMD} 's|^GNUSTEP_INSTALLATION_DIR|#GNUSTEP_INSTALLATION_DIR|' \
		${WRKSRC}/GNUmakefile

.include <bsd.port.mk>
