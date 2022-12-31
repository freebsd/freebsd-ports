PORTNAME=	pydevd
PORTVERSION=	2.9.5
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Debugger used in PyDev and PyCharm
WWW=		https://pypi.org/project/pydevd/

LICENSE=	APACHE20 EPL
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_EPL=	${WRKSRC}/LICENSE-EPL

#USES=		dos2unix python:3.6+
USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils pytest

#DOS2UNIX_GLOB=	*

.include <bsd.port.mk>
