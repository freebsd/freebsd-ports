# Created by: Palle Girgensohn <girgen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	powa-archivist
DISTVERSIONPREFIX=	REL_
DISTVERSION=	3_2_0
PORTREVISION=	1
CATEGORIES=	databases

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	PostgreSQL workload analyzer background worker

LICENSE=	PostgreSQL

RUN_DEPENDS=	${LOCALBASE}/lib/postgresql/pg_stat_kcache.so:databases/pg_stat_kcache \
		${LOCALBASE}/lib/postgresql/pg_qualstats.so:databases/pg_qualstats

USE_GITHUB=	yes
GH_ACCOUNT=	powa-team

USES=		gmake pgsql:9.4+
WANT_PGSQL=	server contrib

pre-patch:
	@for f in ${BUILD_WRKSRC}/*.md; do ${MV} $$f $${f%/*}/powa-$${f##*/}; done

.include <bsd.port.mk>
