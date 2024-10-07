PORTNAME=	cramjam
PORTVERSION=	2.8.4
CATEGORIES=	archivers python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Thin Python bindings to de/compression algorithms in Rust
WWW=		https://github.com/milesgranger/cramjam

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	c-blosc2>=0:archivers/c-blosc2 \
		isa-l>=0:devel/isa-l \
		${PYTHON_PKGNAMEPREFIX}maturin>=0.14:devel/py-maturin@${PY_FLAVOR}

USES=		cargo python
USE_PYTHON=	autoplist concurrent pep517

CARGO_BUILD=	no
CARGO_INSTALL=	no
MAKE_ENV=	RUSTFLAGS="-L ${LOCALBASE}/lib"

.include <bsd.port.mk>
