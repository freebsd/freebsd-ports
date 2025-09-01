PORTNAME=	pyproject-fmt-rust
PORTVERSION=	1.2.1
PORTREVISION=	8
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	pyproject_fmt_rust-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Format your pyproject.toml file
WWW=		https://github.com/tox-dev/pyproject-fmt-rust

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}maturin>=1.7.1:devel/py-maturin@${PY_FLAVOR}

USES=		cargo python
USE_PYTHON=	autoplist concurrent pep517

CARGO_BUILD=	no
CARGO_INSTALL=	no
WRKSRC=		${WRKDIR}/pyproject_fmt_rust-${PORTVERSION}

.include <bsd.port.mk>
