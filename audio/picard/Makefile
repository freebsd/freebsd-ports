# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	picard
PORTVERSION=	1.2
PORTREVISION=	2
CATEGORIES=	audio python
MASTER_SITES=	http://ftp.musicbrainz.org/pub/musicbrainz/picard/ \
		ftp://ftp.musicbrainz.org/pub/musicbrainz/picard/ \
		http://ftp.osuosl.org/pub/musicbrainz/picard/

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Next generation MusicBrainz Tagger

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING.txt

LIB_DEPENDS=	libdiscid.so:${PORTSDIR}/audio/libdiscid
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mutagen>=0:${PORTSDIR}/audio/py-mutagen \
		${PYTHON_PKGNAMEPREFIX}qt4-core>=0:${PORTSDIR}/devel/py-qt4-core \
		${PYTHON_PKGNAMEPREFIX}qt4-gui>=0:${PORTSDIR}/x11-toolkits/py-qt4-gui \
		${PYTHON_PKGNAMEPREFIX}qt4-network>=0:${PORTSDIR}/net/py-qt4-network \
		${PYTHON_PKGNAMEPREFIX}qt4-xml>=0:${PORTSDIR}/textproc/py-qt4-xml

USES=		gettext python:2 desktop-file-utils
USE_PYTHON=	distutils
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	ACOUSTID REPLAYGAIN

ACOUSTID_DESC=		AcoustID audio fingerprinting support
ACOUSTID_RUN_DEPENDS=	fpcalc:${PORTSDIR}/audio/chromaprint

REPLAYGAIN_DESC=	ReplayGain audio normalization support
REPLAYGAIN_RUN_DEPENDS=	metaflac:${PORTSDIR}/audio/flac \
			mp3gain:${PORTSDIR}/audio/mp3gain \
			vorbisgain:${PORTSDIR}/audio/vorbisgain \
			wvgain:${PORTSDIR}/audio/wavpack

post-patch:
	@${REINPLACE_CMD} -e "s|'picard.plugins',|'picard.plugins', 'picard.plugins.lastfm', 'picard.plugins.lastfmplus', 'picard.plugins.replaygain',|" \
		-e 's,distutils\.command\.install ,setuptools\.command\.install ,' \
		${WRKSRC}/setup.py
	@${CP} -R ${WRKSRC}/contrib/plugins/ ${WRKSRC}/picard/plugins

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/picard/util/astrcmp.so

.include <bsd.port.mk>
