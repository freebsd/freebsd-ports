PORTNAME=	sqlglot
PORTVERSION=	26.25.3
CATEGORIES=	databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Easily customizable SQL parser and transpiler
WWW=		https://sqlglot.com/sqlglot.html \
		https://github.com/tobymao/sqlglot

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	RS
RS_DESC=	SQL parser and transpiler in Rust

RS_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}sqlglotrs>=0.6.1<0.6.1_99:databases/py-sqlglotrs@${PY_FLAVOR}

.include <bsd.port.mk>
