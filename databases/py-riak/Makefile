# Created by: TJ Ninneman <tj@harperdog.com>
# $FreeBSD$

PORTNAME=	riak
DISTVERSION=	2.1.0rc1
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Python client for Riak

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}riak_pb>=2.0.0:devel/py-riak_pb@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openssl>=0.14:security/py-openssl@${PY_FLAVOR}

USES=		python:2.7
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
