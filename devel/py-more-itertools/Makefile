PORTNAME=	more-itertools
PORTVERSION=	11.1.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	more_itertools-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	More routines for operating on iterables, beyond itertools
WWW=		https://more-itertools.readthedocs.io/en/stable/ \
		https://github.com/more-itertools/more-itertools

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.12<4:devel/py-flit-core@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 unittest

NO_ARCH=	yes

.include <bsd.port.mk>
