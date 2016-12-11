# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	beets
PORTVERSION=	1.3.19
PORTREVISION=	1
CATEGORIES=	audio python
MASTER_SITES=	CHEESESHOP

MAINTAINER=	stiginge@pvv.org
COMMENT=	Media library management system for obsessive-compulsive music geeks

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mutagen>=1.27:audio/py-mutagen \
		${PYTHON_PKGNAMEPREFIX}unidecode>=0:converters/py-unidecode \
		${PYTHON_PKGNAMEPREFIX}musicbrainzngs>=0.4:audio/py-musicbrainzngs \
		${PYTHON_PKGNAMEPREFIX}munkres>=0:math/py-munkres \
		${PYTHON_PKGNAMEPREFIX}yaml>=0:devel/py-yaml \
		${PYTHON_PKGNAMEPREFIX}enum34>=1.0.4:devel/py-enum34 \
		${PYTHON_PKGNAMEPREFIX}jellyfish>=0:devel/py-jellyfish \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3

USES=		python
USE_PYTHON=	autoplist distutils

PLIST_FILES=	man/man1/beet.1.gz man/man5/beetsconfig.5.gz

OPTIONS_DEFINE=	ACOUSTICBRAINZ BADFILES BEATPORT BPD CHROMA DISCOGS EMBYUPDATE \
		FETCHART FFMPEG IMAGEMAGICK IPFS LASTFM LASTIMPORT LYRICS \
		LYRICS_GOOGLE MPDSTATS METASYNC_DBUS PLEXUPDATE REPLAYGAIN \
		SPOTIFY THUMBNAILS WEB WEB_CORS
OPTIONS_DEFAULT=

ACOUSTICBRAINZ_DESC=	AcousticBrainz Plugin
BADFILES_DESC=	Bad Files Plugin
BEATPORT_DESC=	Beatport Catalog Autotagging Support
BPD_DESC=	MPD Compatible Music Player Plugin
CHROMA_DESC=	Audio Fingerprinting Plugin
DISCOGS_DESC=	Discogs Search Plugin
EMBYUPDATE_DESC=	Emby Update Plugin
FETCHART_DESC=	Cover Art Fetch Plugin
IPFS_DESC=	IPFS Plugin
IMAGEMAGICK_DESC=	Cover Art Resizing and Comparison
LASTFM_DESC=	LastGenre Plugin
LASTIMPORT_DESC=	Last.fm Import Plugin
LYRICS_DESC=	Lyrics Plugin
LYRICS_GOOGLE_DESC=	Use Google Custom Search for Lyrics
METASYNC_DBUS_DESC=	Amarok support for the MetaSync plugin
MPDSTATS_DESC=	MPD Statistics Plugin
PLEXUPDATE_DESC=	PlexUpdate Plugin
REPLAYGAIN_DESC=	Normalize Audio Loudness
SPOTIFY_DESC=	Spotify Plugin
THUMBNAILS_DESC=	Thumbnails for freedesktop.org-compliant file managers
WEB_DESC=		Web plugin for querying, browsing and playing music
WEB_CORS_DESC=		Cross-origin resource sharing for the Web plugin

ACOUSTICBRAINZ_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests
BADFILES_RUN_DEPENDS=	flac:audio/flac \
			mp3val:audio/mp3val
BEATPORT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests \
			${PYTHON_PKGNAMEPREFIX}requests-oauthlib>=0.6.1:www/py-requests-oauthlib
BPD_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gstreamer1>=0:multimedia/py-gstreamer1
CHROMA_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyacoustid>=0:audio/py-pyacoustid
DISCOGS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}discogs-client>=2.1.0:audio/py-discogs-client
EMBYUPDATE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests
FETCHART_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests
FFMPEG_RUN_DEPENDS=	ffmpeg>=2:multimedia/ffmpeg
IMAGEMAGICK_RUN_DEPENDS=	convert:graphics/ImageMagick
IPFS_RUN_DEPENDS=	ipfs-go:sysutils/ipfs-go
LASTFM_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pylast>=0:audio/py-pylast
LASTIMPORT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests
LYRICS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests
LYRICS_GOOGLE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4:www/py-beautifulsoup
METASYNC_DBUS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>=0:devel/py-dbus
MPDSTATS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mpd2>=0:audio/py-mpd2
PLEXUPDATE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests
REPLAYGAIN_RUN_DEPENDS=	mp3gain>=0:audio/mp3gain
REPLAYGAIN_RUN_DEPENDS+=	aacgain>=0:audio/aacgain
SPOTIFY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests
THUMBNAILS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}xdg>=0:devel/py-xdg
THUMBNAILS_RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pathlib>=0:devel/py-pathlib
WEB_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Flask>=0:www/py-flask
WEB_CORS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Flask-Cors>=0:www/py-flask-cors

post-install:
	${INSTALL} ${WRKSRC}/man/beet.1 ${STAGEDIR}${PREFIX}/man/man1/
	${INSTALL} ${WRKSRC}/man/beetsconfig.5 ${STAGEDIR}${PREFIX}/man/man5/

.include <bsd.port.mk>
