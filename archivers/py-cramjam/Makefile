PORTNAME=	cramjam
PORTVERSION=	2.12.1
CATEGORIES=	archivers python
MASTER_SITES=	PYPI \
		https://github.com/milesgranger/cramjam/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Thin Python bindings to de/compression algorithms in Rust
WWW=		https://github.com/milesgranger/cramjam

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}maturin>=0.14:devel/py-maturin@${PY_FLAVOR}
LIB_DEPENDS=	libblosc2.so:archivers/c-blosc2 \
		libisal.so:devel/isa-l

USES=		cargo python:3.11+
USE_PYTHON=	autoplist concurrent pep517

CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no

.include <bsd.port.mk>
