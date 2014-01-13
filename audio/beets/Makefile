# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	beets
PORTVERSION=	1.3.1
CATEGORIES=	audio python
MASTER_SITES=	CHEESESHOP

MAINTAINER=	feld@FreeBSD.org
COMMENT=	A media library management system for obsessive-compulsive music geeks

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mutagen>=1.21:${PORTSDIR}/audio/py-mutagen \
		${PYTHON_PKGNAMEPREFIX}unidecode>=0:${PORTSDIR}/converters/py-unidecode \
		${PYTHON_PKGNAMEPREFIX}musicbrainzngs>=0:${PORTSDIR}/audio/py-musicbrainzngs \
		${PYTHON_PKGNAMEPREFIX}munkres>=0:${PORTSDIR}/math/py-munkres \
		${PYTHON_PKGNAMEPREFIX}yaml>=0:${PORTSDIR}/devel/py-yaml \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:${PORTSDIR}/databases/py-sqlite3

MAN1=	beet.1
MAN5=	beetsconfig.5

NO_STAGE=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

OPTIONS_DEFINE=	BEATPORT CHROMA DISCOGS LASTFM FFMPEG REPLAYGAIN WEB
OPTIONS_DEFAULT=

CHROMA_DESC=	Audio Fingerprinting Plugin
BEATPORT_DESC=	Beatport Catalog Autotagging Support
DISCOGS_DESC=	Discogs Search Plugin
LASTFM_DESC=	LastGenre Plugin
REPLAYGAIN_DESC=	Normalize Audio Loudness
WEB_DESC=	Webserver Music Player Plugin

CHROMA_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyacoustid>=0:${PORTSDIR}/audio/py-pyacoustid
BEATPORT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=0:${PORTSDIR}/www/py-requests
DISCOGS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}discogs-client>=0:${PORTSDIR}/audio/py-discogs-client
FFMPEG_RUN_DEPENDS=	ffmpeg>=2:${PORTSDIR}/multimedia/ffmpeg
LASTFM_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pylast>=0:${PORTSDIR}/audio/py-pylast
REPLAYGAIN_RUN_DEPENDS=	mp3gain>=0:${PORTSDIR}/audio/mp3gain
REPLAYGAIN_RUN_DEPENDS+=	aacgain>=0:${PORTSDIR}/audio/aacgain
WEB_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Flask>=0:${PORTSDIR}/www/py-flask

.include <bsd.port.pre.mk>

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/beet.1 ${PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/man/beetsconfig.5 ${PREFIX}/man/man5/

.include <bsd.port.post.mk>
