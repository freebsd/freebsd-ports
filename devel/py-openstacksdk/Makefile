# Created by: Alexander Nusov <alexander.nusov@nfvexpress.com>
# $FreeBSD$

PORTNAME=	openstacksdk
PORTVERSION=	0.9.10
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	alexander.nusov@nfvexpress.com
COMMENT=	Unified SDK for OpenStack

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=1.8:devel/py-pbr
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=1.9.0:devel/py-six \
		${PYTHON_PKGNAMEPREFIX}stevedore>=1.17.1:devel/py-stevedore \
		${PYTHON_PKGNAMEPREFIX}keystoneauth1>=2.14.0:devel/py-keystoneauth1 \
		${PYTHON_PKGNAMEPREFIX}os-client-config>=1.22.0:devel/py-os-client-config

USES=		python
USE_PYTHON=	distutils autoplist noegginfo
NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's,install_requires.*,,' ${WRKSRC}/setup.py

.include <bsd.port.mk>
