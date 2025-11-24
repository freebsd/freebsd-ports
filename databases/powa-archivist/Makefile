PORTNAME=	powa-archivist
DISTVERSIONPREFIX=	REL_
DISTVERSION=	5_1_0
CATEGORIES=	databases

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	PostgreSQL workload analyzer background worker
WWW=		https://powa.readthedocs.io/en/stable/components/powa-archivist/

LICENSE=	PostgreSQL

RUN_DEPENDS=	${LOCALBASE}/lib/postgresql/pg_stat_kcache.so:databases/pg_stat_kcache \
		${LOCALBASE}/lib/postgresql/pg_qualstats.so:databases/pg_qualstats

USE_GITHUB=	yes
GH_ACCOUNT=	powa-team

USES=		gmake pgsql:11+
WANT_PGSQL=	server contrib

pre-patch:
	@for f in ${BUILD_WRKSRC}/*.md; do ${MV} $$f $${f%/*}/powa-$${f##*/}; done

.include <bsd.port.mk>
