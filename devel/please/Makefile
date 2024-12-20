PORTNAME=	please
DISTVERSIONPREFIX=	v
DISTVERSION=	15.17.1
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
		tools/jarcat/main.go:jarcat \
		tools/please_go_filter/please_go_filter.go:please_go_filter \
		tools/please_go_install/please_go_install.go:please_go_install \
		tools/please_go_test/plz_go_test_main.go:please_go_test \
		tools/please_pex/pex_main.go:please_pex \
		tools/release_signer/main.go:release_signer
USE_GITHUB=	yes
GH_ACCOUNT=	thought-machine

post-extract:
	${CP} ${WRKSRC}/tools/please_go_test/plz_go_test.go ${WRKSRC}/tools/please_go_test/plz_go_test_main.go

post-build:
	cd ${WRKSRC} ; ${SETENV} ${CC} ${CFLAGS} -o please_sandbox tools/sandbox/main.c

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/please_sandbox ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
