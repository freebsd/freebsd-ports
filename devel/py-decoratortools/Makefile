PORTNAME=	decoratortools
PORTVERSION=	1.8
PORTREVISION=	5
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	DecoratorTools-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Class, function, and metaclass decorators
WWW=		https://pypi.org/project/DecoratorTools/

LICENSE=	PSFL ZPL21
LICENSE_COMB=	dual

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python zip
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
