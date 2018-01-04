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

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}discid>=0:audio/py-discid@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mutagen>=0:audio/py-mutagen@${FLAVOR}

USES=		gettext pyqt:4 python:2 desktop-file-utils
USE_PYQT=	core_run gui_run network_run xml_run
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
