# Created by: Jochem Kossen <j.kossen@home.nl>
# $FreeBSD$

PORTNAME=	cplay
PORTVERSION=	1.50
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	audio

MAINTAINER=	woodsb02@FreeBSD.org
COMMENT=	Curses-based front-end for various audio players

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-09-15

USE_GITHUB=	yes
GH_ACCOUNT=	hukka

USES=		gettext gmake python:2.7 shebangfix
SHEBANG_FILES=	${WRKSRC}/cplay cnq

MAKE_ARGS=	PREFIX="${STAGEDIR}${PREFIX}"
NO_ARCH=	yes

PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

OPTIONS_GROUP=		PLAYERS
OPTIONS_GROUP_PLAYERS=	MADPLAY MIKMOD MPG123 MPG321 MPLAYER MPV OGG123 SOX SPEEX SPLAY XMP

MADPLAY_DESC=		MPEG audio playback support via madplay
MPG321_DESC=		MP3 decoding support via mpg321
MPV_DESC=		mpv media player support
OGG123_DESC=		Ogg Vorbis audio decoding support via ogg123
SOX_DESC=		Audio playback support via SOund eXchange
SPLAY_DESC=		MPEG and WAV playback support via Splay
XMP_DESC=		Audio playback support via the Extended Module Player

MADPLAY_RUN_DEPENDS=	madplay:audio/madplay
MIKMOD_RUN_DEPENDS=	mikmod:audio/mikmod
MPG123_RUN_DEPENDS=	mpg123:audio/mpg123
MPG321_RUN_DEPENDS=	mpg321:audio/mpg321
MPLAYER_RUN_DEPENDS=	mplayer:multimedia/mplayer
MPV_RUN_DEPENDS=	mpv:multimedia/mpv
OGG123_RUN_DEPENDS=	ogg123:audio/vorbis-tools
SOX_RUN_DEPENDS=	play:audio/sox
SPEEX_RUN_DEPENDS=	speexdec:audio/speex
SPLAY_RUN_DEPENDS=	splay:audio/splay
XMP_RUN_DEPENDS=	xmp:audio/xmp

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
