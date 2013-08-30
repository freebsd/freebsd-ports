# Created by: sumikawa
# $FreeBSD$

PORTNAME=	raop_play
PORTVERSION=	0.5.1
PORTREVISION=	8
CATEGORIES=	audio
MASTER_SITES=	SF/raop-play/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	sumikawa@FreeBSD.org
COMMENT=	A music file player for Apple Airport Express

LIB_DEPENDS=	samplerate.1:${PORTSDIR}/audio/libsamplerate \
		fltk.1:${PORTSDIR}/x11-toolkits/fltk \
		id3tag.0:${PORTSDIR}/audio/libid3tag
RUN_DEPENDS=	mpg321:${PORTSDIR}/audio/mpg321 \
		ogg123:${PORTSDIR}/audio/vorbis-tools \
		faad:${PORTSDIR}/audio/faad \
		flac:${PORTSDIR}/audio/flac

GNU_CONFIGURE=	yes
LDFLAGS+=	`fltk-config --ldflags`
USES=		gmake
USE_GNOME=	glib20

pre-build:
	${CP} ${FILESDIR}/getline.c ${FILESDIR}/getline.h ${WRKSRC}/rendezvous/

.include <bsd.port.mk>
