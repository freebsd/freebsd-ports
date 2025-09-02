PORTNAME=	types-psycopg2
PORTVERSION=	2.9.21.20250809
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	types_psycopg2-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Typing stubs for psycopg2
WWW=		https://github.com/python/typeshed/tree/main/stubs/psycopg2

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
