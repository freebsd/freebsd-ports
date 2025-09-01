PORTNAME=	deptry
PORTVERSION=	0.23.0
PORTREVISION=	5
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	deptry-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	CLI utility to check for unused, missing and transitive dependencies
WWW=		https://deptry.com/ \
		https://github.com/fpgmaas/deptry

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}maturin>=1.5<2.0:devel/py-maturin@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=8.0.0<9:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=23.2:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requirements-parser>=0.11.0<1:devel/py-requirements-parser@${PY_FLAVOR} \
		${PY_TOMLI}

USES=		cargo python:3.9+
USE_PYTHON=	autoplist concurrent pep517

CARGO_BUILD=	no
CARGO_INSTALL=	no
WRKSRC=		${WRKDIR}/deptry-${PORTVERSION}

.include <bsd.port.mk>
