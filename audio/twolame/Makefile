PORTNAME=	twolame
PORTVERSION=	0.4.0
PORTREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	SF \
		http://www.ecs.soton.ac.uk/~njh/twolame/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	MPEG Audio Layer 2 encoder
WWW=		http://twolame.sf.net/

LIB_DEPENDS=	libsndfile.so:audio/libsndfile \
		libFLAC.so:audio/flac \
		libvorbis.so:audio/libvorbis \
		libogg.so:audio/libogg

USES=		gmake pkgconfig libtool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
INSTALL_TARGET=	install-strip

post-patch:
	@${REINPLACE_CMD} -e 's| -O3||g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
