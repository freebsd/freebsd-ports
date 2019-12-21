# Created by: Vladimir Chukharev
# $FreeBSD$

PORTNAME=	robotframework-pabot
PORTVERSION=	0.94
CATEGORIES=	devel www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	Vladimir.Chukharev@gmail.com
COMMENT=	Parallel executor for Robot Framework test cases

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}robotframework>=2.7.5:devel/py-robotframework@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}robotremoteserver>=1.0.1:devel/py-robotremoteserver@${PY_FLAVOR} \
		${PY_TYPING}

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>0:devel/py-nose@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils
USE_GITHUB=	yes
GH_ACCOUNT=	mkorpela
GH_PROJECT=	pabot

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${SETENV} LC_ALL=en_US.UTF-8 ${PYTHON_CMD} -m nose -v tests

.include <bsd.port.mk>
