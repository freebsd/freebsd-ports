PORTNAME=	pydeps
DISTVERSION=	1.11.2
CATEGORIES=	devel python
MASTER_SITES=	PYPI

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Display Python module dependencies
WWW=		https://github.com/thebjorn/pydeps

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}stdlib-list>0:devel/py-stdlib-list@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
