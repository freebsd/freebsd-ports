# Created by: Palle Girgensohn <girgen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pg_qualstats
PORTVERSION=	1.0.2
CATEGORIES=	databases

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	PostgreSQL extension for collecting statistics about predicates

LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	dalibo

USES=		gmake pgsql:9.4+
WANT_PGSQL=	server

pre-patch:
	@${MV} ${BUILD_WRKSRC}/doc/README.md ${BUILD_WRKSRC}/doc/${PORTNAME}-README.md ;\
	${MV} ${BUILD_WRKSRC}/LICENSE ${BUILD_WRKSRC}/${PORTNAME}-LICENSE

.include <bsd.port.mk>
