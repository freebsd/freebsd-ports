PORTNAME=	migrate
DISTVERSIONPREFIX=	v
DISTVERSION=	4.18.3
PORTREVISION=	1
CATEGORIES=	devel
PKGNAMEPREFIX=	go

MAINTAINER=	dutra@FreeBSD.org
COMMENT=	CLI for performing database migrations
WWW=		https://github.com/golang-migrate/migrate

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.23,modules

CONFLICTS_INSTALL=	migrate

GO_MODULE=	github.com/golang-migrate/migrate/v4
GO_TARGET=	./cmd/${PORTNAME}
_DATABASES=	postgres mysql redshift cassandra spanner cockroachdb \
		yugabytedb clickhouse mongodb sqlserver firebird neo4j pgx pgx5 rqlite

_FILES=file go_bindata github github_ee bitbucket aws_s3 google_cloud_storage godoc_vfs gitlab

GO_BUILDFLAGS=	-ldflags="-X main.Version=${DISTVERSION}" -tags "${_DATABASES} ${_FILES}"

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
