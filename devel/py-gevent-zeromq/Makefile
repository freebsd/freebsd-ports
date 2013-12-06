# $FreeBSD$

PORTNAME=	gevent-zeromq
PORTVERSION=	0.2.5
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${PORTVERSION}

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Gevent compatibility layer for pyzmq

BUILD_DEPENDS=	cython:${PORTSDIR}/lang/cython
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gevent>=1.0:${PORTSDIR}/devel/py-gevent \
	${PYTHON_PKGNAMEPREFIX}pyzmq>=14.0.1:${PORTSDIR}/devel/py-pyzmq

IGNORE=	Does not run properly with devel/py-pyzmq >= 13.0
DEPRECATED=	devel/py-pyzmq has gevent support built in
EXPIRATION_DATE=	2014-01-06

USE_PYTHON=	2.7
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

# Avoid warning
post-patch:
	@${REINPLACE_CMD} -e 's|install_requires|#install_requires|' \
		${WRKSRC}/setup.py

.include <bsd.port.mk> 
