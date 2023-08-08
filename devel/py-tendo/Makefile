PORTNAME=	tendo
PORTVERSION=	0.3.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Basic functionality that is not provided by Python
WWW=		https://github.com/pycontribs/tendo

LICENSE=	PSFL
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

post-patch:
	${ECHO} "from setuptools import setup ; setup()" > ${WRKSRC}/setup.py

.include <bsd.port.mk>
