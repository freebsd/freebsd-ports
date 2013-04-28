# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tox
PORTVERSION=	1.4.3
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Python virtualenv-based automation of test activities

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}virtualenv>=1.8.4:${PORTSDIR}/devel/py-virtualenv \
		${PYTHON_PKGNAMEPREFIX}pylib>=1.4.12:${PORTSDIR}/devel/py-pylib

USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install

OPTIONS_DEFINE=	PYTEST
PYTEST_DESC=	Include the Pytest test runner
OPTIONSFILE?=	${PORT_DBDIR}/py-${PORTNAME}/options

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPYTEST}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pytest>0:${PORTSDIR}/devel/py-pytest
.endif

.include <bsd.port.pre.mk>

.if ${PYTHON_VER} <= 3.2
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}argparse>0:${PORTSDIR}/devel/py-argparse
.endif

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} test

.include <bsd.port.post.mk>
