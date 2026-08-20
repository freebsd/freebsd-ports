PORTNAME=	pg_textsearch
PORTVERSION=	1.4.0
DISTVERSIONPREFIX=	v
CATEGORIES=	databases

MAINTAINER=	kbowling@FreeBSD.org
COMMENT=	PostgreSQL extension for BM25 full-text search
WWW=		https://github.com/timescale/pg_textsearch

LICENSE=	PostgreSQL

NOT_FOR_ARCHS=		i386
NOT_FOR_ARCHS_REASON=	metapage layout assumes 8-byte alignment of uint64 (offsetof asserts fail)

USES=		gmake pgsql:17-18

WANT_PGSQL=	server
USE_GITHUB=	yes
GH_ACCOUNT=	timescale
GH_PROJECT=	pg_textsearch

PLIST_SUB=	PORTVERSION=${PORTVERSION}

.include <bsd.port.mk>
