PORTNAME=	tox-toml-fmt
PORTVERSION=	1.0.0
PORTREVISION=	7
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	tox_toml_fmt-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Format your pyproject.toml file
WWW=		https://github.com/tox-dev/toml-fmt/tree/main/tox-toml-fmt \
		https://github.com/tox-dev/toml-fmt

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}maturin>=1.7.4:devel/py-maturin@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}toml-fmt-common>=1.0.1<1.0.1_99:devel/py-toml-fmt-common@${PY_FLAVOR}

USES=		cargo python:3.9+
USE_PYTHON=	autoplist concurrent pep517

CARGO_BUILD=	no
CARGO_INSTALL=	no
WRKSRC=		${WRKDIR}/tox_toml_fmt-${PORTVERSION}

.include <bsd.port.mk>
