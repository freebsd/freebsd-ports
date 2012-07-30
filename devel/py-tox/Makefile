# New ports collection makefile for:	py-tox
# Date created:		2012-07-19
# Whom:			Kubilay Kocak <koobs.freebsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	tox
PORTVERSION=	1.4.2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs.freebsd@gmail.com
COMMENT=	Python virtualenv-based automation of test activities

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}virtualenv>=1.7:${PORTSDIR}/devel/py-virtualenv \
		${PYTHON_PKGNAMEPREFIX}pylib>=1.4.9:${PORTSDIR}/devel/py-pylib

USE_ZIP=	YES
USE_PYTHON=	YES
USE_PYDISTUTILS=	easy_install

OPTIONS_DEFINE=	PYTEST
PYTEST_DESC=	Include the Pytest test runner

# Workaround ports infrastructure bug
OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPYTEST}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pytest>0:${PORTSDIR}/devel/py-pytest
.endif

.include <bsd.port.pre.mk>

.if ${PYTHON_VER} <= 3.2
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}argparse>0:${PORTSDIR}/devel/py-argparse
.endif

.include <bsd.port.post.mk>
