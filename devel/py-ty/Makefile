PORTNAME=	ty
DISTVERSION=	0.0.1a21
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Extremely fast Python type checker, written in Rust
WWW=		https://github.com/astral-sh/ty

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}maturin>=1.0<2.0:devel/py-maturin@${PY_FLAVOR}
LIB_DEPENDS=	libzstd.so:archivers/zstd

USES=		cargo python

USE_PYTHON=	autoplist concurrent pep517

CARGO_CARGOTOML=${WRKSRC}/ruff/Cargo.toml
CARGO_CARGOLOCK=${WRKSRC}/ruff/Cargo.lock
CARGO_BUILD=	no
CARGO_INSTALL=	no

MAKE_ENV=	${CARGO_ENV}

PORTSCOUT=	limit:^[0-9]\.

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
