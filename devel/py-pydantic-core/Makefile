PORTNAME=	pydantic-core
PORTVERSION=	0.38.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	pydantic_core-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Core functionality for pydantic
WWW=		https://github.com/pydantic/pydantic-core

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}maturin>=0.13:devel/py-maturin@${PY_FLAVOR}

USES=		cargo python:3.7+
USE_PYTHON=	autoplist concurrent pep517

BINARY_ALIAS=	python3=${PYTHON_CMD}
CARGO_BUILD=	no
CARGO_INSTALL=	no
WRKSRC=		${WRKDIR}/pydantic_core-${PORTVERSION}

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 31100
BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}typing-extensions>=0:devel/py-typing-extensions@${PY_FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}typing-extensions>=0:devel/py-typing-extensions@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
