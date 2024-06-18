PORTNAME=	plette
PORTVERSION=	2.1.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Structured Pipfile and Pipfile.lock models
WWW=		https://github.com/sarugaku/plette

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61.0.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0.28.0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tomlkit>=0:textproc/py-tomlkit@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	VALIDATION
OPTIONS_DEFAULT=VALIDATION
VALIDATION_DESC=Validation support

VALIDATION_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Cerberus>=0:devel/py-cerberus@${PY_FLAVOR}

.include <bsd.port.mk>
