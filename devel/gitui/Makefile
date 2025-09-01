PORTNAME=	gitui
DISTVERSIONPREFIX=	v
DISTVERSION=	0.27.0	# After update, `make patch` and `make cargo-crates > Makefile.crates` to avoid fetching vendored openssl-src
PORTREVISION=	7
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Terminal UI for git
WWW=		https://github.com/gitui-org/gitui

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BROKEN_i386=	link fails: ld: error: undefined symbol: __atomic_is_lock_fre

BUILD_DEPENDS=	bash:shells/bash \
		gmake:devel/gmake
LIB_DEPENDS=	libgit2.so:devel/libgit2 \
		libssh2.so:security/libssh2

USES=		cargo localbase:ldflags perl5 pkgconfig python:build ssl xorg
USE_XORG=	xcb

USE_GITHUB=	yes
GH_ACCOUNT=	gitui-org

RUSTFLAGS+=	--cap-lints=warn
PLIST_FILES=	bin/${PORTNAME}

OPENSSLINC=	/usr/include
OPENSSLLIB=	/usr/lib

BINARY_ALIAS=	python3=${PYTHON_CMD} # xcb requires python3

# Fix build on armv7, i386 and powerpc
# sys-info-0.9.1 crate issue: https://github.com/FillZpp/sys-info-rs/issues/80
xpost-patch:
	@${REINPLACE_CMD} \
	-e '/get_cpu/s|unsigned long|uint64_t|' \
	-e '/get_proc_total/s|unsigned long|uint64_t|' \
	${WRKSRC}/cargo-crates/sys-info-0.9.1/c/*.[ch]

.include <bsd.port.mk>
