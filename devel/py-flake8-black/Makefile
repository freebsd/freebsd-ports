PORTNAME=	flake8-black
PORTVERSION=	0.3.4
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	flake8 plugin to call black as a code style validator
WWW=		https://github.com/peterjc/flake8-black

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}black>=22.1.0:devel/py-black@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flake8>=3:devel/py-flake8@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tomli>=0:textproc/py-tomli@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

post-patch:
	@${CP} ${FILESDIR}/setup.py ${WRKSRC}/

.include <bsd.port.mk>
