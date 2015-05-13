# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	beets
PORTVERSION=	1.3.11
CATEGORIES=	audio python
MASTER_SITES=	CHEESESHOP

MAINTAINER=	stiginge@pvv.org
COMMENT=	Media library management system for obsessive-compulsive music geeks

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mutagen>=1.27:${PORTSDIR}/audio/py-mutagen \
		${PYTHON_PKGNAMEPREFIX}unidecode>=0:${PORTSDIR}/converters/py-unidecode \
		${PYTHON_PKGNAMEPREFIX}musicbrainzngs>=0.4:${PORTSDIR}/audio/py-musicbrainzngs \
		${PYTHON_PKGNAMEPREFIX}munkres>=0:${PORTSDIR}/math/py-munkres \
		${PYTHON_PKGNAMEPREFIX}yaml>=0:${PORTSDIR}/devel/py-yaml \
		${PYTHON_PKGNAMEPREFIX}enum34>=1.0:${PORTSDIR}/devel/py-enum34 \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:${PORTSDIR}/databases/py-sqlite3

USES=		python
USE_PYTHON=	distutils autoplist

PLIST_FILES=	man/man1/beet.1.gz man/man5/beetsconfig.5.gz

OPTIONS_DEFINE=	BPD CHROMA DISCOGS ECHONEST FETCHART FFMPEG \
		IMAGEMAGICK LASTFM LASTIMPORT LYRICS LYRICS_GOOGLE MPDSTATS \
		PLEXUPDATE REPLAYGAIN SPOTIFY THUMBNAILS WEB WEB_CORS
OPTIONS_DEFAULT=

BPD_DESC=	MPD Compatible Music Player Plugin
CHROMA_DESC=	Audio Fingerprinting Plugin
DISCOGS_DESC=	Discogs Search Plugin
ECHONEST_DESC=	Echo Nest Plugin
FETCHART_DESC=	Cover Art Fetch Plugin
IMAGEMAGICK_DESC=	Cover Art Resizing and Comparison
LASTFM_DESC=	LastGenre Plugin
LASTIMPORT_DESC=	Last.fm Import Plugin
LYRICS_DESC=	Lyrics Plugin
LYRICS_GOOGLE_DESC=	Use Google Custom Search for Lyrics
MPDSTATS_DESC=	MPD Statistics Plugin
PLEXUPDATE_DESC=	PlexUpdate Plugin
REPLAYGAIN_DESC=	Normalize Audio Loudness
SPOTIFY_DESC=	Spotify Plugin
THUMBNAILS_DESC=	Thumbnails for freedesktop.org-compliant file managers
WEB_DESC=		Web plugin for querying, browsing and playing music
WEB_CORS_DESC=		Cross-origin resource sharing for the Web plugin

BPD_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gstreamer>=0.10:${PORTSDIR}/multimedia/py-gstreamer
BPD_RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}mpd>=0.2.0:${PORTSDIR}/audio/py-mpd
CHROMA_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyacoustid>=0:${PORTSDIR}/audio/py-pyacoustid
DISCOGS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}discogs-client>=2.1.0:${PORTSDIR}/audio/py-discogs-client
ECHONEST_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyechonest>=8.0.1:${PORTSDIR}/devel/py-pyechonest
FETCHART_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=0:${PORTSDIR}/www/py-requests
FFMPEG_RUN_DEPENDS=	ffmpeg>=2:${PORTSDIR}/multimedia/ffmpeg
IMAGEMAGICK_RUN_DEPENDS=	convert:${PORTSDIR}/graphics/ImageMagick
LASTFM_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pylast>=0:${PORTSDIR}/audio/py-pylast
LASTIMPORT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=0:${PORTSDIR}/www/py-requests
LYRICS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=0:${PORTSDIR}/www/py-requests
LYRICS_GOOGLE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}py-beautifulsoup>=4:${PORTSDIR}/www/py-beautifulsoup
MPDSTATS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mpd>=0.2.0:${PORTSDIR}/audio/py-mpd
PLEXUPDATE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=0:${PORTSDIR}/www/py-requests
REPLAYGAIN_RUN_DEPENDS=	mp3gain>=0:${PORTSDIR}/audio/mp3gain
REPLAYGAIN_RUN_DEPENDS+=	aacgain>=0:${PORTSDIR}/audio/aacgain
SPOTIFY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=0:${PORTSDIR}/www/py-requests
THUMBNAILS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}xdg>=0:${PORTSDIR}/devel/py-xdg
THUMBNAILS_RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pathlib>=0:${PORTSDIR}/devel/py-pathlib
WEB_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Flask>=0:${PORTSDIR}/www/py-flask
WEB_CORS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Flask-Cors>=0:${PORTSDIR}/www/py-flask-cors

.include <bsd.port.pre.mk>

.if ! ${PORT_OPTIONS:MX11}
IMAGEMAGICK_RUN_DEPENDS=	convert:${PORTSDIR}/graphics/ImageMagick-nox11
.endif

post-install:
	${INSTALL} ${WRKSRC}/man/beet.1 ${STAGEDIR}${PREFIX}/man/man1/
	${INSTALL} ${WRKSRC}/man/beetsconfig.5 ${STAGEDIR}${PREFIX}/man/man5/

.include <bsd.port.post.mk>
