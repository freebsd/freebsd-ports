# Created by: db

PORTNAME=	ephem
PORTVERSION=	4.1.1
CATEGORIES=	astro math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rhurlin@FreeBSD.org
COMMENT=	Compute positions of the planets and stars

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python:3.7+ # Because of UnicodeDecodeError in ascii.py
USE_PYTHON=	autoplist distutils

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/ephem/_libastro${PYTHON_EXT_SUFFIX}.so

do-test:
	# WARNING: Testing via this command is deprecated and will be
	# removed in a future version. Users looking for a generic test
	# entry point independent of test runner are encouraged to use tox.
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
