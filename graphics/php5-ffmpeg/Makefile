# Created by: Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ffmpeg
PORTVERSION=	0.6.0
PORTREVISION=	9
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}-php/${PORTNAME}-php/${PORTVERSION}
PKGNAMEPREFIX=	php5-
DISTNAME=	${PORTNAME}-php-${PORTVERSION}
EXTRACT_SUFX=	.tbz2

MAINTAINER=	acm@FreeBSD.org
COMMENT=	The ffmpeg shared extension for php

LIB_DEPENDS=	libgd.so:${PORTSDIR}/graphics/gd \
		libavutil0.so:${PORTSDIR}/multimedia/ffmpeg0

CFLAGS+=	-I${LOCALBASE}/include/ffmpeg0
LDFLAGS+=	-L${LOCALBASE}/lib/ffmpeg0
USE_BZIP2=	yes
USE_PHP=	yes
USE_PHPIZE=	yes
USE_PHPEXT=	yes

CONFIGURE_ARGS+=	--with-ffmpeg=${LOCALBASE}/include/ffmpeg0

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|==|=|g' ${WRKSRC}/config.m4
	@${REINPLACE_CMD} \
		-e 's,<avcodec\.h>,<libavcodec/avcodec\.h>,g' \
		-e 's,<avformat\.h>,<libavformat/avformat\.h>,g' \
		-e 's,<swscale\.h>,<libswscale/swscale\.h>,g' \
		${WRKSRC}/*.c \
		${WRKSRC}/*.h

pre-configure:
	@${REINPLACE_CMD} \
		-e 's,lavcodec,lavcodec0,g' \
		-e 's,lavformat,lavformat0,g' \
		-e 's,lavutil,lavutil0,g' \
		-e 's,lswscale,lswscale0,g' \
		-e 's,include/libavcodec,include/ffmpeg0/libavcodec,g' \
		-e 's,/libavcodec.so,/ffmpeg0/libavcodec0.so,g' \
		${WRKSRC}/configure

post-configure:
	@${REINPLACE_CMD} -e 's,include/ffmpeg$$,include/ffmpeg0,g' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
