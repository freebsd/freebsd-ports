# Created by: Kubilay Kocak <koobs@FreeBSD.org>

PORTNAME=	python-magic
PORTVERSION=	0.4.15
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	File type identification using libmagic

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python:3.6+
USE_GITHUB=	yes # missing test data files
USE_PYTHON=	autoplist distutils

GH_ACCOUNT=	ahupp

# both install module as magic.py
CONFLICTS=	${PYTHON_PKGNAMEPREFIX}magic

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
