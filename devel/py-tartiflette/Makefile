# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	tartiflette
PORTVERSION=	1.3.3
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	GraphQL Engine for Python

LICENSE=	MIT

LIB_DEPENDS=	libgraphqlparser.so:devel/libgraphqlparser
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>=1.0.0<2.0.0:devel/py-cffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lark-parser>=0.11.1:devel/py-lark-parser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=0,1:devel/py-pytz@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

post-patch:
	@${LN} -s ${LOCALBASE}/lib/libgraphqlparser.so ${WRKSRC}/tartiflette/language/parsers/libgraphqlparser/cffi/libgraphqlparser.so

.include <bsd.port.mk>
