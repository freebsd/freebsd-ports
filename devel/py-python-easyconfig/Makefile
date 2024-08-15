PORTNAME=	python-easyconfig
PORTVERSION=	0.1.7
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Python-EasyConfig-${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Library for loading configurations easily in Python
WWW=		https://github.com/RussellLuo/easyconfig

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyyaml>3.10:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>1.9.0:devel/py-six@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
