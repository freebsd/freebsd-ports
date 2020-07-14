# $FreeBSD$

PORTNAME=	pendulum
PORTVERSION=	2.1.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Python package to ease datetimes manipulation

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dateutil>=2.6:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=2018.3:devel/py-pytz@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/pendulum/_extensions/_helpers.so
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/pendulum/parsing/_iso8601.so

.include <bsd.port.mk>
