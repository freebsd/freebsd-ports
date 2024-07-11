PORTNAME=	methodtools
PORTVERSION=	0.4.7
CATEGORIES=	devel python
#MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Expand standard functools to methods
WWW=		https://pypi.org/project/methodtools/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}wirerope>=0.4.7:devel/py-wirerope@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	youknowone

NO_ARCH=	yes

.include <bsd.port.mk>
