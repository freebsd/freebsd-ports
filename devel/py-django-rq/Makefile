# Created by: René Ladan <rene@freebsd.org>
# $FreeBSD$

PORTNAME=	django-rq
PORTVERSION=	1.3
DISTVERSIONPREFIX=	v
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rene@FreeBSD.org
COMMENT=	Provides Django integration for RQ (Redis Queue)

LICENSE=	MIT

USES=		python
USE_PYTHON=	autoplist distutils
USE_GITHUB=	yes
GH_ACCOUNT=	rq

TEST_DEPENDS=	redis-server:databases/redis \
		${PYTHON_PKGNAMEPREFIX}coverage>=0:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docutils>=0:textproc/py-docutils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>=0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=0:devel/py-yaml@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django111>0:www/py-django111@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rq>=0.12.0:devel/py-rq@${PY_FLAVOR}

NO_ARCH=	yes

post-patch:
	${REINPLACE_CMD} 's/coverage/coverage-${PYTHON_VERSION:S/python//}/' \
	    ${WRKSRC}/Makefile

do-test:
	cd ${WRKSRC} && ${TEST_ENV} ${MAKE} ${TEST_ARGS}

.include <bsd.port.mk>
