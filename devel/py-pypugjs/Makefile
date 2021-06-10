PORTNAME=	pypugjs
PORTVERSION=	5.9.9
CATEGORIES=	devel lang python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PugJS syntax adapter for Django, Jinja2 and Mako templates

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}chardet>=0,1:textproc/py-chardet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
