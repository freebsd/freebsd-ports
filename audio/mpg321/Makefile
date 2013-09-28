# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mpg321
PORTVERSION=	0.2.10
PORTREVISION=	8
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	Command-line MP3 player, compatible with mpg123

LIB_DEPENDS=	libao.so:${PORTSDIR}/audio/libao \
		libid3tag.so:${PORTSDIR}/audio/libid3tag \
		libmad.so:${PORTSDIR}/audio/libmad

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-mpg123-symlink
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/mpg321 man/man1/mpg321.1.gz

OPTIONS_DEFINE=	SCROBBLER
SCROBBLER_DESC=	Last.fm Audioscrobbler support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSCROBBLER}
RUN_DEPENDS+=	scrobbler-helper:${PORTSDIR}/audio/p5-Audio-Scrobbler

PATCHFILES+=	mpg321-0.2.10-scrobbler-01.patch:scrobbler
PATCH_SITES+=	http://people.FreeBSD.org/~roam/ports/audio/:scrobbler \
		http://devel.ringlet.net/audio/mpg321-scrobbler/:scrobbler

MPG321_SCROBBLER_PLUGIN_NAME?=	321

post-patch:
		${REINPLACE_CMD} "s/\"mpg321\"/\"${MPG321_SCROBBLER_PLUGIN_NAME}\"/" ${WRKSRC}/scrobbler.c
.endif

.include <bsd.port.mk>
