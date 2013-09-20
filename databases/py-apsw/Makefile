# Created by: Rusty Nejdl
# $FreeBSD$

PORTNAME=	apsw
PORTVERSION=	3.8.0.2
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-${PORTVERSION}-r1

MAINTAINER=	rnejdl@ringofsaturn.com
COMMENT=	APSW stands for Another Python SQLite Wrapper

LIB_DEPENDS=	libsqlite3.so:${PORTSDIR}/databases/sqlite3

PYDISTUTILS_PKGVERSION=	${PORTVERSION}_r1
USE_PYTHON=	yes
USE_PYDISTUTILS=yes
USE_ZIP=	yes

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

NO_STAGE=	yes
.include <bsd.port.mk>
