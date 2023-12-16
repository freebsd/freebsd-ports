PORTNAME=	cirrus-cli
PORTVERSION=	0.108.1
DISTVERSIONPREFIX=	v
CATEGORIES=	devel
MASTER_SITES=	https://raw.githubusercontent.com/${GH_ACCOUNT}/${GH_PROJECT}/${DISTVERSIONFULL}/:gomod
DISTFILES=	go.mod:gomod

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Command line interface for Cirrus CI
WWW=		https://github.com/cirruslabs/cirrus-cli

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	cirruslabs

USE_RC_SUBR=	${PORTNAME}

GO_MODULE=	github.com/cirruslabs/cirrus-cli
GO_TARGET=	./cmd/cirrus
GO_BUILDFLAGS=	-ldflags="-X github.com/cirruslabs/cirrus-cli/internal/version.Version=${PORTVERSION}"

SUB_FILES=	pkg-message

USERS=		cirrus
GROUPS=		cirrus

post-install:
	${INSTALL_DATA} ${FILESDIR}/cirrus-worker.yml ${STAGEDIR}${PREFIX}/etc/cirrus-worker.yml.sample

.include <bsd.port.mk>
