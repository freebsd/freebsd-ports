PORTNAME=	kyotocabinet
PORTVERSION=	1.23
DISTVERSIONPREFIX=	python-
PORTREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	https://dbmx.net/kyotocabinet/pythonpkg/ \
		LOCAL/sunpoet
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python binding of kyotocabinet
WWW=		https://dbmx.net/kyotocabinet/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libkyotocabinet.so:databases/kyotocabinet

USES=		python
USE_PYTHON=	autoplist concurrent pep517

.include <bsd.port.mk>
