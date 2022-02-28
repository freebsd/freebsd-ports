# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	retype
PORTVERSION=	21.12.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Re-apply types from .pyi stub files to your codebase

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=7:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pathspec>=0.5.9<1:devel/py-pathspec@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typed-ast>=1.3:devel/py-typed-ast@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
