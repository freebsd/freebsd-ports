PORTNAME=	xstatic-mdi
PORTVERSION=	1.6.50.2
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	XStatic-mdi-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	mdi (Material Design Icons) (XStatic packaging standard)
WWW=		https://pictogrammers.com/library/mdi/ \
		https://github.com/openstack/xstatic-mdi

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
