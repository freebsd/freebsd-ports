# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	beets
PORTVERSION=	1.2.2
PORTREVISION=	1
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
USE_PYTHON=	2.7+
USE_PYDISTUTILS=	easy_install

OPTIONS_DEFINE=	CHROMA BEATPORT DISCOGS FFMPEG REPLAYGAIN
OPTIONS_DEFAULT=

CHROMA_DESC=	Audio Fingerprinting Plugin
BEATPORT_DESC=	Beatport catalog autotagging support
DISCOGS_DESC=	Discogs search plugin
REPLAYGAIN_DESC=	Normalize audio loudness

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCHROMA}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}acoustid>=0:${PORTSDIR}/audio/py-pyacoustid
.endif

.if ${PORT_OPTIONS:MBEATPORT}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}requests>=0:${PORTSDIR}/www/py-requests
.endif

.if ${PORT_OPTIONS:MDISCOGS}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}discogs-client>=0:${PORTSDIR}/audio/py-discogs-client
.endif

.if ${PORT_OPTIONS:MFFMPEG}
RUN_DEPENDS+=	ffmpeg>=2:${PORTSDIR}/multimedia/ffmpeg
.endif

.if ${PORT_OPTIONS:MREPLAYGAIN}
RUN_DEPENDS+=	mp3gain>=0:${PORTSDIR}/audio/mp3gain \
		aacgain>=0:${PORTSDIR}/audio/aacgain
.endif

.include <bsd.port.pre.mk>

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/beet.1 ${PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/man/beetsconfig.5 ${PREFIX}/man/man5/

.include <bsd.port.post.mk>
