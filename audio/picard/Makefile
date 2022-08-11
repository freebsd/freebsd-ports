PORTNAME=	picard
PORTVERSION=	2.8.1
CATEGORIES=	audio python
MASTER_SITES=	http://ftp.musicbrainz.org/pub/musicbrainz/picard/ \
		ftp://ftp.musicbrainz.org/pub/musicbrainz/picard/ \
		http://ftp.osuosl.org/pub/musicbrainz/picard/

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Next generation MusicBrainz Tagger

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}discid>=1.0:audio/py-discid@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mutagen>=1.37:audio/py-mutagen@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dateutil>=2.7:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fasteners>=0.14:devel/py-fasteners@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=5.1:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markdown>=3.2:textproc/py-markdown@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyjwt>=2.0:www/py-pyjwt@${PY_FLAVOR}

USES=		gettext pyqt:5 python:3.7+ desktop-file-utils
USE_LOCALE=	en_US.UTF-8
USE_PYQT=	pyqt5_run sip
USE_PYTHON=	autoplist distutils noflavors

CONFLICTS_INSTALL=	picard-tools py*-python-picard # bin/picard

WRKSRC=		${WRKDIR}/${PORTNAME}-release-${DISTVERSION}

OPTIONS_DEFINE=		ACOUSTID PLUGINS
OPTIONS_DEFAULT=	PLUGINS

ACOUSTID_RUN_DEPENDS=	fpcalc:audio/chromaprint

PLUGINS_DESC=		Install various plugins to extend functionality
PLUGINS_RUN_DEPENDS=	picard-plugins>=2.0:audio/picard-plugins

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/picard/util/_astrcmp*.so

.include <bsd.port.mk>
