PORTNAME=	wavbreaker
DISTVERSION=	0.16
PORTREVISION=	2
CATEGORIES=	audio

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	GUI tool to split WAV and MP3 files
WWW=		https://github.com/thp/wavbreaker

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libao.so:audio/libao

USES=		desktop-file-utils gettext-tools gnome meson pkgconfig
USE_GITHUB=	yes
USE_GNOME=	cairo gtk30
GH_ACCOUNT=	thp

CONFLICTS_INSTALL=	aften # bin/wavinfo

OPTIONS_DEFINE=	MOODBAR MPG123 VORBIS
OPTIONS_DEFAULT=MOODBAR MPG123 VORBIS

MOODBAR_DESC=		Visual representation from .mood files
MOODBAR_RUN_DEPENDS=	moodbar:audio/moodbar
MOODBAR_MESON_TRUE=	moodbar

MPG123_LIB_DEPENDS=	libmpg123.so:audio/mpg123
MPG123_MESON_TRUE=	mp3

VORBIS_LIB_DEPENDS=	libvorbisfile.so:audio/libvorbis
VORBIS_MESON_TRUE=	ogg_vorbis

.include <bsd.port.mk>
