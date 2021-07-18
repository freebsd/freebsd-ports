# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	represent
PORTVERSION=	1.6.0
DISTVERSIONSUFFIX=	.post0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Represent-${DISTVERSIONFULL}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Create __repr__ automatically or declaratively

LICENSE=	BSD3CLAUSE MIT
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=1.8.0:devel/py-six@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ipython>=0:devel/ipython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=3.0.5:devel/py-pytest@${PY_FLAVOR}

USES=		dos2unix python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
