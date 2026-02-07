PORTNAME=	orderly-set
DISTVERSION=	5.2.3
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Package containing multiple implementations of Ordered Set
WWW=		https://github.com/seperman/orderly-set

LICENSE=	MIT

USES=		python
USE_PYTHON=	distutils autoplist pytest # 3 errors in tests, see https://github.com/seperman/orderly-set/issues/6

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

.include <bsd.port.mk>
