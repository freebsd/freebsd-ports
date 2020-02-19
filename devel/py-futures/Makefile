# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	futures
PORTVERSION=	3.2.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Backport of the concurrent.futures package from Python 3

LICENSE=	PSFL
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python:2.7
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

# Some tests require 256 semaphores. Set the following sysctl(8)
# before running tests: sysctl p1003_1b.sem_nsems_max=512

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} test_futures.py

.include <bsd.port.mk>
