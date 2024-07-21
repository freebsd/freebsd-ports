PORTNAME=	versioneer
PORTVERSION=	0.29
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Easy VCS-based management of project version strings
WWW=		https://github.com/python-versioneer/python-versioneer

LICENSE=	UNLICENSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PY_TOMLI} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	TOML
OPTIONS_DEFAULT=TOML
TOML_DESC=	TOML (Tom's Obvious Minimal Language) support

TOML_RUN_DEPENDS=	${PY_TOMLI}

.include <bsd.port.mk>
