PORTNAME=	simple-parsing
PORTVERSION=	0.1.3
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	simple_parsing-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Small utility for simplifying and cleaning up argument parsing scripts
WWW=		https://pypi.org/project/simple-parsing/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}docstring-parser>=0.15<1:textproc/py-docstring-parser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.5.0:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	YAML
OPTIONS_DEFAULT=YAML

YAML_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}yaml>=0:devel/py-yaml@${PY_FLAVOR}

.include <bsd.port.mk>
