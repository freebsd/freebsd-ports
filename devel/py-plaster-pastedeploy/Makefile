PORTNAME=	plaster-pastedeploy
PORTVERSION=	1.0.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	plaster_pastedeploy-${PORTVERSION}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Plaster plugin to load PasteDeploy ini files
WWW=		https://github.com/Pylons/plaster_pastedeploy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=41:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pastedeploy>=2.0:www/py-pastedeploy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plaster>=0.5:devel/py-plaster@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
