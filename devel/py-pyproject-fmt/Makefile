PORTNAME=	pyproject-fmt
PORTVERSION=	2.29.4
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	pyproject_fmt-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Format pyproject.toml files
WWW=		https://pyproject-fmt.readthedocs.io/en/latest/ \
		https://github.com/tox-dev/toml-fmt/tree/main/pyproject-fmt \
		https://github.com/tox-dev/toml-fmt

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}maturin>=1.15:devel/py-maturin@${PY_FLAVOR}

USES=		cargo python
USE_PYTHON=	autoplist concurrent pep517

CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no
WRKSRC=		${WRKDIR}/pyproject_fmt-${PORTVERSION}

.include <bsd.port.mk>
