PORTNAME=	pydantic-core
PORTVERSION=	2.33.2
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	pydantic_core-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Core functionality for Pydantic validation and serialization
WWW=		https://github.com/pydantic/pydantic-core

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}maturin>=1<2:devel/py-maturin@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.6.0:devel/py-typing-extensions@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.6.0:devel/py-typing-extensions@${PY_FLAVOR}

USES=		cargo python:3.9+
USE_PYTHON=	autoplist concurrent pep517

BINARY_ALIAS=	python3=${PYTHON_CMD}
CARGO_BUILD=	no
CARGO_INSTALL=	no
WRKSRC=		${WRKDIR}/pydantic_core-${PORTVERSION}

.include <bsd.port.mk>
