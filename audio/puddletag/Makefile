PORTNAME=	puddletag
DISTVERSION=	2.2.0
CATEGORIES=	audio python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	DtxdF@disroot.org
COMMENT=	Powerful, simple, audio tag editor
WWW=		https://puddletag.net

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Depends on deprecated devel/py-qt5-pyqt
EXPIRATION_DATE=	2023-11-28

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}configobj>=0:devel/py-configobj@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mutagen>=0:audio/py-mutagen@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyparsing>=0:devel/py-pyparsing@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}unidecode>=0:converters/py-unidecode@${PY_FLAVOR} \
		chromaprint>=0:audio/chromaprint

USES=		pyqt:5 python
USE_PYTHON=	autoplist distutils
USE_PYQT=	pyqt5:run

.include <bsd.port.mk>
