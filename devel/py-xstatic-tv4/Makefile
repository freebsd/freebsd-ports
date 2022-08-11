PORTNAME=	xstatic-tv4
PORTVERSION=	1.2.7.0
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	XStatic-tv4-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	tv4 (XStatic packaging standard)

LICENSE=	MIT PD
LICENSE_COMB=	dual

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}xstatic>=0:devel/py-xstatic@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
