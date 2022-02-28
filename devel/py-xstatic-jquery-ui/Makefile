# Created by: Alexander Nusov <alexander.nusov@nfvexpress.com>

PORTNAME=	xstatic-jquery-ui
PORTVERSION=	1.13.0.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	XStatic-jquery-ui-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	jquery-ui (XStatic packaging standard)

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}xstatic>=0:devel/py-xstatic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xstatic-jquery>=0:devel/py-xstatic-jquery@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
