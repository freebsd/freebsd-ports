PORTNAME=	xstatic-angular-bootstrap
PORTVERSION=	2.5.0.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	XStatic-Angular-Bootstrap-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Angular-Bootstrap (XStatic packaging standard)
WWW=		https://angular-ui.github.io/bootstrap/

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}xstatic>=0:devel/py-xstatic@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
