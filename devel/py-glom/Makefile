PORTNAME=	glom
PORTVERSION=	23.5.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Declarative object transformer and formatter
WWW=		https://glom.readthedocs.io/en/latest/ \
		https://github.com/mahmoud/glom

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}attrs>=0:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}boltons>=19.3.0:devel/py-boltons@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}face>=20.1.0:devel/py-face@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	TOML
OPTIONS_DEFAULT=TOML
TOML_DESC=	TOML (Tom's Obvious Minimal Language) support

TOMLI_RUN_DEPENDS=	${PY_TOMLI}

.include <bsd.port.mk>
