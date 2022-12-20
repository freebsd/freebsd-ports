PORTNAME=	intbitset
DISTVERSION=	3.0.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	C-based extension implementing fast integer bit sets
WWW=		https://github.com/inveniosoftware/intbitset/

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python:3.6-3.10
USE_PYTHON=	autoplist cython distutils pytest

TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/intbitset*.so

.include <bsd.port.mk>
