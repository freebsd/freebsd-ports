# Created by: trasz <trasz@pin.if.uz.zgora.pl>
# $FreeBSD$

PORTNAME=	openjpeg
PORTVERSION=	1.5.0
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open-source JPEG 2000 codec

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	tiff:${PORTSDIR}/graphics/tiff \
		png15:${PORTSDIR}/graphics/png \
		lcms2:${PORTSDIR}/graphics/lcms2

GNU_CONFIGURE=	yes
USES=		cmake
USE_LDCONFIG=	yes

MAN1=		image_to_j2k.1 j2k_dump.1 j2k_to_image.1
MAN3=		libopenjpeg.3

NO_STAGE=	yes
.include <bsd.port.mk>
