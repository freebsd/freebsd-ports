# $FreeBSD$

PORTNAME=	importlib-metadata
PORTVERSION=	1.7.0
CATEGORIES=	devel
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	importlib_metadata-${PORTVERSION}

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Read metadata from Python packages

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>=0:devel/py-setuptools_scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zipp>=0.5:devel/py-zipp@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
