# Created by: Rusty Nejdl

PORTNAME=	apsw
PORTVERSION=	3.35.4
DISTVERSIONSUFFIX=	-r1
CATEGORIES=	databases python
MASTER_SITES=	https://github.com/rogerbinns/apsw/releases/download/${PORTVERSION}${DISTVERSIONSUFFIX}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Another Python SQLite Wrapper

LICENSE=	ZLIB

BUILD_DEPENDS=	sqlite3>=${PORTVERSION:R},1:databases/sqlite3

USES=		localbase python:3.6+ sqlite:3 zip
USE_PYTHON=	autoplist concurrent distutils

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/apsw*.so

do-test:
	cd ${WRKSRC}/ && ${PYTHON_CMD} setup.py test

.include <bsd.port.mk>
