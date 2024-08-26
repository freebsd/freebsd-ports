PORTNAME=	cramjam
PORTVERSION=	2.8.3
PORTREVISION=	3
CATEGORIES=	archivers python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Thin Python bindings to de/compression algorithms in Rust
WWW=		https://github.com/milesgranger/cramjam

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}maturin>=0.14:devel/py-maturin@${PY_FLAVOR}

USES=		cargo python
USE_PYTHON=	autoplist concurrent pep517

CARGO_BUILD=	no
CARGO_CARGOLOCK=${WRKSRC}/cramjam-python/Cargo.lock
CARGO_CARGOTOML=${WRKSRC}/cramjam-python/Cargo.toml
CARGO_INSTALL=	no

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
