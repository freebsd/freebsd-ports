PORTNAME=	pex
PORTVERSION=	2.101.6
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	PEX packaging toolchain
WWW=		https://pex.readthedocs.org/en/latest/

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}wheel>=0.24.0:devel/py-wheel@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	autoplist distutils

# Vendored pip/setuptools console scripts use a "#!python" placeholder.
python_OLD_CMD+=	python
SHEBANG_FILES=	pex/vendor/_vendored/*/.prefix/bin/*

.include <bsd.port.mk>
