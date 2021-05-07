# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	future-annotations
PORTVERSION=	1.0.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	future_annotations-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Backport of __future__ annotations to python < 3.7

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tokenize-rt>=3:devel/py-tokenize-rt@${PY_FLAVOR}

USES=		python:3.6
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
