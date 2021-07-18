# Created by: Alexander Nusov <alexander.nusov@nfvexpress.com>

PORTNAME=	os-vif
PORTVERSION=	2.5.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	os_vif-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library for plugging and unplugging virtual interfaces in OpenStack

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=2.0.0:devel/py-pbr@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}debtcollector>=1.19.0:devel/py-debtcollector@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netaddr>=0.7.18:net/py-netaddr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.concurrency>=3.20.0:devel/py-oslo.concurrency@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.config>=5.1.0:devel/py-oslo.config@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.i18n>=3.15.3:devel/py-oslo.i18n@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.log>=3.30.0:devel/py-oslo.log@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.privsep>=1.23.0:devel/py-oslo.privsep@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.versionedobjects>=1.28.0:devel/py-oslo.versionedobjects@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ovsdbapp>=0.12.1:devel/py-ovsdbapp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pbr>=2.0.0:devel/py-pbr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyroute2>=0.5.2:net/py-pyroute2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}stevedore>=1.20.0:devel/py-stevedore@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
