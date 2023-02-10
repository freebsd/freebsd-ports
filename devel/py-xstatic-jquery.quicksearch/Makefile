PORTNAME=	xstatic-jquery.quicksearch
PORTVERSION=	2.0.3.2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	XStatic-JQuery.quicksearch-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	JQuery.quicksearch (XStatic packaging standard)
WWW=		https://plugins.jquery.com/jquery.quicksearch/

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}xstatic>=0:devel/py-xstatic@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
