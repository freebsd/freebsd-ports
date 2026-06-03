PORTNAME=	pg_stat_kcache
DISTVERSIONPREFIX=	REL
DISTVERSION=	2_3_1
CATEGORIES=	databases

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	Gather statistics about PostgreSQL I/O and CPU usage
WWW=		https://github.com/dalibo/pg_stat_kcache

LICENSE=	PostgreSQL

USES=		gmake pgsql:11+
LLD_UNSAFE=	yes
WANT_PGSQL=	server contrib

USE_GITHUB=	yes
GH_ACCOUNT=	powa-team

pre-patch:
	@${MV} ${BUILD_WRKSRC}/README.rst ${BUILD_WRKSRC}/${PORTNAME}-README.rst

.include <bsd.port.mk>
