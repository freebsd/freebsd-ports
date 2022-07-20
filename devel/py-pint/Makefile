PORTNAME=	pint
PORTVERSION=	0.19.2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Pint-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Physical quantities module

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>=0:devel/py-setuptools_scm@${PY_FLAVOR}

USES=		python:3.8+ shebangfix
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

SHEBANG_FILES=	pint/pint-convert

.include <bsd.port.mk>
