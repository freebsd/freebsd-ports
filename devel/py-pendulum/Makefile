# $FreeBSD$

PORTNAME=	pendulum
PORTVERSION=	2.0.4
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Python package to ease datetimes manipulation

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/pendulum/_extensions/_helpers.so
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/pendulum/parsing/_iso8601.so

.include <bsd.port.mk>
