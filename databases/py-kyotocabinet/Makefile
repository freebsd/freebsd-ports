# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kyotocabinet
PORTVERSION=	1.22
CATEGORIES=	databases python
MASTER_SITES=	http://fallabs.com/${PORTNAME}/pythonpkg/ \
		LOCAL/sunpoet
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-python-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python binding of kyotocabinet

LICENSE=	GPLv3

LIB_DEPENDS=	libkyotocabinet.so:${PORTSDIR}/databases/kyotocabinet

USE_PYTHON=	autoplist distutils
USES=		python:3

.include <bsd.port.mk>
