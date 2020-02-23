# Created by: Douglas Thrift <douglas@douglasthrift.net>
# $FreeBSD$

PORTNAME=	gitosis
PORTVERSION=	0.3
DISTVERSIONPREFIX=	release/
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	douglas@douglasthrift.net
COMMENT=	Software for hosting git repositories

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

RUN_DEPENDS=	git:devel/git
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nose>0:devel/py-nose@${PY_FLAVOR}

USES=		python:2.7
USE_PYTHON=	distutils autoplist
USE_GITHUB=	yes
GH_ACCOUNT=	tv42

NO_ARCH=	yes

USERS=		git
GROUPS=		${USERS}

do-test:
	cd ${WRKSRC} && ${PYTHON_CMD} -m pytest -v -s gitosis/test/

.include <bsd.port.mk>
