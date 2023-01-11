PORTNAME=	xstatic-jsencrypt
PORTVERSION=	2.3.1.1
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	XStatic-JSEncrypt-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	JSEncrypt (XStatic packaging standard)
WWW=		https://travistidwell.com/jsencrypt/

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}xstatic>=0:devel/py-xstatic@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
