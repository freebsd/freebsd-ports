PORTNAME=	gitleaks
DISTVERSIONPREFIX=	v
DISTVERSION=	8.28.0
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Tool for detecting hardcoded secrets in git repositories
WWW=		https://github.com/gitleaks/gitleaks

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	nodefault
GH_TUPLE=	golang:sys:v0.6.0:sys

GO_MODULE=	github.com/zricethezav/gitleaks/v8
GO_TARGET=	.
GO_BUILDFLAGS=	-ldflags="-X github.com/zricethezav/gitleaks/v8/cmd.Version=${DISTVERSION}"

PLIST_FILES=	bin/${PORTNAME}

pre-patch:
	${RM} -r ${WRKSRC}/vendor/golang.org/x/sys
	${LN} -s ${WRKDIR}/sys-* ${WRKSRC}/vendor/golang.org/x/sys

.include <bsd.port.mk>
