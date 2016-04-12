# Created by: gahr
# $FreeBSD$

PORTNAME=	casstcl
PORTVERSION=	2.11
DISTVERSIONPREFIX=v
CATEGORIES=	databases

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Tcl language interface to the Cassandra database

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libcassandra.so:databases/cassandra-cpp-driver

USES=		autoreconf tcl:85+
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tcl=${TCL_LIBDIR} \
		--exec-prefix=${PREFIX}

USE_GITHUB=	yes
GH_ACCOUNT=	flightaware

USE_LDCONFIG=	yes
PLIST_SUB+=	PORTVERSION=${PORTVERSION}

.include <bsd.port.mk>
