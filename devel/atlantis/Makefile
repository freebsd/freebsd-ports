PORTNAME=	atlantis
DISTVERSIONPREFIX=	v
DISTVERSION=	0.23.5
PORTREVISION=	4
CATEGORIES=	devel

MAINTAINER=	nulldutra@proton.me
COMMENT=	Terraform Pull Requests Automation
WWW=		https://www.runatlantis.io

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	terraform:sysutils/terraform

USES=		go:modules

GO_MODULE=	github.com/runatlantis/atlantis
CGO_ENABLED=	0

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
