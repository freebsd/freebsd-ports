PORTNAME=	ruamel.yaml
PORTVERSION=	0.17.21
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	pi@FreeBSD.org
COMMENT=	YAML 1.2 loader/dumper package for Python
WWW=		https://bitbucket.org/ruamel/yaml

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ruamel.yaml.clib>=0.2.6:devel/py-ruamel.yaml.clib@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

post-extract:
	@${RM} ${WRKSRC}/LICENSE

.include <bsd.port.mk>
