# Created by: SimaMoto,RyoTa <liangtai.s4@gmail.com>
# $FreeBSD$

PORTNAME=	libbs2b
PORTVERSION=	3.1.0
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	SF/bs2b/${PORTNAME}/${PORTVERSION}

MAINTAINER=	liangtai.s16@gmail.com
COMMENT=	Bauer Stereophonic-to-Binaural DSP

LIB_DEPENDS+=	libsndfile.so:audio/libsndfile \
		libogg.so:audio/libogg \
		libFLAC.so:audio/flac \
		libvorbis.so:audio/libvorbis

USES=		tar:bzip2 gmake pkgconfig libtool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	CFLAGS=`pkg-config --cflags sndfile` \
			LDFLAGS=`pkg-config --libs-only-L sndfile`

INSTALL_TARGET=	install-strip

pre-configure:
	${REINPLACE_CMD} -e 's@^\(pkgconfigdir = \).*@\1$${prefix}/libdata/pkgconfig@' \
	${WRKSRC}/Makefile.am ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
