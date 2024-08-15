PORTNAME=	docformatter
PORTVERSION=	1.7.5
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Format docstrings to follow PEP 257
WWW=		https://docformatter.readthedocs.io/en/latest/ \
		https://github.com/PyCQA/docformatter

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.0.0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}charset-normalizer>=3.0.0<4:textproc/py-charset-normalizer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}untokenize>=0.1.1<0.2:devel/py-untokenize@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

SHEBANG_FILES=	src/docformatter/__main__.py

OPTIONS_DEFINE=	TOMLI
OPTIONS_DEFAULT=TOMLI
TOMLI_DESC=	TOML (Tom's Obvious Minimal Language) support

TOMLI_RUN_DEPENDS=	${PY_TOMLI}

.include <bsd.port.mk>
