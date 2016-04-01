# Created by: sumikawa
# $FreeBSD$

PORTNAME=	raop_play
PORTVERSION=	0.5.1
PORTREVISION=	10
CATEGORIES=	audio
MASTER_SITES=	SF/raop-play/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Music file player for Apple Airport Express

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libsamplerate.so:audio/libsamplerate \
		libfltk.so:x11-toolkits/fltk \
		libid3tag.so:audio/libid3tag
RUN_DEPENDS=	mpg321:audio/mpg321 \
		ogg123:audio/vorbis-tools \
		faad:audio/faad \
		flac:audio/flac

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
