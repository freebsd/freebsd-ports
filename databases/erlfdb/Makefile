# $FreeBSD$

PORTNAME=	erlfdb
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.0
CATEGORIES=	databases

MAINTAINER=	dch@FreeBSD.org
COMMENT=	FoundationDB client in Erlang via FDB C bindings

LICENSE=	APACHE20

LIB_DEPENDS=	libfdb_c.so:databases/foundationdb-devel

USES=		erlang:rebar
USE_GITHUB=	yes
GH_ACCOUNT=	apache
GH_PROJECT=	couchdb-${PORTNAME}

post-install:
	@${FIND} -E ${STAGEDIR} -type f  -name *.so \
		-exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
