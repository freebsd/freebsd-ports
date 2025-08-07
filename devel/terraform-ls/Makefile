PORTNAME=	terraform-ls
DISTVERSIONPREFIX=	v
DISTVERSION=	0.36.5
PORTREVISION=	2
CATEGORIES=	devel

MAINTAINER=	dutra@FreeBSD.org
COMMENT=	Terraform language server
WWW=		https://github.com/hashicorp/terraform-ls

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	terraform:sysutils/terraform

USES=		go:1.24,modules

GO_MODULE=	github.com/hashicorp/terraform-ls

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
