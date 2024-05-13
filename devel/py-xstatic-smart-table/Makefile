PORTNAME=	xstatic-smart-table
PORTVERSION=	1.4.13.2
PORTREVISION=	4
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	XStatic-smart-table-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	smart-table (XStatic packaging standard)
WWW=		https://github.com/openstack/xstatic-angular-smart-table \
		https://github.com/lorenzofox3/Smart-Table

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
