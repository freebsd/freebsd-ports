PORTNAME=	xstatic-jquery.tablesorter
PORTVERSION=	2.14.5.3
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	xstatic_jquery_tablesorter-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	JQuery.TableSorter ${PORTVERSION:R} (XStatic packaging standard)
WWW=		https://opendev.org/openstack/xstatic-jquery.tablesorter \
		https://github.com/openstack/xstatic-jquery.tablesorter

LICENSE=	GPLv2 MIT
LICENSE_COMB=	dual

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
