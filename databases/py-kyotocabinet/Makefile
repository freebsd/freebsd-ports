# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kyotocabinet
PORTVERSION=	1.23
DISTVERSIONPREFIX=	python-
CATEGORIES=	databases python
MASTER_SITES=	https://dbmx.net/kyotocabinet/pythonpkg/ \
		LOCAL/sunpoet
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python binding of kyotocabinet

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libkyotocabinet.so:databases/kyotocabinet

USES=		python:3.4+
USE_PYTHON=	autoplist concurrent distutils

.include <bsd.port.mk>
