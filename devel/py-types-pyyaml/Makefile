PORTNAME=	types-pyyaml
PORTVERSION=	6.0.12.20241230
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	types_pyyaml-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Typing stubs for PyYAML
WWW=		https://github.com/python/typeshed/tree/main/stubs/pyyaml

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
