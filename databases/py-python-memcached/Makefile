PORTNAME=	python-memcached
PORTVERSION=	1.62
CATEGORIES=	databases python
MASTER_SITES=	PYPI \
		https://github.com/linsomniac/python-memcached/releases/download/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python API for memcached, a distributed memory cache daemon
WWW=		https://github.com/linsomniac/python-memcached

LICENSE=	PSFL
LICENSE_FILE=	${WRKSRC}/PSF.LICENSE

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
