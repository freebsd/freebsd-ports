PORTNAME=	behave
PORTVERSION=	1.3.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Behaviour-driven development in Python style
WWW=		https://behave.readthedocs.io/en/latest/ \
		https://github.com/behave/behave

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}colorama>=0.3.7:devel/py-colorama@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cucumber-expressions>=17.1.0:devel/py-cucumber-expressions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cucumber-tag-expressions>=4.1.0:devel/py-cucumber-tag-expressions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}parse-type>=0.6.0:textproc/py-parse-type@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}parse>=1.18.0:textproc/py-parse@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.15.0:devel/py-six@${PY_FLAVOR} \
		${PY_TOMLI}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
