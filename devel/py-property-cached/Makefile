PORTNAME=	property-cached
PORTVERSION=	1.6.4
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Decorator for caching properties in classes
WWW=		https://github.com/althonos/property-cached/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python zip
USE_PYTHON=	distutils autoplist pytest # 1 test fails, see https://github.com/pydanny/cached-property/pull/294

NO_ARCH=	yes

.include <bsd.port.mk>
