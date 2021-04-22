# Created by: gahr

PORTNAME=	casstcl
PORTVERSION=	2.15.0
DISTVERSIONPREFIX=v
PORTREVISION=	1
CATEGORIES=	databases

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Tcl language interface to the Cassandra database

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libcassandra.so:databases/cassandra-cpp-driver

USES=		autoreconf tcl:tea

USE_GITHUB=	yes
GH_ACCOUNT=	flightaware

USE_LDCONFIG=	${PREFIX}/lib/casstcl${PORTVERSION:R}
PLIST_SUB+=	PORTVERSION=${PORTVERSION:R}

post-patch:
	@${REINPLACE_CMD} 's|2.14.0|2.15.0|' ${WRKSRC}/configure.in

.include <bsd.port.mk>
