PORTNAME=	mps
PORTVERSION=	0.20.16
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	PYPI

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Terminal based MP3 search, playback and download
WWW=		https://github.com/np1/mps

LICENSE=	GPLv3

OPTIONS_DEFAULT=	MPLAYER
OPTIONS_RADIO=		PLAYER
OPTIONS_RADIO_PLAYER=	MPLAYER MPV

MPV_DESC=	Mpv media player support

# This port installs the following files in shared dirs
# PLIST_FILES=	bin/mps
USES=		python
USE_PYTHON=	distutils autoplist concurrent optsuffix

MPLAYER_RUN_DEPENDS=	mplayer:multimedia/mplayer
MPV_RUN_DEPENDS=	mpv:multimedia/mpv

.include <bsd.port.mk>
