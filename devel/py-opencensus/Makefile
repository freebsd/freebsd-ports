# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	opencensus
PORTVERSION=	0.7.13
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Stats collection and distributed tracing framework

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}google-api-core>=1.0.0<2.0.0:www/py-google-api-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opencensus-context>=0.1.2:devel/py-opencensus-context@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
