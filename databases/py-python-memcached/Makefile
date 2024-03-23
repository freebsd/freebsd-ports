PORTNAME=	python-memcached
PORTVERSION=	1.62
PORTREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	PYPI \
		https://github.com/linsomniac/python-memcached/releases/download/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python API for memcached, a distributed memory cache daemon
WWW=		https://github.com/linsomniac/python-memcached

LICENSE=	PSFL
LICENSE_FILE=	${WRKSRC}/PSF.LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
