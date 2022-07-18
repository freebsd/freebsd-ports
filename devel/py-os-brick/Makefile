# Created by: Alexander Nusov <alexander.nusov@nfvexpress.com>

PORTNAME=	os-brick
PORTVERSION=	5.2.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	OpenStack Cinder brick library for managing local volume attaches

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=2.0.0:devel/py-pbr@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}eventlet>=0.30.1:net/py-eventlet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}os-win>=5.5.0:devel/py-os-win@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.concurrency>=4.5.0:devel/py-oslo.concurrency@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.context>=3.4.0:devel/py-oslo.context@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.i18n>=5.1.0:devel/py-oslo.i18n@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.log>=4.4.0:devel/py-oslo.log@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.privsep>=2.6.2:devel/py-oslo.privsep@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.serialization>=4.2.0:devel/py-oslo.serialization@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.service>=2.8.0:devel/py-oslo.service@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.utils>=4.12.1:devel/py-oslo.utils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pbr>=5.8.0:devel/py-pbr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.25.1:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tenacity>=6.3.1:devel/py-tenacity@${PY_FLAVOR}

USES=		python:3.8+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes
REINPLACE_ARGS=	-i ''

post-patch:
	@${REINPLACE_CMD} -e '/etc\//d' ${WRKSRC}/setup.cfg
	@${GREP} -lr '/etc/' ${WRKSRC}/etc ${WRKSRC}/os_brick | ${XARGS} -J % ${REINPLACE_CMD} -e 's|/etc/|${PREFIX}&|g' %

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}/rootwrap.d
	${INSTALL_DATA} ${WRKSRC}/etc/os-brick/rootwrap.d/os-brick.filters ${STAGEDIR}${ETCDIR}/rootwrap.d/os-brick.filters.sample

.include <bsd.port.mk>
