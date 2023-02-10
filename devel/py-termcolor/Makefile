PORTNAME=	termcolor
PORTVERSION=	2.1.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	c.kworr@gmail.com
COMMENT=	ANSII Color formatting for output in terminal
WWW=		https://pypi.org/project/termcolor/

LICENSE=	MIT

USES=		python:3.6+ pytest
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

post-extract:
	@${ECHO_CMD} 'from setuptools import setup; setup()' > ${WRKSRC}/setup.py

.include <bsd.port.mk>
