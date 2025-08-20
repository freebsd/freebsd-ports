PORTNAME=	ruamel.yaml
PORTVERSION=	0.18.15
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	YAML 1.2 loader/dumper package for Python
WWW=		https://sourceforge.net/p/ruamel-yaml

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ruamel.yaml.clib>=0.2.6:devel/py-ruamel.yaml.clib@${PY_FLAVOR}

USES=		python:3.9+
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

post-extract:
	@${RM} ${WRKSRC}/LICENSE

.include <bsd.port.mk>
