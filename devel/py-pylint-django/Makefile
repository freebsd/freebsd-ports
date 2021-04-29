# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	pylint-django
PORTVERSION=	2.4.4
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Pylint plugin to understand the Django web framework

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pylint-plugin-utils>=0.5:devel/py-pylint-plugin-utils@${PY_FLAVOR} \
		pylint${PYTHON_PKGNAMESUFFIX}>=2.0:devel/pylint@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
