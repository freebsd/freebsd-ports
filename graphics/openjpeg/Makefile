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

LIB_DEPENDS=	libtiff.so:${PORTSDIR}/graphics/tiff \
		libpng15.so:${PORTSDIR}/graphics/png \
		liblcms2.so:${PORTSDIR}/graphics/lcms2

DOS2UNIX_FILES=	libopenjpeg/opj_malloc.h
GNU_CONFIGURE=	yes
USES=		cmake dos2unix
USE_LDCONFIG=	yes

.include <bsd.port.mk>
