# Created by: Palle Girgensohn <girgen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	powa-archivist
PORTVERSION=	3.1.1.a.20161106
CATEGORIES=	databases

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	PostgreSQL workload analyzer background worker

LICENSE=	PostgreSQL

RUN_DEPENDS=	${LOCALBASE}/lib/postgresql/pg_stat_kcache.so:databases/pg_stat_kcache \
		${LOCALBASE}/lib/postgresql/pg_qualstats.so:databases/pg_qualstats

USE_GITHUB=	yes
GH_ACCOUNT=	dalibo
GH_TAGNAME=	521fdf

USES=		gmake pgsql:9.4+
WANT_PGSQL=	server contrib

pre-patch:
	@for f in ${BUILD_WRKSRC}/*.md; do ${MV} $$f $${f%/*}/powa-$${f##*/}; done

.include <bsd.port.mk>
