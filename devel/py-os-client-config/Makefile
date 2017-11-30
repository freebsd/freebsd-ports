# Created by: Alexander Nusov <alexander.nusov@nfvexpress.com>
# $FreeBSD$

PORTNAME=	os-client-config
PORTVERSION=	1.26.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	alexander.nusov@nfvexpress.com
COMMENT=	OpenStack Client Configuation Library

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=1.6:devel/py-pbr@${FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}yaml>=3.1.0:devel/py-yaml@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}appdirs>=1.3.0:devel/py-appdirs@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}keystoneauth1>=2.1.0:devel/py-keystoneauth1@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requestsexceptions>=1.1.1:devel/py-requestsexceptions@${FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist noegginfo
NO_ARCH=	yes

.include <bsd.port.mk>
