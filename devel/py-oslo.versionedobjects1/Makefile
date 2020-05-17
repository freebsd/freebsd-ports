# Created by: Alexander Nusov <alexander.nusov@nfvexpress.com>
# $FreeBSD$

PORTNAME=	oslo.versionedobjects
PORTVERSION=	1.37.0
PORTREVISION=	8
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	1

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Oslo versioned objects library

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=2.0.0:devel/py-pbr@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}iso8601>=0.1.11:devel/py-iso8601@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netaddr>=0.7.18:net/py-netaddr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.10.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}webob>=1.7.1:www/py-webob@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

# oslo.versionedobjects 2.0.0+ requires Python 3.6+
PORTSCOUT=	limit:^1\.

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3600
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}oslo.concurrency3>=3.26.0:devel/py-oslo.concurrency3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.config7>=5.2.0:devel/py-oslo.config7@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.context2>=2.19.2:devel/py-oslo.context2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.i18n3>=3.15.3:devel/py-oslo.i18n3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.log3>=3.36.0:devel/py-oslo.log3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.messaging10>=5.29.0:devel/py-oslo.messaging10@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.serialization2>=2.18.0:devel/py-oslo.serialization2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.utils3>=3.33.0:devel/py-oslo.utils3@${PY_FLAVOR}
.else
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}oslo.concurrency>=3.26.0:devel/py-oslo.concurrency@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.config>=5.2.0:devel/py-oslo.config@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.context>=2.19.2:devel/py-oslo.context@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.i18n>=3.15.3:devel/py-oslo.i18n@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.log>=3.36.0:devel/py-oslo.log@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.messaging>=5.29.0:devel/py-oslo.messaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.serialization>=2.18.0:devel/py-oslo.serialization@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.utils>=3.33.0:devel/py-oslo.utils@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
