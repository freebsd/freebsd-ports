PORTNAME=	gitleaks
DISTVERSIONPREFIX=	v
DISTVERSION=	8.15.2
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Tool for detecting hardcoded secrets in git repositories
WWW=		https://github.com/zricethezav/gitleaks

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/zricethezav/gitleaks/v8
GO_TARGET=	.
PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
