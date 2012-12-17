# Created by: trasz <trasz@pin.if.uz.zgora.pl>
# $FreeBSD$

PORTNAME=	openjpeg
PORTVERSION=	1.5.0
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An open-source JPEG 2000 codec

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	tiff:${PORTSDIR}/graphics/tiff \
		png15:${PORTSDIR}/graphics/png

GNU_CONFIGURE=	yes
USE_CMAKE=	yes
USE_LDCONFIG=	yes

MAN1=		image_to_j2k.1 j2k_dump.1 j2k_to_image.1
MAN3=		libopenjpeg.3

.include <bsd.port.mk>
