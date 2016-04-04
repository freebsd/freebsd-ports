# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	twolame
PORTVERSION=	0.3.13
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	SF \
		http://www.ecs.soton.ac.uk/~njh/twolame/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	MPEG Audio Layer 2 encoder

LIB_DEPENDS=	libsndfile.so:audio/libsndfile \
		libFLAC.so:audio/flac \
		libvorbis.so:audio/libvorbis \
		libogg.so:audio/libogg

USES=		gmake pathfix pkgconfig libtool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

post-patch:
	@${REINPLACE_CMD} -e 's| -O3||g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
