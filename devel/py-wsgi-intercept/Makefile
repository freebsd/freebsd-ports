PORTNAME=	wsgi-intercept
PORTVERSION=	1.12.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	wsgi_intercept-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	WSGI application in place of a real URI for testing
WWW=		https://github.com/cdent/wsgi-intercept

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
