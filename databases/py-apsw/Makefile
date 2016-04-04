# Created by: Rusty Nejdl
# $FreeBSD$

PORTNAME=	apsw
PORTVERSION=	3.11.1
DISTVERSIONSUFFIX=	-r1
CATEGORIES=	databases python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Another Python SQLite Wrapper

LICENSE=	ZLIB

USE_GITHUB=	yes
GH_ACCOUNT=	rogerbinns

USES=		localbase python sqlite:3
USE_PYTHON=	distutils autoplist
PYDISTUTILS_EGGINFO=	apsw-${PORTVERSION|.post1-py${PYTHON_VER}.egg-info

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/apsw.so

.include <bsd.port.mk>
