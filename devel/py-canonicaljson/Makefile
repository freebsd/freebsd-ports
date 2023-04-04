PORTNAME=	canonicaljson
PORTVERSION=	1.6.4
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Canonical JSON
WWW=		https://github.com/matrix-org/python-canonicaljson

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=35.0.2:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}simplejson>=3.14.0:devel/py-simplejson@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}frozendict>=1.0:devel/py-frozendict@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes

OPTIONS_DEFINE=	FROZENDICT
FROZENDICT_DESC=Frozendict immutable dictionaries support

FROZENDICT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}frozendict>=1.0:devel/py-frozendict@${PY_FLAVOR}

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 30800
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.0.0:devel/py-typing-extensions@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
