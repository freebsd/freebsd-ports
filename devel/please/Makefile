PORTNAME=	please
DISTVERSIONPREFIX=	v
DISTVERSION=	17.35.2
CATEGORIES=	devel
MASTER_SITES=	https://raw.githubusercontent.com/thought-machine/please/${DISTVERSIONFULL}/
DISTFILES=	go.mod
PKGNAMESUFFIX=	.build

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	High-performance extensible build system for reproducible builds
WWW=		https://please.build/

LICENSE=	Apache-2.0 BSD-2-Clause BSD-3-Clause CC0-1.0 MIT MPL-2.0
LICENSE_COMB=	multi
LICENSE_FILE_Apache-2.0=	${WRKSRC}/LICENSE
LICENSE_FILE_BSD-2-Clause=	${WRKSRC}/vendor/github.com/ulikunitz/xz/LICENSE
LICENSE_FILE_BSD-3-Clause=	${WRKSRC}/vendor/google.golang.org/protobuf/LICENSE
LICENSE_FILE_CC0-1.0=	${WRKSRC}/vendor/github.com/zeebo/blake3/LICENSE
LICENSE_FILE_MIT=	${WRKSRC}/vendor/github.com/klauspost/cpuid/v2/LICENSE
LICENSE_FILE_MPL-2.0=	${WRKSRC}/vendor/github.com/hashicorp/go-retryablehttp/LICENSE

NOT_FOR_ARCHS=	armv7 i386
NOT_FOR_ARCHS_REASON=	Build crashes with integer overflow

BUILD_DEPENDS=	bash:shells/bash \
		ca_root_nss>0:security/ca_root_nss \
		git:devel/git \
		protoc:devel/protobuf

USES=		go:1.27+,modules
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
