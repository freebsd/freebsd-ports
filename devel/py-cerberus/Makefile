PORTNAME=      cerberus
PORTVERSION=	1.3.8
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:tl}-${PORTVERSION}

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Lightweight, extensible validation tool for Python dictionaries
WWW=		https://github.com/pyeve/cerberus

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist concurrent pep517

# Not to be confused with devel/py-pycerberus which fulfils a quite
# different function.

.include <bsd.port.mk>
