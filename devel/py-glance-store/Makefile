# Created by: Alexander Nusov <alexander.nusov@nfvexpress.com>
# $FreeBSD$

PORTNAME=	glance-store
PORTVERSION=	1.1.0
PORTREVISION=	5
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	glance_store-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	OpenStack Image Service Store Library

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=2.0.0:devel/py-pbr@${PY_FLAVOR}
RUN_DEPENDS=	${PY_ENUM34} \
		${PYTHON_PKGNAMEPREFIX}eventlet>=0.18.2:net/py-eventlet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema>=2.6.0:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}keystoneauth1>=3.4.0:devel/py-keystoneauth1@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.i18n>=3.15.3:devel/py-oslo.i18n@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.serialization>=2.18.0:devel/py-oslo.serialization@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.utils>=3.33.0:devel/py-oslo.utils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-keystoneclient>=3.8.0:net/py-python-keystoneclient@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.14.2:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.10.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}stevedore>=1.20.0:devel/py-stevedore@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

SHEBANG_GLOB=	*.sh

OPTIONS_DEFINE=	CINDER VMWARE
OPTIONS_DEFAULT=CINDER VMWARE
CINDER_DESC=	Storage backend for OpenStack Cinder storage nodes
VMWARE_DESC=	Storage backend for VMware Datastore

CINDER_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}os-brick>=2.2.0:devel/py-os-brick@${PY_FLAVOR}

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3600
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}oslo.concurrency3>=3.26.0:devel/py-oslo.concurrency3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.config7>=5.2.0:devel/py-oslo.config7@${PY_FLAVOR}
.else
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}oslo.concurrency>=3.26.0:devel/py-oslo.concurrency@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.config>=5.2.0:devel/py-oslo.config@${PY_FLAVOR}
.endif

.if ${PORT_OPTIONS:MCINDER}
.if ${PYTHON_REL} < 3600
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}oslo.rootwrap5>=5.8.0:devel/py-oslo.rootwrap5@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-cinderclient5>=3.3.0:net/py-python-cinderclient5@${PY_FLAVOR}
.else
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}oslo.rootwrap>=5.8.0:devel/py-oslo.rootwrap@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-cinderclient>=3.3.0:net/py-python-cinderclient@${PY_FLAVOR}
.endif
.endif

.if ${PORT_OPTIONS:MVMWARE}
.if ${PYTHON_REL} < 3600
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}oslo.privsep1>=1.23.0:devel/py-oslo.privsep1@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.vmware2>=2.17.0:devel/py-oslo.vmware2@${PY_FLAVOR}
.else
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}oslo.privsep>=1.23.0:devel/py-oslo.privsep@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.vmware>=2.17.0:devel/py-oslo.vmware@${PY_FLAVOR}
.endif
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/glance/|${PREFIX}&|' ${WRKSRC}/etc/glance/rootwrap.conf ${WRKSRC}/glance_store/_drivers/cinder.py ${WRKSRC}/glance_store/tests/unit/test_cinder_store.py
	@${REINPLACE_CMD} -e 's|/etc/ssl/|${PREFIX}&|' ${WRKSRC}/glance_store/_drivers/swift/store.py ${WRKSRC}/glance_store/_drivers/vmware_datastore.py

.include <bsd.port.post.mk>
