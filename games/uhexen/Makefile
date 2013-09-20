# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	uhexen
PORTVERSION=	0.601
PORTREVISION=	9
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/U-hexen%20version%20${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Yet another port of Hexen, popular game from Raven Software

USE_GMAKE=	yes
USE_SDL=	mixer sdl

OPTIONS_DEFINE=	MUSIC
OPTIONS_DEFAULT=	MUSIC
MUSIC_DESC=	In-game MIDI music support

PLIST_FILES=	bin/uhexen

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${ARCH} == "powerpc"
BROKEN=		Does not compile on ${ARCH}
.endif

.if ${PORT_OPTIONS:MMUSIC}
RUN_DEPENDS=	${LOCALBASE}/lib/timidity/goemon.cfg:${PORTSDIR}/audio/timidity
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include "${.CURDIR}/../doom-data/Makefile.include"
.include <bsd.port.post.mk>
