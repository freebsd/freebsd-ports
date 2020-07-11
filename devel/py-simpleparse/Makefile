# Created by: ijliao
# $FreeBSD$

PORTNAME=	simpleparse
PORTVERSION=	2.2.2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	SimpleParse-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python EBNF parser generator (with mx.TextTools derivative)

USES=		python
USE_PYTHON=	autoplist concurrent distutils

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/simpleparse/stt/TextTools/mxTextTools/mxTextTools.so

.include <bsd.port.mk>
