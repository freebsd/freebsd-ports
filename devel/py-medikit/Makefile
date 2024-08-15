PORTNAME=	medikit
PORTVERSION=	0.8.0
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Automated release engineer assistant
WWW=		https://python-medikit.github.io/ \
		https://github.com/python-medikit/medikit

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Jinja2>=2.10:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}git-semver>=0.3.2<0.4:devel/py-git-semver@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mondrian>=0.8<1:devel/py-mondrian@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=20.0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pip-tools4>=4.5.0<4.6:devel/py-pip-tools4@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}semantic-version>=2.8<3:devel/py-semantic-version@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}stevedore>=3.0:devel/py-stevedore@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}whistle>=1.0<2:devel/py-whistle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yapf>=0.20<1:textproc/py-yapf@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
