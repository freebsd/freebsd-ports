# New ports collection makefile for:	picard
# Date created:				Sat Aug 20 15:26:15 UTC 2005
# Whom:					Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	picard
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	audio python
MASTER_SITES=	http://ftp.musicbrainz.org/pub/musicbrainz/picard/ \
		ftp://ftp.musicbrainz.org/pub/musicbrainz/picard/ \
		http://ftp.uk.musicbrainz.org/pub/musicbrainz/picard/ \
		http://ftp.osuosl.org/pub/musicbrainz/picard/

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Next generation MusicBrainz Tagger

LICENSE=	GPLv2

LIB_DEPENDS=	ofa:${PORTSDIR}/audio/libofa \
		avcodec:${PORTSDIR}/multimedia/ffmpeg \
		discid:${PORTSDIR}/audio/libdiscid
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mutagen>=0:${PORTSDIR}/audio/py-mutagen \
		${PYTHON_PKGNAMEPREFIX}qt4-core>=0:${PORTSDIR}/devel/py-qt4-core \
		${PYTHON_PKGNAMEPREFIX}qt4-gui>=0:${PORTSDIR}/x11-toolkits/py-qt4-gui \
		${PYTHON_PKGNAMEPREFIX}qt4-network>=0:${PORTSDIR}/net/py-qt4-network \
		${PYTHON_PKGNAMEPREFIX}qt4-xml>=0:${PORTSDIR}/textproc/py-qt4-xml

USE_GETTEXT=	yes
USE_PYTHON=	-2.7
USE_PYDISTUTILS=yes
INSTALLS_ICONS=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|'picard.plugins',|'picard.plugins', 'picard.plugins.lastfm', 'picard.plugins.lastfmplus', 'picard.plugins.replaygain',|" \
		${WRKSRC}/setup.py
	@${CP} -R ${WRKSRC}/contrib/plugins/ ${WRKSRC}/picard/plugins

.include <bsd.port.mk>
