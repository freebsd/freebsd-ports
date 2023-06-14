PORTNAME=	kyotocabinet
PORTVERSION=	1.23
DISTVERSIONPREFIX=	python-
CATEGORIES=	databases python
MASTER_SITES=	https://dbmx.net/kyotocabinet/pythonpkg/ \
		LOCAL/sunpoet
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python binding of kyotocabinet
WWW=		https://dbmx.net/kyotocabinet/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libkyotocabinet.so:databases/kyotocabinet

USES=		python
USE_PYTHON=	autoplist concurrent distutils

.include <bsd.port.mk>
