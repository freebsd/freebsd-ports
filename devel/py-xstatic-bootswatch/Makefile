PORTNAME=	xstatic-bootswatch
PORTVERSION=	3.3.7.0
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	XStatic-bootswatch-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	bootswatch (themes for Bootstrap) (XStatic packaging standard)

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}xstatic>=0:devel/py-xstatic@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
