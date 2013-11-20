# Created by: Michael Johnson <ahze@ahze.net>
# $FreeBSD$

PORTNAME=	memcached
PORTVERSION=	1.53
CATEGORIES=	databases python
MASTER_SITES=	http://ftp.tummy.com/pub/python-memcached/ \
		http://ftp.tummy.com/pub/python-memcached/old-releases/ \
		ftp://ftp.tummy.com/pub/python-memcached/ \
		ftp://ftp.tummy.com/pub/python-memcached/old-releases/ \
		LOCAL/sunpoet
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-${PORTNAME}-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python API for memcached, a distributed memory cache daemon

USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install
PYDISTUTILS_PKGNAME=	python-memcached

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

.include <bsd.port.mk>
