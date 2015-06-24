# Created by: gahr
# $FreeBSD$

PORTNAME=	casstcl
PORTVERSION=	2.7
DISTVERSIONPREFIX=v
CATEGORIES=	databases

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Tcl language interface to the Cassandra database

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libcassandra.so:${PORTSDIR}/databases/cassandra-cpp-driver

USES=		autoreconf tcl:85+
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tcl=${TCL_LIBDIR} \
		--exec-prefix=${PREFIX}

USE_GITHUB=	yes
GH_ACCOUNT=	flightaware

USE_LDCONFIG=	yes

PLIST_FILES=	include/casstcl.h \
		lib/casstcl2.4/casstcl.tcl \
		lib/casstcl2.4/libcasstcl.so.1 \
		lib/casstcl2.4/pkgIndex.tcl

.include <bsd.port.mk>
