# Created by: Alexander Nusov <alexander.nusov@nfvexpress.com>
# $FreeBSD$

PORTNAME=	oslo.versionedobjects
PORTVERSION=	1.32.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Oslo versioned objects library

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=2.0.0:devel/py-pbr@${FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}iso8601>=0.1.11:devel/py-iso8601@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netaddr>=0.7.18:net/py-netaddr@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.concurrency>=3.25.0:devel/py-oslo.concurrency@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.config>=5.1.0:devel/py-oslo.config@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.context>=2.19.2:devel/py-oslo.context@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.i18n>=3.15.3:devel/py-oslo.i18n@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.log>=3.36.0:devel/py-oslo.log@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.messaging>=5.29.0:devel/py-oslo.messaging@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.serialization>=2.18.0:devel/py-oslo.serialization@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.utils>=3.33.0:devel/py-oslo.utils@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.10.0:devel/py-six@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}webob>=1.7.1:www/py-webob@${FLAVOR}

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist concurrent distutils

.include <bsd.port.mk>
