# Created by: Craig Leres <leres@FreeBSD.org>
# $FreeBSD$

PORTNAME=	flynt
PORTVERSION=	0.52
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	leres@FreeBSD.org
COMMENT=	Convert Python scripts from string formatting to f-strings

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}astor>0:devel/py-astor@${PY_FLAVOR}

USES=		python:3.6+
USE_GITHUB=	yes
USE_PYTHON=	autoplist distutils

GH_ACCOUNT=	ikamensh

post-patch:
	${REINPLACE_CMD} -e 's/0\.49/0.50/' ${WRKSRC}/src/flynt/__init__.py

.include <bsd.port.mk>
