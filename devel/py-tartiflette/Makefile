PORTNAME=	tartiflette
PORTVERSION=	1.4.1
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	GraphQL Engine for Python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgraphqlparser.so:devel/libgraphqlparser
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>=1.0.0<2.0.0:devel/py-cffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lark>=0.12.0:devel/py-lark@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

post-patch:
	@${LN} -s ${LOCALBASE}/lib/libgraphqlparser.so ${WRKSRC}/tartiflette/language/parsers/libgraphqlparser/cffi/libgraphqlparser.so

.include <bsd.port.mk>
