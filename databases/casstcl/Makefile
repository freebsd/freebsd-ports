# Created by: gahr
# $FreeBSD$

PORTNAME=	casstcl
PORTVERSION=	2.11
PORTREVISION=	1
DISTVERSIONPREFIX=v
CATEGORIES=	databases

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Tcl language interface to the Cassandra database

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libcassandra.so:databases/cassandra-cpp-driver

USES=		autoreconf tcl:85+,tea

USE_GITHUB=	yes
GH_ACCOUNT=	flightaware

USE_LDCONFIG=	${PREFIX}/lib/casstcl${PORTVERSION}
PLIST_SUB+=	PORTVERSION=${PORTVERSION}

.include <bsd.port.mk>
