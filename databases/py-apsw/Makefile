# Created by: Rusty Nejdl
# $FreeBSD$

PORTNAME=	apsw
PORTVERSION=	3.8.0.2
DISTVERSIONSUFFIX=	-r1
PORTREVISION=	2
CATEGORIES=	databases python
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	APSW stands for Another Python SQLite Wrapper

LICENSE=	ZLIB

LIB_DEPENDS=	libsqlite3.so:${PORTSDIR}/databases/sqlite3

PYDISTUTILS_PKGVERSION=	${PORTVERSION}_r1
PYDISTUTILS_EGGINFO=	apsw-${PORTVERSION}.post1-py${PYTHON_VER}.egg-info
USES=		localbase python zip
USE_PYTHON=	distutils

.include <bsd.port.mk>
