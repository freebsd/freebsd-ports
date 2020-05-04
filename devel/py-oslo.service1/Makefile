# Created by: Alexander Nusov <alexander.nusov@nfvexpress.com>
# $FreeBSD$

PORTNAME=	oslo.service
PORTVERSION=	1.41.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	1

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Oslo.service library

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=2.0.0:devel/py-pbr@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}debtcollector>=1.2.0:devel/py-debtcollector@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}eventlet>=0.18.2:net/py-eventlet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fixtures>=0:devel/py-fixtures@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}greenlet>=0.4.10:devel/py-greenlet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.i18n>=3.15.3:devel/py-oslo.i18n@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.log>=3.36.0:devel/py-oslo.log@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.utils>=3.40.2:devel/py-oslo.utils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Paste>=2.0.2:www/py-paste@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}PasteDeploy>=1.5.0:www/py-pastedeploy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}routes>=2.3.1:www/py-routes@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.10.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}webob>=1.7.1:www/py-webob@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yappi>=1.0:devel/py-yappi@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

# oslo.service 2.0.0+ requires Python 3.6+
PORTSCOUT=	limit:^1\.

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3300
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}monotonic>=0.6:devel/py-monotonic@${PY_FLAVOR}
.endif

.if ${PYTHON_REL} < 3600
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}oslo.concurrency3>=3.25.0:devel/py-oslo.concurrency3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.config7>=5.1.0:devel/py-oslo.config7@${PY_FLAVOR}
.else
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}oslo.concurrency>=3.25.0:devel/py-oslo.concurrency@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.config>=5.1.0:devel/py-oslo.config@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
