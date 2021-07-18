# Created by: Rainer Hurling <rhurlin@gwdg.de>

PORTNAME=	pyls-black
PORTVERSION=	0.4.7
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rhurlin@FreeBSD.org
COMMENT=	Black plugin for the Python Language Server

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}black>0:devel/py-black@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
