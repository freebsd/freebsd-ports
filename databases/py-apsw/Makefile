# Created by: Rusty Nejdl
# $FreeBSD$

PORTNAME=	apsw
PORTVERSION=	3.8.0.2
DISTVERSIONSUFFIX=	-r1
PORTREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rnejdl@ringofsaturn.com
COMMENT=	APSW stands for Another Python SQLite Wrapper

LIB_DEPENDS=	libsqlite3.so:${PORTSDIR}/databases/sqlite3

PYDISTUTILS_PKGVERSION=	${PORTVERSION}_r1
USES=		python zip
USE_PYTHON=	distutils

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
