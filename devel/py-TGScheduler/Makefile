# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	TGScheduler
PORTVERSION=	1.6.3
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Turbogears Scheduler

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dateutil>=1.5:${PORTSDIR}/devel/py-dateutil
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dateutil>=1.5:${PORTSDIR}/devel/py-dateutil

USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's,<2.0dev,!=2.0,g' ${WRKSRC}/setup.py

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} test

.include <bsd.port.mk>
