# $FreeBSD$

PORTNAME=	libbs2b
PORTVERSION=	3.1.0
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	SF/bs2b/${PORTNAME}/${PORTVERSION}

MAINTAINER=	liangtai.s16@gmail.com
COMMENT=	Bauer Stereophonic-to-Binaural DSP

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS+=	libsndfile.so:audio/libsndfile \
		libogg.so:audio/libogg \
		libFLAC.so:audio/flac \
		libvorbis.so:audio/libvorbis

USES=		gmake libtool localbase pathfix pkgconfig tar:bzip2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
