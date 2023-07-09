PORTNAME=	flake8-comprehensions
PORTVERSION=	3.13.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	flake8_comprehensions-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	flake8 plugin to help you write better list/set/dict comprehensions
WWW=		https://github.com/adamchainz/flake8-comprehensions

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
