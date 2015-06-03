# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pytest-xdist
PORTVERSION=	1.12
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Py.test plugin for distributed testing

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}execnet>=1.1:${PORTSDIR}/sysutils/py-execnet \
		${PYTHON_PKGNAMEPREFIX}pytest>=2.4.2:${PORTSDIR}/devel/py-pytest \
		${PYTHON_PKGNAMEPREFIX}py>=1.4.22:${PORTSDIR}/devel/py-py
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=2.5.1:${PORTSDIR}/devel/py-pytest \
		${PYTHON_PKGNAMEPREFIX}pexpect>0:${PORTSDIR}/misc/py-pexpect

USES=		python
USE_PYTHON=	autoplist distutils

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} -m pytest

.include <bsd.port.mk>
