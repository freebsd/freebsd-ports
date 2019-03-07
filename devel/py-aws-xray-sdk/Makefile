# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	aws-xray-sdk
PORTVERSION=	2.4.2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	AWS X-Ray SDK for Python

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}botocore>=1.11.3:devel/py-botocore@${PY_FLAVOR} \
		${PY_ENUM34} \
		${PYTHON_PKGNAMEPREFIX}future>=0:devel/py-future@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonpickle>=0:devel/py-jsonpickle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wrapt>=0:devel/py-wrapt@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes
USE_LOCALE=	en_US.UTF-8

.include <bsd.port.mk>
