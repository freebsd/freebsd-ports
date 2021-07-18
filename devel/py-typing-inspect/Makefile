# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	typing-inspect
PORTVERSION=	0.7.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	typing_inspect-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Runtime inspection utilities for typing module

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mypy_extensions>=0.3.0:devel/py-mypy_extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=3.7.4:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
