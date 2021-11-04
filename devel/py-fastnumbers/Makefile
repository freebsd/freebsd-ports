PORTNAME=	fastnumbers
DISTVERSION=	3.2.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Super-fast and clean conversions to numbers

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	autoplist distutils

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/fastnumbers/fastnumbers*.so

do-test: install # requires pytest higher than 4.6.11, otherwise tests fail, see bug#259648
	@cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest

.include <bsd.port.mk>
