# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	pipenv
PORTVERSION=	2021.5.29
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python Development Workflow for Humans

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}invoke>=0:devel/py-invoke@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}parver>=0:devel/py-parver@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}certifi>=0:security/py-certifi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pip>=18.0:devel/py-pip@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}virtualenv>=0:devel/py-virtualenv@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}virtualenv-clone>=0.2.5:devel/py-virtualenv-clone@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
