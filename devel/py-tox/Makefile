# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tox
PORTVERSION=	2.3.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Virtualenv-based automation of test activities

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}virtualenv>=1.11.2:devel/py-virtualenv \
		${PYTHON_PKGNAMEPREFIX}py>=1.4.17:devel/py-py \
		${PYTHON_PKGNAMEPREFIX}pluggy>0:devel/py-pluggy

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tox>0:devel/py-tox \
		${PYTHON_PKGNAMEPREFIX}pytest>=2.3.5:devel/py-pytest \
		${PYTHON_PKGNAMEPREFIX}pytest-timeout>0:devel/py-pytest-timeout

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_VER} != 2.7 && ${PYTHON_VER} < 3.2
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}argparse>0:devel/py-argparse
.endif

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.post.mk>
