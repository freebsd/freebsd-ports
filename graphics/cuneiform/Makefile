# Created by: samm
# $FreeBSD$

PORTNAME=	cuneiform
PORTVERSION=	1.1.0
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	http://launchpadlibrarian.net/69906918/
DISTNAME=	${PORTNAME}-linux-${PORTVERSION}

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	OCR system developed and open sourced by Cognitive technologies

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/cuneiform_src/Kern/license.txt

DEPRECATED=	Unmaintained upstream
EXPIRATION_DATE=	2018-12-15
ONLY_FOR_ARCHS=	amd64 i386

USES=		cmake:outsource tar:bzip2
USE_CXXSTD=	gnu++98
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	IMAGEMAGICK

IMAGEMAGICK_LIB_DEPENDS=	libMagick++-6.so:graphics/ImageMagick
IMAGEMAGICK_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_ImageMagick

post-patch:
	${MV} ${WRKSRC}/cuneiform_src/Kern/hhh/tigerh/h/strings.h \
		${WRKSRC}/cuneiform_src/Kern/hhh/tigerh/h/cf_strings.h
	@${REINPLACE_CMD} -e 's:\[(uchar):\[(uchar)L:' \
		${WRKSRC}/cuneiform_src/Kern/leo/src/leo_dll.c

.include <bsd.port.mk>
