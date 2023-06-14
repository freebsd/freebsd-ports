PORTNAME=	ephem
PORTVERSION=	4.1.4
CATEGORIES=	astro math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rhurlin@FreeBSD.org
COMMENT=	Compute positions of the planets and stars
WWW=		https://pypi.org/project/ephem/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python
USE_PYTHON=	autoplist distutils

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/ephem/_libastro${PYTHON_EXT_SUFFIX}.so

do-test:
	# WARNING: Testing via this command is deprecated and will be
	# removed in a future version. Users looking for a generic test
	# entry point independent of test runner are encouraged to use tox.
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
