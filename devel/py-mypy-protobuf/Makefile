# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	mypy-protobuf
PORTVERSION=	2.7
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Generate mypy stub files from protobuf specs

LICENSE=	APACHE20

RUN_DEPENDS=	protobuf>=3.17.3,1:devel/protobuf \
		${PYTHON_PKGNAMEPREFIX}protobuf>=3.17.3,1:devel/py-protobuf@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
