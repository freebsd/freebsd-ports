PORTNAME=	xstatic-d3
PORTVERSION=	3.5.17.0
PORTREVISION=	4
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	XStatic-D3-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	D3 (Data-Driven Documents) (XStatic packaging standard)
WWW=		https://d3js.org/ \
		https://github.com/openstack/xstatic-d3

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
