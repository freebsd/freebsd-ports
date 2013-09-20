# Created by: Masanori Kiriake <seiken@nbs.co.jp>
# $FreeBSD$

PORTNAME=	play
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_PORTS_JP}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple audio file player

CONFLICTS=	sox-[0-9]*

MAKE_ARGS=	CFLAGS="${CFLAGS}" DESTDIR="${PREFIX}" MANDIR="/man/ja/man"

MANLANG=	ja
NO_STAGE=	yes
MAN1=		play.1
MANCOMPRESSED=	yes
PLIST_FILES=	bin/play

post-patch:
.for file in play_audio.c mixer_ctl.c encode_sun.c encode_riff.c speed.c
	@${REINPLACE_CMD} '/soundcard\.h/s,machine,sys,' ${WRKSRC}/${file}
.endfor

.include <bsd.port.mk>
