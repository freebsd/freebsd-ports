PORTNAME=	picard
PORTVERSION=	2.12.2
CATEGORIES=	audio python
MASTER_SITES=	http://ftp.musicbrainz.org/pub/musicbrainz/picard/ \
		ftp://ftp.musicbrainz.org/pub/musicbrainz/picard/ \
		http://ftp.osuosl.org/pub/musicbrainz/picard/

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Next generation MusicBrainz Tagger
WWW=		https://picard.musicbrainz.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING.txt

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}discid>=1.0:audio/py-discid@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mutagen>=1.37:audio/py-mutagen@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dateutil>=2.7:devel/py-python-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fasteners>=0.14:devel/py-fasteners@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=5.1:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markdown>=3.2:textproc/py-markdown@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyjwt>=2.0:www/py-pyjwt@${PY_FLAVOR}

USES=		desktop-file-utils gettext-tools pyqt:5 python
USE_LOCALE=	en_US.UTF-8
USE_PYQT=	pyqt5:run sip
USE_PYTHON=	autoplist noflavors pep517 unittest

CONFLICTS_INSTALL=	picard-tools py*-python-picard # bin/picard

OPTIONS_DEFINE=		ACOUSTID PLUGINS
OPTIONS_DEFAULT=	PLUGINS

ACOUSTID_RUN_DEPENDS=	fpcalc:audio/chromaprint

PLUGINS_DESC=		Install various plugins to extend functionality
PLUGINS_RUN_DEPENDS=	picard-plugins>=2.0:audio/picard-plugins

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/picard/util/_astrcmp*.so

.include <bsd.port.mk>
