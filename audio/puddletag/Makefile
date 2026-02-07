PORTNAME=	puddletag
DISTVERSION=	2.5.0
PORTREVISION=	1
CATEGORIES=	audio python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Powerful, simple, audio tag editor
WWW=		https://puddletag.net

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}configobj>=0:devel/py-configobj@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mutagen>=0:audio/py-mutagen@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyparsing>=0:devel/py-pyparsing@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}unidecode>=0:converters/py-unidecode@${PY_FLAVOR} \
		chromaprint>=0:audio/chromaprint

USES=		desktop-file-utils pyqt:5 python
USE_PYQT=	pyqt5:run
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

OPTIONS_DEFINE=		LEVENSHTEIN LXML PYACOUSTID
OPTIONS_DEFAULT=	LEVENSHTEIN LXML PYACOUSTID

LEVENSHTEIN_DESC=	Enable better string matching
LXML_DESC=		Enable better HTML parsing
PYACOUSTID_DESC=	Enable support for tagging audio files using web based Tag Sources

LEVENSHTEIN_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Levenshtein>=0:devel/py-Levenshtein@${PY_FLAVOR}
LXML_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}lxml>=0:devel/py-lxml@${PY_FLAVOR}
PYACOUSTID_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}pyacoustid>=0:audio/py-pyacoustid@${PY_FLAVOR}

.include <bsd.port.mk>
