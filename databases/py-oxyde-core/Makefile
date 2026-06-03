PORTNAME=	oxyde-core
DISTVERSION=	0.5.0
PORTREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	meka@tilda.center
COMMENT=	Rust core for Oxyde ORM
WWW=		https://github.com/mr-fatalyst/oxyde

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}maturin>=1.0<2.0:devel/py-maturin@${PY_FLAVOR}

USES=		cargo python
USE_PYTHON=	autoplist concurrent pep517

CARGO_CARGOLOCK=	${WRKSRC}/Cargo.lock
CARGO_CARGOTOML=	${WRKSRC}/crates/oxyde-core-py/Cargo.toml
CARGO_BUILD=	no
CARGO_INSTALL=	no
MAKE_ENV=	${CARGO_ENV}
BINARY_ALIAS=	python3=${PYTHON_CMD}

.include <bsd.port.mk>
