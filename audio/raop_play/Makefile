# Created by: sumikawa
# $FreeBSD$

PORTNAME=	raop_play
PORTVERSION=	0.5.1
PORTREVISION=	9
CATEGORIES=	audio
MASTER_SITES=	SF/raop-play/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	sumikawa@FreeBSD.org
COMMENT=	Music file player for Apple Airport Express

LIB_DEPENDS=	libsamplerate.so:${PORTSDIR}/audio/libsamplerate \
		libfltk.so:${PORTSDIR}/x11-toolkits/fltk \
		libid3tag.so:${PORTSDIR}/audio/libid3tag
RUN_DEPENDS=	mpg321:${PORTSDIR}/audio/mpg321 \
		ogg123:${PORTSDIR}/audio/vorbis-tools \
		faad:${PORTSDIR}/audio/faad \
		flac:${PORTSDIR}/audio/flac

GNU_CONFIGURE=	yes
LDFLAGS+=	`fltk-config --ldflags`
USES=		gmake
USE_GNOME=	glib20

post-patch:
	@${REINPLACE_CMD} 's/-lssl/-lcrypto/' \
		${WRKSRC}/configure ${WRKSRC}/raop_play/Makefile.in

pre-build:
	${CP} ${FILESDIR}/getline.c ${FILESDIR}/getline.h ${WRKSRC}/rendezvous/

.include <bsd.port.mk>
