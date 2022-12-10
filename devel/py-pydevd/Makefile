PORTNAME=	pydevd
PORTVERSION=	2.9.3
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Debugger used in PyDev and PyCharm
WWW=		https://pypi.org/project/pydevd/

LICENSE=	EPL
LICENSE_FILE=	${WRKSRC}/LICENSE

#USES=		dos2unix python:3.6+
USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils pytest

#DOS2UNIX_GLOB=	*

.include <bsd.port.mk>
