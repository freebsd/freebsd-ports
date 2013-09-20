# $FreeBSD$

PORTNAME=	gevent-zeromq
PORTVERSION=	0.2.5
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${PORTVERSION}

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Gevent compatibility layer for pyzmq

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/Cython/__init__.py:${PORTSDIR}/lang/cython
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gevent/__init__.py:${PORTSDIR}/devel/py-gevent \
	${PYTHON_SITELIBDIR}/zmq/__init__.py:${PORTSDIR}/devel/py-pyzmq

USE_PYTHON=	2.7
USE_PYDISTUTILS=	yes

# Avoid warning
NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|install_requires|#install_requires|' \
		${WRKSRC}/setup.py

.include <bsd.port.mk> 
