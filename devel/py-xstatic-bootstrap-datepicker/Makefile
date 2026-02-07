PORTNAME=	xstatic-bootstrap-datepicker
PORTVERSION=	1.4.0.0
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	XStatic-Bootstrap-Datepicker-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Datepicker for Bootstrap (bootstrap-datepicker)
WWW=		https://github.com/openstack/xstatic-bootstrap-datepicker \
		https://github.com/uxsolutions/bootstrap-datepicker

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
