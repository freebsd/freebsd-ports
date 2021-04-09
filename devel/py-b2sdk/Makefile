PORTNAME=	b2sdk
DISTVERSION=	1.6.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	PopularMoment@protonmail.com
COMMENT=	Backblaze B2 SDK

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>0:devel/py-setuptools_scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}arrow>=0.8.0:devel/py-arrow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}logfury>=0.1.2:devel/py-logfury@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.9.1:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools_scm>0:devel/py-setuptools_scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=4.5.0:misc/py-tqdm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>0:devel/py-nose@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	distutils autoplist concurrent

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 30800
RUN_DEPENDS+= ${PYTHON_PKGNAMEPREFIX}importlib-metadata>=0:devel/py-importlib-metadata@${PY_FLAVOR}
.endif

do-test:
	@cd ${WRKSRC} && ${TOUCH} ${WRKSRC}/test/__init__.py && \
	${PYTHON_CMD} ${PYDISTUTILS_SETUP} nosetests

.include <bsd.port.post.mk>
