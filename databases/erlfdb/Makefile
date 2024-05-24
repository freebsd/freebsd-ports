PORTNAME=	erlfdb
PORTVERSION=	1.3.6
DISTVERSIONPREFIX=	v
CATEGORIES=	databases

MAINTAINER=	dch@FreeBSD.org
COMMENT=	FoundationDB client in Erlang via FDB C bindings
WWW=		https://github.com/apache/couchdb-erlfdb

LICENSE=	APACHE20

LIB_DEPENDS=	libfdb_c.so:databases/foundationdb71-client

USES=		erlang:rebar3,enc
USE_GITHUB=	yes
GH_ACCOUNT=	apache
GH_PROJECT=	couchdb-${PORTNAME}

post-install:
	@${FIND} ${STAGEDIR} -type f  -name *.so \
		-exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
