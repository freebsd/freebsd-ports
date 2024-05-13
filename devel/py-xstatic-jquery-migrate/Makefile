PORTNAME=	xstatic-jquery-migrate
PORTVERSION=	3.3.2.1
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	XStatic-JQuery-Migrate-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	JQuery-Migrate (XStatic packaging standard)
WWW=		https://github.com/openstack/xstatic-jquery-migrate \
		https://github.com/jquery/jquery-migrate

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
