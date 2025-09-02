PORTNAME=	types-psutil
PORTVERSION=	7.0.0.20250801
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	types_psutil-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Typing stubs for psutil
WWW=		https://github.com/python/typeshed/tree/main/stubs/psutil

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
