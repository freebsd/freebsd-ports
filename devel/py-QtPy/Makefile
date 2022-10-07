PORTNAME=	QtPy
DISTVERSION=	2.2.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Abstraction layer on top of the various Qt bindings
WWW=		https://github.com/spyder-ide/qtpy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		python:3.6+
USE_PYTHON=	distutils autoplist pytest # tests fail to run, see https://github.com/spyder-ide/qtpy/issues/370

NO_ARCH=	yes

.include <bsd.port.mk>
