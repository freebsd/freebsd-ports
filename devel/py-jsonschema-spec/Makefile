PORTNAME=	jsonschema-spec
PORTVERSION=	0.1.2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	JSONSchema Spec with object-oriented paths
WWW=		https://github.com/p1c2u/jsonschema-spec

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jsonschema>=4.0.0<5.0.0:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pathable>=0.4.1<0.5.0:devel/py-pathable@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=5.1:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.3.0<5.0.0:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
