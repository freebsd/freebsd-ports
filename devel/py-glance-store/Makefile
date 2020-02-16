# Created by: Alexander Nusov <alexander.nusov@nfvexpress.com>
# $FreeBSD$

PORTNAME=	glance-store
PORTVERSION=	0.23.0
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	glance_store-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	OpenStack Image Service Store Library

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=2.0.0:devel/py-pbr@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}oslo.config>=5.1.0:devel/py-oslo.config@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.i18n>=3.15.3:devel/py-oslo.i18n@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.serialization>=2.18.0:devel/py-oslo.serialization@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.utils>=3.33.0:devel/py-oslo.utils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.concurrency>=3.25.0:devel/py-oslo.concurrency@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}stevedore>=1.20.0:devel/py-stevedore@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}eventlet>=0.18.2:net/py-eventlet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.10.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema>=2.6.0:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}keystoneauth1>=3.3.0:devel/py-keystoneauth1@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-keystoneclient>=3.8.0:net/py-python-keystoneclient@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.14.2:www/py-requests@${PY_FLAVOR} \
		${PY_ENUM34}

USES=		python shebangfix
USE_PYTHON=	autoplist concurrent distutils
SHEBANG_FILES=	glance_store/tests/functional/hooks/post_test_hook.sh \
		glance_store/tests/functional/hooks/gate_hook.sh

NO_ARCH=	yes

OPTIONS_DEFINE=		CINDER VMWARE
OPTIONS_DEFAULT=	CINDER VMWARE

CINDER_DESC=	Storage backend for OpenStack Cinder storage nodes
VMWARE_DESC=	Storage backend for VMware Datastore

CINDER_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}os-brick>=2.3.4:devel/py-os-brick@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}oslo.rootwrap>=5.8.0:devel/py-oslo.rootwrap@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}oslo.privsep>=1.23.0:devel/py-oslo.privsep@${PY_FLAVOR}
VMWARE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}oslo.vmware>=2.17.0:devel/py-oslo.vmware@${PY_FLAVOR}

post-patch:
	@${REINPLACE_CMD} -Ee 's,(/etc/)(ceph|glance|ssl),${PREFIX}\1\2,g' \
		${WRKSRC}/glance_store/_drivers/cinder.py \
		${WRKSRC}/glance_store/_drivers/rbd.py \
		${WRKSRC}/glance_store/_drivers/swift/store.py \
		${WRKSRC}/glance_store/_drivers/vmware_datastore.py \
		${WRKSRC}/glance_store/tests/unit/test_cinder_store.py

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MCINDER}
.if ${PYTHON_REL} < 3600
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}python-cinderclient5>=3.3.0:net/py-python-cinderclient5@${PY_FLAVOR}
.else
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}python-cinderclient>=3.3.0:net/py-python-cinderclient@${PY_FLAVOR}
.endif
.endif

.include <bsd.port.post.mk>
