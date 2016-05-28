# Created by: Palle Girgensohn <girgen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pg_stat_kcache
PORTVERSION=	2.0.2
CATEGORIES=	databases

USE_GITHUB=	yes
GH_ACCOUNT=	dalibo
GH_TAGNAME=	REL2_0_2

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	Gather statistics about PostgreSQL I/O and CPU usage 

USES=		gmake pgsql:9.4+
WANT_PGSQL=	server contrib

pre-patch:
	@${MV} ${BUILD_WRKSRC}/README.rst ${BUILD_WRKSRC}/${PORTNAME}-README.rst

.include <bsd.port.mk>
