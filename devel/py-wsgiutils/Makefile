PORTNAME=	wsgiutils
PORTVERSION=	0.7.2
PORTREVISION=	1
CATEGORIES=	devel textproc www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	WSGIUtils-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Utility libraries for development of simple WSGI programs
WWW=		https://github.com/davidfraser/WSGIUtils

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
