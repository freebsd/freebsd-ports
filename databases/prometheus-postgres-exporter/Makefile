PORTNAME=	prometheus-postgres-exporter
DISTVERSIONPREFIX=	v
DISTVERSION=	0.17.1
PORTREVISION=	3
CATEGORIES=	databases

MAINTAINER=	ivy@FreeBSD.org
COMMENT=	PostgreSQL metric exporter for Prometheus
WWW=		https://github.com/prometheus-community/postgres_exporter

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_RC_SUBR=	postgres_exporter
GO_MODULE=	github.com/prometheus-community/postgres_exporter
GO_TARGET=	./cmd/postgres_exporter:${PREFIX}/bin/postgres_exporter

SUB_FILES=	pkg-message

PLIST_FILES=	bin/postgres_exporter \
		etc/postgres_exporter.yml.sample

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc
	${INSTALL_DATA} ${PATCHDIR}/postgres_exporter.yml.sample \
		${STAGEDIR}${PREFIX}/etc/postgres_exporter.yml.sample

.include <bsd.port.mk>
