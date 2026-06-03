PORTNAME=	xstatic-smart-table
PORTVERSION=	1.4.13.3
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	xstatic_smart_table-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	smart-table ${PORTVERSION:R} (XStatic packaging standard)
WWW=		https://opendev.org/openstack/xstatic-angular-smart-table \
		https://github.com/openstack/xstatic-angular-smart-table

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
