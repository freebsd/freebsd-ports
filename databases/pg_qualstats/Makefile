# Created by: Palle Girgensohn <girgen@FreeBSD.org>

PORTNAME=	pg_qualstats
PORTVERSION=	2.0.3
CATEGORIES=	databases

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	PostgreSQL extension for collecting statistics about predicates

LICENSE=	PostgreSQL

USE_GITHUB=	yes
GH_ACCOUNT=	powa-team

USES=		gmake pgsql:9.4+
LLD_UNSAFE=	yes
WANT_PGSQL=	server

pre-patch:
	@${MV} ${BUILD_WRKSRC}/doc/README.md ${BUILD_WRKSRC}/doc/${PORTNAME}-README.md

.include <bsd.port.mk>
