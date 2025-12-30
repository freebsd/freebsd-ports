PORTNAME=	ruamel.yaml.clib
PORTVERSION=	0.2.15
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	ruamel_yaml_clib-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	C version of reader, parser and emitter for ruamel.yaml
WWW=		https://yaml.dev/doc/ruamel.yaml.clib/ \
		https://sourceforge.net/projects/ruamel-yaml-clib/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent cython pep517

WRKSRC=		${WRKDIR}/ruamel.yaml.clib-${PORTVERSION}

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
