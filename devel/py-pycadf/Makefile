PORTNAME=	pycadf
PORTVERSION=	3.1.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	CADF Library

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=2.0.0:devel/py-pbr@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}debtcollector>=1.2.0:devel/py-debtcollector@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.config>=5.2.0:devel/py-oslo.config@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.serialization>=2.18.0:devel/py-oslo.serialization@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pbr>=2.0.0:devel/py-pbr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=2013.6,1:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.10.0:devel/py-six@${PY_FLAVOR}

USES=		cpe python:3.8+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

CPE_VENDOR=	openstack

post-patch:
	@${REINPLACE_CMD} -e 's|^data_files|no_&|' ${WRKSRC}/setup.cfg

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
.for service in ceilometer cinder glance neutron nova swift trove
	${INSTALL_DATA} ${WRKSRC}/etc/pycadf/${service}_api_audit_map.conf ${STAGEDIR}${ETCDIR}/${service}_api_audit_map.conf.sample
.endfor

.include <bsd.port.mk>
