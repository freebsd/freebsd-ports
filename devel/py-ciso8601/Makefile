PORTNAME=	ciso8601
DISTVERSIONPREFIX=	v
DISTVERSION=	2.2.0
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ygy@FreeBSD.org
COMMENT=	Fast ISO8601 date time parser for Python written in C

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>=0:devel/py-nose@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=0:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}unittest2>=0:devel/py-unittest2@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

USE_GITHUB=	yes
GH_ACCOUNT=	closeio

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/ciso8601*.so

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m nose -v

.include <bsd.port.mk>
