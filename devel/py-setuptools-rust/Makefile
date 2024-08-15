PORTNAME=	setuptools-rust
PORTVERSION=	1.10.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	setuptools_rust-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Setuptools Rust extension plugin
WWW=		https://setuptools-rust.readthedocs.io/en/latest/ \
		https://github.com/PyO3/setuptools-rust

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=62.4:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	cargo:lang/rust \
		${PYTHON_PKGNAMEPREFIX}semantic-version>=2.8.2<3:devel/py-semantic-version@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=62.4:devel/py-setuptools@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
