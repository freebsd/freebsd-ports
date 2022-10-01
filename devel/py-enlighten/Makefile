PORTNAME=	enlighten
DISTVERSION=	1.11.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Console progress bar module for Python
WWW=		https://github.com/Rockhopper-Technologies/enlighten

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}blessed>=1.17.7:devel/py-blessed@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}prefixed>=0.3.2:devel/py-prefixed@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	distutils autoplist pytest # 9 tests fail, see https://github.com/Rockhopper-Technologies/enlighten/issues/50

NO_ARCH=	yes

.include <bsd.port.mk>
