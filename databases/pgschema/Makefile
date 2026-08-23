PORTNAME=	pgschema
DISTVERSIONPREFIX=	v
DISTVERSION=	1.12.4
PORTREVISION=	1
CATEGORIES=	databases

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Terraform-style declarative schema migration workflow for Postgres
WWW=		https://github.com/pgplex/pgschema

LICENSE=	PGSCHEMA
LICENSE_NAME=	pgschema Community License v1.0
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

USES=		go:modules

GO_MODULE=	github.com/pgplex/pgschema

PLIST_FILES=	bin/pgschema

.include <bsd.port.mk>
