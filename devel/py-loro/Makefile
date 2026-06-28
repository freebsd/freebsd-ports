PORTNAME=	loro
PORTVERSION=	1.13.1
DISTVERSIONPREFIX=	v
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Python bindings for Loro CRDT
WWW=		https://loro.dev

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}maturin>=1.8<2.0:devel/py-maturin@${PY_FLAVOR}

USES=		cargo python
USE_PYTHON=	autoplist pep517

USE_GITHUB=	yes
GH_ACCOUNT=	loro-dev
GH_PROJECT=	loro-py

CARGO_BUILD=		no
CARGO_INSTALL=		no
CARGO_TARGET_DIR=	${WRKSRC}/target

.include <bsd.port.mk>
