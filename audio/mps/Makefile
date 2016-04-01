# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mps
PORTVERSION=	0.20.16
#PORTREVISION=	0
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	CHEESESHOP

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Terminal based MP3 search, playback and download

LICENSE=	GPLv3

OPTIONS_DEFAULT=	MPLAYER
OPTIONS_RADIO=		PLAYER
OPTIONS_RADIO_PLAYER=	MPLAYER MPV

MPV_DESC=	Mpv media player support

# This port installs the following files in shared dirs
# PLIST_FILES=	bin/mps
USES=		python
USE_PYTHON=	distutils autoplist

MPLAYER_RUN_DEPENDS=	mplayer:multimedia/mplayer
MPV_RUN_DEPENDS=	mpv:multimedia/mpv

.include <bsd.port.mk>
