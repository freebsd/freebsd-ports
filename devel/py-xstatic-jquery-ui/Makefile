PORTNAME=	xstatic-jquery-ui
PORTVERSION=	1.13.0.1
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	XStatic-jquery-ui-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	jquery-ui (XStatic packaging standard)
WWW=		https://jqueryui.com/ \
		https://github.com/xstatic-py/xstatic-jquery_ui

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}xstatic-jquery>=0:devel/py-xstatic-jquery@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
