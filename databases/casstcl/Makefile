# Created by: gahr
# $FreeBSD$

PORTNAME=	casstcl
PORTVERSION=	2.13.0
DISTVERSIONPREFIX=v
PORTREVISION=	0
CATEGORIES=	databases

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Tcl language interface to the Cassandra database

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libcassandra.so:databases/cassandra-cpp-driver

USES=		autoreconf tcl:tea

USE_GITHUB=	yes
GH_ACCOUNT=	flightaware

USE_LDCONFIG=	${PREFIX}/lib/casstcl${PORTVERSION}
PLIST_SUB+=	PORTVERSION=${PORTVERSION:R}

.include <bsd.port.mk>
