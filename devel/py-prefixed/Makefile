PORTNAME=	prefixed
DISTVERSION=	0.8.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Prefixed alternative numeric library
WWW=		https://github.com/Rockhopper-Technologies/prefixed

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python
USE_PYTHON=	distutils autoplist pytest # 1 test fails, see https://github.com/Rockhopper-Technologies/prefixed/issues/5

NO_ARCH=	yes

.include <bsd.port.mk>
