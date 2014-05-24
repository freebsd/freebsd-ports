# Created by: trasz <trasz@pin.if.uz.zgora.pl>
# $FreeBSD$

PORTNAME=	openjpeg
PORTVERSION=	1.5.2
CATEGORIES=	graphics
MASTER_SITES=	SF/openjpeg.mirror/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open-source JPEG 2000 codec

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libtiff.so:${PORTSDIR}/graphics/tiff \
		libpng15.so:${PORTSDIR}/graphics/png \
		liblcms2.so:${PORTSDIR}/graphics/lcms2

USES=		cmake dos2unix
DOS2UNIX_FILES=	libopenjpeg/opj_malloc.h
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

.include <bsd.port.mk>
