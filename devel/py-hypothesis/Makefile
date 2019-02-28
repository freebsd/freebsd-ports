# Created by: Brendan Molloy <brendan+freebsd@bbqsrc.net>
# $FreeBSD$

PORTNAME=	hypothesis
PORTVERSION=	4.7.5
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library for property based testing

LICENSE=	MPL20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}attrs>=16.0.0:devel/py-attrs@${PY_FLAVOR} \
		${PY_ENUM34} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

do-test:
	@(cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test)

.include <bsd.port.mk>
