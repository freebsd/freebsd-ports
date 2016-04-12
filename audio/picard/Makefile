# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	picard
PORTVERSION=	1.3.2
CATEGORIES=	audio python
MASTER_SITES=	http://ftp.musicbrainz.org/pub/musicbrainz/picard/ \
		ftp://ftp.musicbrainz.org/pub/musicbrainz/picard/ \
		http://ftp.osuosl.org/pub/musicbrainz/picard/

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Next generation MusicBrainz Tagger

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}discid>=0:audio/py-discid \
		${PYTHON_PKGNAMEPREFIX}mutagen>=0:audio/py-mutagen \
		${PYTHON_PKGNAMEPREFIX}qt4-core>=0:devel/py-qt4-core \
		${PYTHON_PKGNAMEPREFIX}qt4-gui>=0:x11-toolkits/py-qt4-gui \
		${PYTHON_PKGNAMEPREFIX}qt4-network>=0:net/py-qt4-network \
		${PYTHON_PKGNAMEPREFIX}qt4-xml>=0:textproc/py-qt4-xml

USES=		gettext python:2 desktop-file-utils
USE_PYTHON=	distutils
INSTALLS_ICONS=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-release-${PORTVERSION}

OPTIONS_DEFINE=	ACOUSTID REPLAYGAIN

ACOUSTID_DESC=		AcoustID audio fingerprinting support
ACOUSTID_RUN_DEPENDS=	fpcalc:audio/chromaprint

REPLAYGAIN_DESC=	ReplayGain audio normalization support
REPLAYGAIN_RUN_DEPENDS=	metaflac:audio/flac \
			mp3gain:audio/mp3gain \
			vorbisgain:audio/vorbisgain \
			wvgain:audio/wavpack

post-patch:
	@${REINPLACE_CMD} -e 's|distutils\.command\.install |setuptools\.command\.install |' \
		${WRKSRC}/setup.py
	@${CP} -R ${WRKSRC}/contrib/plugins/ ${WRKSRC}/picard/plugins

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/picard/util/astrcmp.so

.include <bsd.port.mk>
