# Created by: Craig Leres <leres@FreeBSD.org>

PORTNAME=	flynt
PORTVERSION=	0.76
PORTREVISION=	1
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	leres@FreeBSD.org
COMMENT=	Convert Python scripts from string formatting to f-strings

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}astor>0:devel/py-astor@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tomli>1.1.0:textproc/py-tomli@${PY_FLAVOR}

USES=		python:3.6+
USE_GITHUB=	yes
USE_PYTHON=	autoplist distutils

GH_ACCOUNT=	ikamensh

.include <bsd.port.mk>
