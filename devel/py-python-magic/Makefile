# Created by: Kubilay Kocak <koobs@FreeBSD.org>

PORTNAME=	python-magic
PORTVERSION=	0.4.25
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	File type identification using libmagic

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	ahupp

do-test:
	cd ${WRKSRC} && ${SETENV} LC_ALL=en_US.UTF-8 PYTHONPATH=${STAGEDIR}${PYTHON_SITELIBDIR} ${PYTHON_CMD} -m unittest -v

.include <bsd.port.mk>
