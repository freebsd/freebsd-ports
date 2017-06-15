# $FreeBSD$

PORTNAME=	apscheduler
PORTVERSION=	3.3.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	APScheduler-${DISTVERSION}

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	In-process task scheduler with Cron-like capabilities

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>0:devel/py-setuptools_scm
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytz>0:devel/py-pytz \
		${PYTHON_PKGNAMEPREFIX}six>=1.4.0:devel/py-six \
		${PYTHON_PKGNAMEPREFIX}tzlocal>=1.2:devel/py-tzlocal
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=2.5.1:devel/py-pytest \
		${PYTHON_PKGNAMEPREFIX}pytest-capturelog>=0.7:devel/py-pytest-capturelog

NO_ARCH=	yes
USES=		python:2.7+
USE_PYTHON=	autoplist distutils
TEST_ENV=	${MAKE_ENV} TZ=UTC

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3300
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}futures>0:devel/py-futures \
		${PYTHON_PKGNAMEPREFIX}funcsigs>0:devel/py-funcsigs
TEST_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock
.else
TEST_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pytest-asyncio>0:devel/py-pytest-asyncio \
		${PYTHON_PKGNAMEPREFIX}pytest-tornado>0:devel/py-pytest-tornado
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/ --cov//' ${WRKSRC}/${PYSETUP:R}.cfg
	@${REINPLACE_CMD} -e 's/set_level/setLevel/' \
		-e 's/\.records/&()/' \
		-e '/records/s/== 1/== 2/' \
		-e '/message/s/\[0]./[1]./' \
		${WRKSRC}/tests/test_schedulers.py

do-test:
	@(cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest)

.include <bsd.port.post.mk>
