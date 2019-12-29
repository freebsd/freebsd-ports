# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cachecontrol
PORTVERSION=	0.12.6
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	CacheControl-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	httplib2 caching for requests

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}msgpack>=0.5.2:devel/py-msgpack@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	LOCKFILE REDIS
OPTIONS_DEFAULT=LOCKFILE
LOCKFILE_DESC=	Lockfile support
REDIS_DESC=	Redis support

LOCKFILE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lockfile>=0.9:devel/py-lockfile@${PY_FLAVOR}
REDIS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}redis>=2.10.5:databases/py-redis@${PY_FLAVOR}

.include <bsd.port.mk>
