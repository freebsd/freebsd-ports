# $FreeBSD$

PORTNAME=	erlfdb
PORTVERSION=	0.0.0
CATEGORIES=	databases

MAINTAINER=	dch@FreeBSD.org
COMMENT=	FoundationDB client in Erlang

LICENSE=	APACHE20

LIB_DEPENDS=	libfdb_c.so:databases/foundationdb-devel
RUN_DEPENDS=	erlang-runtime21>=0:lang/erlang-runtime21

USES=		erlang:rebar
USE_GITHUB=	yes
GH_ACCOUNT=	cloudant-labs
GH_PROJECT=	couchdb-${PORTNAME}
GH_TAGNAME=	c89b2d6

MAKE_ENV=	PATH=${LOCALBASE}/lib/erlang21/bin:${PATH}

post-install:
	@${FIND} -E ${STAGEDIR} -type f  -name *.so \
		-exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
