PORTNAME=	jupyter-events
PORTVERSION=	0.12.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	jupyter_events-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Jupyter Event System library
WWW=		https://jupyter-events.readthedocs.io/en/latest/ \
		https://github.com/jupyter/jupyter_events

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=1.5:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jsonschema>=4.18.0:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-json-logger>=2.0.4:devel/py-python-json-logger@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=5.3:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}referencing>=0:devel/py-referencing@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rfc3339-validator>=0:devel/py-rfc3339-validator@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rfc3986-validator>=0.1.1:devel/py-rfc3986-validator@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}traitlets>=5.3:devel/py-traitlets@${PY_FLAVOR}
# jsonschema[format-nongpl]
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}fqdn>=0:www/py-fqdn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}idna>=0:dns/py-idna@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}isoduration>=0:devel/py-isoduration@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonpointer>=1.13:devel/py-jsonpointer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rfc3339-validator>=0:devel/py-rfc3339-validator@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rfc3986-validator>=0.1.0:devel/py-rfc3986-validator@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rfc3987-syntax>=1.1.0:www/py-rfc3987-syntax@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uri-template>=0:net/py-uri-template@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}webcolors>=24.6.0:graphics/py-webcolors@${PY_FLAVOR}

USES=		python:3.9+
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
