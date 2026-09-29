PORTNAME=	validate-pyproject-schema-store
PORTVERSION=	2026.9.19
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	validate_pyproject_schema_store-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Plugin set for validate-pyproject and schema-store
WWW=		https://github.com/henryiii/validate-pyproject-schema-store

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=1.26:devel/py-hatchling@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
