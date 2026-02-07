PORTNAME=	xstatic-angular-schema-form
PORTVERSION=	0.8.13.0
PORTREVISION=	4
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	XStatic-Angular-Schema-Form-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Angular-Schema-Form (XStatic packaging standard)
WWW=		http://schemaform.io/ \
		https://github.com/openstack-archive/deb-python-xstatic-angular-schema-form

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
