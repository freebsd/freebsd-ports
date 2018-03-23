# $FreeBSD$

PORTNAME=	pglite
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.7
CATEGORIES=	databases python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lbartoletti@tuxfamily.org
COMMENT=	Light PostgreSQL: use PostgreSQL as a simple SQLite database

LICENSE=	LGPL20+

USES=		python pgsql
USE_PYTHON=	autoplist distutils
USE_GITHUB=	yes
GH_ACCOUNT=	Oslandia
NO_ARCH=	yes
WANT_PGSQL=	server

.include <bsd.port.mk>
