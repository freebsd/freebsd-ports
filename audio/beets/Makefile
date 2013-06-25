# Created by: Mark Felder <feld@feld.me>
# $FreeBSD$

PORTNAME=	beets
PORTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	audio python
MASTER_SITES=	CHEESESHOP

MAINTAINER=	feld@feld.me
COMMENT=	A media library management system for obsessive-compulsive music geeks

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mutagen>=0:${PORTSDIR}/audio/py-mutagen \
		${PYTHON_PKGNAMEPREFIX}unidecode>=0:${PORTSDIR}/converters/py-unidecode \
		${PYTHON_PKGNAMEPREFIX}musicbrainzngs>=0:${PORTSDIR}/audio/py-musicbrainzngs \
		${PYTHON_PKGNAMEPREFIX}munkres>=0:${PORTSDIR}/math/py-munkres

MAN1=	beet.1
MAN5=	beetsconfig.5

USE_PYTHON=	2.7+
USE_PYDISTUTILS=	easy_install

OPTIONS_DEFINE=	CHROMA FFMPEG REPLAYGAIN
OPTIONS_DEFAULT=

CHROMA_DESC=	Audio Fingerprinting Plugin
REPLAYGAIN_DESC=	Normalize audio loudness

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCHROMA}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}acoustid>=0:${PORTSDIR}/audio/py-acoustid
.endif

.if ${PORT_OPTIONS:MFFMPEG}
RUN_DEPENDS+=	ffmpeg>=0:${PORTSDIR}/multimedia/ffmpeg1
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
