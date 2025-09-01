PORTNAME=	pendulum
PORTVERSION=	3.1.0
PORTREVISION=	3
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	pendulum-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python package to ease datetimes manipulation
WWW=		https://pendulum.eustace.io/ \
		https://pendulum.eustace.io/docs/ \
		https://github.com/python-pendulum/pendulum

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}maturin>=1.0<2.0:devel/py-maturin@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-dateutil>=2.6:devel/py-python-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}time-machine>=2.6.0:devel/py-time-machine@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tzdata>=2020.1:devel/py-tzdata@${PY_FLAVOR}

USES=		cargo python
USE_PYTHON=	autoplist concurrent pep517

CARGO_BUILD=	no
CARGO_CARGOLOCK=${WRKSRC}/rust/Cargo.lock
CARGO_CARGOTOML=${WRKSRC}/rust/Cargo.toml
CARGO_INSTALL=	no

.include <bsd.port.mk>
