PORTNAME=	cirrus-cli
DISTVERSIONPREFIX=	v
DISTVERSION=	0.140.4
CATEGORIES=	devel

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Command line interface for Cirrus CI
WWW=		https://github.com/cirruslabs/cirrus-cli

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_RC_SUBR=	${PORTNAME}

GO_MODULE=	github.com/cirruslabs/cirrus-cli
GO_TARGET=	./cmd/cirrus
GO_BUILDFLAGS=	-ldflags="-X github.com/cirruslabs/cirrus-cli/internal/version.Version=${DISTVERSION}"

SUB_FILES=	pkg-message

USERS=		cirrus
GROUPS=		cirrus

post-install:
	${INSTALL_DATA} ${FILESDIR}/cirrus-worker.yml ${STAGEDIR}${PREFIX}/etc/cirrus-worker.yml.sample

.include <bsd.port.mk>
