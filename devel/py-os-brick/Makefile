# Created by: Alexander Nusov <alexander.nusov@nfvexpress.com>
# $FreeBSD$

PORTNAME=	os-brick
PORTVERSION=	1.8.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	alexander.nusov@nfvexpress.com
COMMENT=	Openstack cinder brick library for managing local volume attaches

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=1.6:devel/py-pbr
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}os-win>=0.2.3:devel/py-os-win \
		${PYTHON_PKGNAMEPREFIX}castellan>=0.4.0:devel/py-castellan \
		${PYTHON_PKGNAMEPREFIX}six>=1.9.0:devel/py-six \
		${PYTHON_PKGNAMEPREFIX}retrying>=0:devel/py-retrying \
		${PYTHON_PKGNAMEPREFIX}requests>=2.10.0:www/py-requests \
		${PYTHON_PKGNAMEPREFIX}oslo.utils>=3.17.0:devel/py-oslo.utils \
		${PYTHON_PKGNAMEPREFIX}oslo.service>=1.10.0:devel/py-oslo.service \
		${PYTHON_PKGNAMEPREFIX}oslo.privsep>=1.9.0:devel/py-oslo.privsep \
		${PYTHON_PKGNAMEPREFIX}oslo.i18n>=2.1.0:devel/py-oslo.i18n \
		${PYTHON_PKGNAMEPREFIX}oslo.serialization>=1.10.0:devel/py-oslo.serialization \
		${PYTHON_PKGNAMEPREFIX}oslo.log>=3.11.0:devel/py-oslo.log \
		${PYTHON_PKGNAMEPREFIX}oslo.concurrency>=3.8.0:devel/py-oslo.concurrency \
		${PYTHON_PKGNAMEPREFIX}eventlet>=0:net/py-eventlet \
		${PYTHON_PKGNAMEPREFIX}Babel>=2.3.4:devel/py-babel

NO_ARCH=	yes

USES=		python
USE_PYTHON=	autoplist distutils

post-patch:
	@${ECHO_CMD} "os-brick configuration at ${PREFIX}/etc/os-brick/rootwrap.d" >> \
		${WRKSRC}/etc/os-brick.readme
	@${ECHO_CMD} "os-brick configuration" >> ${WRKSRC}/etc/os-brick/info

.include <bsd.port.mk>
