PORTNAME=	pyproject-fmt
PORTVERSION=	2.6.0
PORTREVISION=	3
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	pyproject_fmt-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Format your pyproject.toml file
WWW=		https://github.com/tox-dev/toml-fmt/tree/main/pyproject-fmt \
		https://github.com/tox-dev/toml-fmt

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}maturin>=1.8.4:devel/py-maturin@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}toml-fmt-common>=1.0.1<1.0.1_99:devel/py-toml-fmt-common@${PY_FLAVOR}

USES=		cargo python:3.9+
USE_PYTHON=	autoplist concurrent pep517

CARGO_BUILD=	no
CARGO_INSTALL=	no
WRKSRC=		${WRKDIR}/pyproject_fmt-${PORTVERSION}

.include <bsd.port.mk>
