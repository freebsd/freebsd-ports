PORTNAME=	iteration-utilities
PORTVERSION=	0.11.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	iteration_utilities-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Utilities based on Pythons iterators and generators
WWW=		https://github.com/MSeifert04/iteration_utilities

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		python
USE_PYTHON=	autoplist concurrent distutils

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
