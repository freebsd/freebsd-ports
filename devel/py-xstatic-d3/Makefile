PORTNAME=	xstatic-d3
PORTVERSION=	3.5.17.0
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	XStatic-D3-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	D3 (Data-Driven Documents) (XStatic packaging standard)

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}xstatic>=0:devel/py-xstatic@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
