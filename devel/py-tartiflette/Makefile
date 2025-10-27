PORTNAME=	tartiflette
PORTVERSION=	1.4.1
PORTREVISION=	3
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	GraphQL Engine for Python
WWW=		https://github.com/tartiflette/tartiflette

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=39.2.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libgraphqlparser.so:devel/libgraphqlparser
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>=1.0.0:devel/py-cffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lark>=0.12.0:devel/py-lark@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

post-patch:
	@${LN} -s ${LOCALBASE}/lib/libgraphqlparser.so ${WRKSRC}/tartiflette/language/parsers/libgraphqlparser/cffi/libgraphqlparser.so

.include <bsd.port.mk>
