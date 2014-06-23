# Created by: Sofian Brabez <sbz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	phabricator
PORTVERSION=	0.4.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Phabricator API Bindings

LICENSE=	APACHE20

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

OPTIONS_DEFINE=	PYTEST
PYTEST_DESC=	Install Python test dependency

PYTEST_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mock>0:${PORTSDIR}/devel/py-mock

regression-test: extract
	${PYTHON_CMD} ${WRKSRC}/${PORTNAME}/tests.py

.include <bsd.port.mk>
