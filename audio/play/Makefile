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

USES=		uidfix
MAKE_ARGS=	CFLAGS="${CFLAGS}" MANDIR="${PREFIX}/man/ja/man" BINDIR="${PREFIX}/bin"

PLIST_FILES=	bin/play man/ja/man1/play.1.gz

post-patch:
.for file in play_audio.c mixer_ctl.c encode_sun.c encode_riff.c speed.c
	@${REINPLACE_CMD} '/soundcard\.h/s,machine,sys,' ${WRKSRC}/${file}
.endfor

.include <bsd.port.mk>
