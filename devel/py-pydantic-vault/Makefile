PORTNAME=	pydantic-vault
PORTVERSION=	1.0.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pydantic_vault-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Pydantic BaseSettings extension to retrieve secrets from Hashicorp Vault
WWW=		https://github.com/nymous/pydantic-vault

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hvac>=0.10.6:devel/py-hvac@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic>=1.8<2:devel/py-pydantic@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
