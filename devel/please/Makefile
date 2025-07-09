PORTNAME=	please
DISTVERSIONPREFIX=	v
DISTVERSION=	17.18.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://raw.githubusercontent.com/thought-machine/please/${DISTVERSIONFULL}/
DISTFILES=	go.mod
PKGNAMESUFFIX=	.build

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	High-performance extensible build system for reproducible builds
WWW=		https://please.build/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	armv7
NOT_FOR_ARCHS_REASON=	Build crashes

BUILD_DEPENDS=	bash:shells/bash \
		ca_root_nss>0:security/ca_root_nss \
		git:devel/git \
		protoc:devel/protobuf

USES=		go:modules
GO_MODULE=	github.com/thought-machine/please
GO_TARGET=	src/please.go:please \
		tools/build_langserver/langserver_main.go:build_langserver \
		tools/http_cache/main.go:http_cache \
		tools/please_shim/main.go:please_shim \
		tools/release_signer/main.go:release_signer
USE_GITHUB=	yes
GH_ACCOUNT=	thought-machine

post-extract:
	${REINPLACE_CMD} -e 's|99.0.9999|${DISTVERSION}|' ${WRKSRC}/src/version/version.go

post-build:
	cd ${WRKSRC} ; ${SETENV} ${CC} ${CFLAGS} -I${WRKSRC} -o please_sandbox tools/sandbox/main.c tools/sandbox/sandbox.c

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/please_sandbox ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
