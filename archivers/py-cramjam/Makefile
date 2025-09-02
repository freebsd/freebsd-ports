PORTNAME=	cramjam
PORTVERSION=	2.11.0
PORTREVISION=	2
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

USES=		cargo python
USE_PYTHON=	autoplist concurrent pep517

CARGO_BUILD=	no
CARGO_INSTALL=	no
MAKE_ENV=	RUSTFLAGS="-L ${LOCALBASE}/lib"

.include <bsd.port.mk>
