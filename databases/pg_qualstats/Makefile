PORTNAME=	pg_qualstats
PORTVERSION=	2.1.2
CATEGORIES=	databases

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	PostgreSQL extension for collecting statistics about predicates
WWW=		https://github.com/dalibo/pg_qualstats

LICENSE=	PostgreSQL

USE_GITHUB=	yes
GH_ACCOUNT=	powa-team

USES=		gmake pgsql:11+
LLD_UNSAFE=	yes
WANT_PGSQL=	server

pre-patch:
	@${MV} ${BUILD_WRKSRC}/doc/README.md ${BUILD_WRKSRC}/doc/${PORTNAME}-README.md

.include <bsd.port.mk>
