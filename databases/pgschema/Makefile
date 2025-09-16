PORTNAME=	pgschema
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.3
CATEGORIES=	databases

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Terraform-style declarative schema migration workflow for Postgres
WWW=		https://github.com/pgschema/pgschema

LICENSE=	PGSCHEMA
LICENSE_NAME=	pgschema Community License v1.0
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

USES=		go:1.24,modules

GO_MODULE=	github.com/pgschema/pgschema

PLIST_FILES=	bin/pgschema

.include <bsd.port.mk>
