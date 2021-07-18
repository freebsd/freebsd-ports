# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>

PORTNAME=	aiorpcX
PORTVERSION=	0.22.1
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Generic async RPC implementation, including JSON-RPC

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}attrs>=0:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}websockets>=0:devel/py-websockets@${PY_FLAVOR}

USES=		python:3.8+
USE_PYTHON=	autoplist distutils

CONFLICTS_INSTALL=	py[0-9]*-aiorpcX-legacy

NO_ARCH=	yes

.include <bsd.port.mk>
